#include "heat_3d.h"

void heat_3d(data_t A[N * N * N], data_t B[N * N * N]) {
	data_t lA[N * N * N];
	data_t lB[N * N * N];

	for(unsigned i = 0; i < N * N * N; i++)
		lA[i] = A[i];

	/* -------------------------------------------------------------------------------------- */

	for(unsigned i = 1; i < N - 1; i++) {
		for(unsigned j = 1; j < N - 1; j++) {
			for(unsigned k = 1; k < N - 1; k++) {
				// i * N * N + j * N + k
				unsigned ijk = N * ((N * i) + j) + k;

				lB[ijk] = 0.125f * (lA[ijk + (N * N)] - 2.0f * lA[ijk] + lA[ijk - (N * N)]) +
						0.125f * (lA[ijk + N] - 2.0f * lA[ijk] + lA[ijk - N]) +
						0.125f * (lA[ijk + 1] - 2.0f * lA[ijk] + lA[ijk - 1]) +
						lA[ijk];
			}
		}
	}

	/* -------------------------------------------------------------------------------------- */

	for(unsigned i = 0; i < N * N * N; i++)
		B[i] = lB[i];
}
