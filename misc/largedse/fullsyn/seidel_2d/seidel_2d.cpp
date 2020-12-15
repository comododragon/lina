#include "seidel_2d.h"

void seidel_2d(data_t A[N * N]) {
	data_t lA[N * N];

	for(unsigned i = 0; i < N * N; i++)
		lA[i] = A[i];

	/* -------------------------------------------------------------------------------------- */

	for(unsigned t = 0; t < TSTEPS; t++) {
		for(unsigned i = 1; i < N - 1; i++) {
			for(unsigned j = 1; j < N - 1; j++) {
				lA[i * N + j] = (lA[(i - 1) * N + j - 1] + lA[(i - 1) * N + j] + lA[(i - 1) * N + j + 1] + lA[i * N + j - 1] + lA[i * N + j] + lA[i * N + j + 1] + lA[(i + 1) * N + j - 1] + lA[(i + 1) * N + j] + lA[(i + 1) * N + j + 1]) / 9.0f;
			}
		}
	}

	/* -------------------------------------------------------------------------------------- */

	for(unsigned i = 0; i < N * N; i++)
		A[i] = lA[i];
}
