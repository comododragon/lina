#include "heat_3d.h"

void heat_3d(data_t A[N * N * N], data_t B[N * N * N]) {
	for(unsigned i = 1; i < N - 1; i++) {
		for(unsigned j = 1; j < N - 1; j++) {
			for(unsigned k = 1; k < N - 1; k++) {
				// i * N * N + j * N + k
				unsigned ijk = N * ((N * i) + j) + k;

				B[ijk] = 0.125f * (A[ijk + (N * N)] - 2.0f * A[ijk] + A[ijk - (N * N)]) +
						0.125f * (A[ijk + N] - 2.0f * A[ijk] + A[ijk - N]) +
						0.125f * (A[ijk + 1] - 2.0f * A[ijk] + A[ijk - 1]) +
						A[ijk];
			}
		}
	}
}
