#include "syr2k.h"

void syr2k(data_t C[N * N], data_t A[N * M], data_t B[N * M]) {
	for(unsigned i = 0; i < N; i++) {
		for(unsigned j = 0; j < N; j++) {
			C[i * N + j] *= BETA;

			for(unsigned k = 0; k < M; k++) {
				C[i * N + j] += A[j * M + k] * ALPHA * B[i * M + k] + B[j * M + k] * ALPHA * A[i * M + k];
			}
		}
	}
}
