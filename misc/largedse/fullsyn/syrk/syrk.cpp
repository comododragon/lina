#include "syrk.h"

void syrk(data_t C[N * N], data_t A[N * M]) {
	data_t lC[N * N];
	data_t lA[N * M];

	for(unsigned i = 0; i < N * N; i++)
		lC[i] = C[i];

	for(unsigned i = 0; i < N * M; i++)
		lA[i] = A[i];

	/* -------------------------------------------------------------------------------------- */

	for(unsigned i = 0; i < N; i++) {
		for(unsigned j = 0; j < N; j++) {
			lC[i * N + j] *= BETA;

			for(unsigned k = 0; k < M; k++) {
				lC[i * N + j] += ALPHA * lA[i * M + k] * lA[j * M + k];
			}
		}
	}

	/* -------------------------------------------------------------------------------------- */

	for(unsigned i = 0; i < N * N; i++)
		C[i] = lC[i];
}
