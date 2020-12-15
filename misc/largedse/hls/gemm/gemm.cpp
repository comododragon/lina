#include "gemm.h"

void gemm(data_t C[NI * NJ], data_t A[NI * NK], data_t B[NK * NJ]) {
	for(unsigned i = 0; i < NI; i++) {
		for(unsigned j = 0; j < NJ; j++) {
			C[i * NJ + j] *= BETA;

			for(unsigned k = 0; k < NK; k++) {
				C[i * NJ + j] += ALPHA * A[i * NK + k] * B[k * NJ + j];
			}
		}
	}
}
