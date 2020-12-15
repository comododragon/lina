#include "seidel_2d.h"

void seidel_2d(data_t A[N * N]) {
	for(unsigned t = 0; t < TSTEPS; t++) {
		for(unsigned i = 1; i < N - 1; i++) {
			for(unsigned j = 1; j < N - 1; j++) {
				A[i * N + j] = (A[(i - 1) * N + j - 1] + A[(i - 1) * N + j] + A[(i - 1) * N + j + 1] + A[i * N + j - 1] + A[i * N + j] + A[i * N + j + 1] + A[(i + 1) * N + j - 1] + A[(i + 1) * N + j] + A[(i + 1) * N + j + 1]) / 9.0f;
			}
		}
	}
}
