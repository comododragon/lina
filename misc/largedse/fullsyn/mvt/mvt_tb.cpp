#include "mvt_tb.h"
#include "mvt.h"

#include <cstdlib>

void init(data_t x1[N], data_t x2[N], data_t y_1[N], data_t y_2[N], data_t A[N * N]) {
	for(unsigned i = 0; i < N; i++) {
		x1[i] = (data_t) (i % N) / N;
		x2[i] = (data_t) ((i + 1) % N) / N;
		y_1[i] = (data_t) ((i + 3) % N) / N;
		y_2[i] = (data_t) ((i + 4) % N) / N;

		for(unsigned j = 0; j < N; j++)
			A[i * N + j] = (data_t) (i * j % N) / N;
	}
}

int main(void) {
	data_t *x1 = (data_t *) malloc(sizeof(data_t) * N);
	data_t *x2 = (data_t *) malloc(sizeof(data_t) * N);
	data_t *y_1 = (data_t *) malloc(sizeof(data_t) * N);
	data_t *y_2 = (data_t *) malloc(sizeof(data_t) * N);
	data_t *A = (data_t *) malloc(sizeof(data_t) * N * N);

	init(x1, x2, y_1, y_2, A);
	mvt(x1, x2, y_1, y_2, A);

_err:

	if(x1) free(x1);
	if(x2) free(x2);
	if(y_1) free(y_1);
	if(y_2) free(y_2);
	if(A) free(A);

	return 0;
}
