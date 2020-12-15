#include "syrk_tb.h"
#include "syrk.h"

#include <cstdlib>

void init(data_t C[N * N], data_t A[N * M]) {
	for(unsigned i = 0; i < N; i++) {
		for(unsigned j = 0; j < M; j++)
			A[i * M + j] = (data_t) ((i * j + 1) % N) / N;
	}
	for(unsigned i = 0; i < N; i++) {
		for(unsigned j = 0; j < N; j++)
			C[i * N + j] = (data_t) ((i * j + 2) % M) / M;
	}
}

int main(void) {
	data_t *C = (data_t *) malloc(sizeof(data_t) * N * N);
	data_t *A = (data_t *) malloc(sizeof(data_t) * N * M);

	init(C, A);
	syrk(C, A);

_err:

	if(A) free(A);
	if(C) free(C);

	return 0;
}
