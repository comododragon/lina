#include "gemm.h"

void gemm(data_t C[NI * NJ], data_t A[NI * NK], data_t B[NK * NJ]) {
	data_t lC[NI * NJ];
	data_t lA[NI * NK];
	data_t lB[NK * NJ];

	for(unsigned i = 0; i < NI * NJ; i++)
		lC[i] = C[i];
	for(unsigned i = 0; i < NI * NK; i++)
		lA[i] = A[i];
	for(unsigned i = 0; i < NK * NJ; i++)
		lB[i] = B[i];

	/* -------------------------------------------------------------------------------------- */

	for(unsigned i = 0; i < NI; i++) {
		for(unsigned j = 0; j < NJ; j++) {
			lC[i * NJ + j] *= BETA;

			for(unsigned k = 0; k < NK; k++) {
				lC[i * NJ + j] += ALPHA * lA[i * NK + k] * lB[k * NJ + j];
			}
		}
	}

	/* -------------------------------------------------------------------------------------- */

	for(unsigned i = 0; i < NI * NJ; i++)
		C[i] = lC[i];
}
