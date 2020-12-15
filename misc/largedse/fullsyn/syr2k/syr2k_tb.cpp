#include "syr2k_tb.h"
#include "syr2k.h"

#include <cstdlib>

void init(data_t C[N * N], data_t A[N * M], data_t B[N * M]) {
	for(unsigned i = 0; i < N; i++) {
		for(unsigned j = 0; j < M; j++) {
			A[i * M + j] = (data_t) ((i * j + 1) % N) / N;
			B[i * M + j] = (data_t) ((i * j + 2) % M) / M;
		}
	}
	for(unsigned i = 0; i < N; i++) {
		for(unsigned j = 0; j < N; j++)
			C[i * N + j] = (data_t) ((i * j + 3) % N) / M;
	}
}

int main(void) {
	data_t *C = (data_t *) malloc(sizeof(data_t) * N * N);
	data_t *A = (data_t *) malloc(sizeof(data_t) * N * M);
	data_t *B = (data_t *) malloc(sizeof(data_t) * N * M);

	init(C, A, B);
	syr2k(C, A, B);

_err:

	if(B) free(B);
	if(A) free(A);
	if(C) free(C);

	return 0;
}
