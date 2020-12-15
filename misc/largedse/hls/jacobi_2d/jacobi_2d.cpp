#include "jacobi_2d.h"

void jacobi_2d(data_t A[N * N], data_t B[N * N]) {
	for(unsigned i = 1; i < N - 1; i++) {
		for(unsigned j = 1; j < N - 1; j++) {
			B[i * N + j] = 0.2f * (A[i * N + j] + A[i * N + j - 1] + A[i * N + j + 1] + A[(i + 1) * N + j] + A[(i - 1) * N + j]);
		}
	}
}
