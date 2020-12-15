#include "gemm_tb.h"
#include "gemm.h"

#include <cstdlib>

void init(data_t C[NI * NJ], data_t A[NI * NK], data_t B[NK * NJ]) {
	for(unsigned i = 0; i < NI; i++) {
		for(unsigned j = 0; j < NJ; j++)
			C[i * NJ + j] = (data_t) ((i * j + 1) % NI) / NI;
	}

	for(unsigned i = 0; i < NI; i++) {
		for(unsigned k = 0; k < NK; k++)
			A[i * NK + k] = (data_t) (i * (k + 1) % NK) / NK;
	}

	for(unsigned k = 0; k < NK; k++) {
		for(unsigned j = 0; j < NJ; j++)
			B[k * NJ + j] = (data_t) (k * (j + 2) % NJ) / NJ;
	}
}

int main(void) {
	data_t *C = (data_t *) malloc(sizeof(data_t) * NI * NJ);
	data_t *A = (data_t *) malloc(sizeof(data_t) * NI * NK);
	data_t *B = (data_t *) malloc(sizeof(data_t) * NK * NJ);

	init(C, A, B);
	gemm(C, A, B);

_err:

	if(B) free(B);
	if(A) free(A);
	if(C) free(C);

	return 0;
}
