#include "gesummv_tb.h"
#include "gesummv.h"

#include <cstdlib>

void init(data_t A[N * N], data_t B[N * N], data_t tmp[N], data_t x[N], data_t y[N]) {
	for(unsigned i = 0; i < N; i++) {
		tmp[i] = 0.0;
		x[i] = (data_t) (i % N) / N;
		y[i] = 0.0;

		for(unsigned j = 0; j < N; j++) {
			A[i * N + j] = (data_t) ((i * j + 1) % N) / N;
			B[i * N + j] = (data_t) ((i * j + 2) % N) / N;
		}
	}
}

int main(void) {
	data_t *A = (data_t *) malloc(sizeof(data_t) * N * N);
	data_t *B = (data_t *) malloc(sizeof(data_t) * N * N);
	data_t *tmp = (data_t *) malloc(sizeof(data_t) * N);
	data_t *x = (data_t *) malloc(sizeof(data_t) * N);
	data_t *y = (data_t *) malloc(sizeof(data_t) * N);

	init(A, B, tmp, x, y);
	gesummv(A, B, tmp, x, y);

_err:

	if(y) free(y);
	if(x) free(x);
	if(tmp) free(tmp);
	if(B) free(B);
	if(A) free(A);

	return 0;
}
