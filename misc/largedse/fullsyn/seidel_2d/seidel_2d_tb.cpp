#include "seidel_2d_tb.h"
#include "seidel_2d.h"

#include <cstdlib>

void init(data_t A[N * N]) {
	for(unsigned i = 0; i < N; i++) {
		for(unsigned j = 0; j < N; j++)
			A[i * N + j] = ((data_t) i * (j + 2) + 2) / N;
	}
}

int main(void) {
	data_t *A = (data_t *) malloc(sizeof(data_t) * N * N);

	init(A);
	seidel_2d(A);

_err:

	if(A) free(A);

	return 0;
}
