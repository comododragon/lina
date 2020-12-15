#include "syrk.h"

void syrk(data_t C[N * N], data_t A[N * M]) {
	for(unsigned i = 0; i < N; i++) {
		for(unsigned j = 0; j < N; j++) {
			C[i * N + j] *= BETA;

			for(unsigned k = 0; k < M; k++) {
				C[i * N + j] += ALPHA * A[i * M + k] * A[j * M + k];
			}
		}
	}
}
