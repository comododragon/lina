#include "jacobi_1d.h"

void jacobi_1d(data_t A[N], data_t B[N]) {
	data_t lA[N];
	data_t lB[N];

	for(unsigned i = 0; i < N; i++)
		lA[i] = A[i];

	/* -------------------------------------------------------------------------------------- */

	for(unsigned i = 1; i < N - 1; i++) {
		lB[i] = 0.33333f * (lA[i - 1] + lA[i] + lA[i + 1]);
	}

	/* -------------------------------------------------------------------------------------- */

	for(unsigned i = 0; i < N; i++)
		B[i] = lB[i];
}
