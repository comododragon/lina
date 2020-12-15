#include "jacobi_2d.h"

void jacobi_2d(data_t A[N * N], data_t B[N * N]) {
	data_t lA[N * N];
	data_t lB[N * N];

	for(unsigned i = 0; i < N * N; i++)
		lA[i] = A[i];

	/* -------------------------------------------------------------------------------------- */

	for(unsigned i = 1; i < N - 1; i++) {
		for(unsigned j = 1; j < N - 1; j++) {
			lB[i * N + j] = 0.2f * (lA[i * N + j] + lA[i * N + j - 1] + lA[i * N + j + 1] + lA[(i + 1) * N + j] + lA[(i - 1) * N + j]);
		}
	}

	/* -------------------------------------------------------------------------------------- */

	for(unsigned i = 0; i < N * N; i++)
		B[i] = lB[i];
}
