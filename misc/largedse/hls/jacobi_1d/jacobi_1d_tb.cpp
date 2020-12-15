#include "jacobi_1d_tb.h"
#include "jacobi_1d.h"

#include <cstdlib>

void init(data_t A[N], data_t B[N]) {
	for(unsigned i = 0; i < N; i++)
		A[i] = ((data_t) i + 2) / N;
}

int main(void) {
	data_t *A = (data_t *) malloc(sizeof(data_t) * N);
	data_t *B = (data_t *) malloc(sizeof(data_t) * N);

	init(A, B);
	jacobi_1d(A, B);

_err:

	if(B) free(B);
	if(A) free(A);

	return 0;
}
