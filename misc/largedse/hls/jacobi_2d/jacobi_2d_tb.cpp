#include "jacobi_2d_tb.h"
#include "jacobi_2d.h"

#include <cstdlib>

void init(data_t A[N * N], data_t B[N * N]) {
	for(unsigned i = 0; i < N; i++) {
		for(unsigned j = 0; j < N; j++) {
			A[i * N + j] = ((data_t) i * (j + 2) + 2) / N;
			B[i * N + j] = ((data_t) i * (j + 3) + 3) / N;
		}
	}
}

int main(void) {
	data_t *A = (data_t *) malloc(sizeof(data_t) * N * N);
	data_t *B = (data_t *) malloc(sizeof(data_t) * N * N);

	init(A, B);
	jacobi_2d(A, B);

_err:

	if(B) free(B);
	if(A) free(A);

	return 0;
}
