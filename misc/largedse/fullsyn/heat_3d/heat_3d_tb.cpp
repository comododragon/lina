#include "heat_3d_tb.h"
#include "heat_3d.h"

#include <cstdlib>

void init(data_t A[N * N * N], data_t B[N * N * N]) {
	for(unsigned i = 0; i < N; i++) {
		for(unsigned j = 0; j < N; j++) {
			for(unsigned k = 0; k < N; k++)
				A[N * ((N * i) + j) + k] = (data_t) (i + j + (N - k)) * 10 / N;
		}
	}
}

int main(void) {
	data_t *A = (data_t *) malloc(sizeof(data_t) * N * N * N);
	data_t *B = (data_t *) malloc(sizeof(data_t) * N * N * N);

	init(A, B);
	heat_3d(A, B);

_err:

	if(B) free(B);
	if(A) free(A);

	return 0;
}
