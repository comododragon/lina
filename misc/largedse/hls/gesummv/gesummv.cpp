#include "gesummv.h"

void gesummv(data_t A[N * N], data_t B[N * N], data_t tmp[N], data_t x[N], data_t y[N]) {
	for(unsigned i = 0; i < N; i++) {
		for(unsigned j = 0; j < N; j++) {
			tmp[i] = A[i * N + j] * x[j] + tmp[i];
			y[i] = B[i * N + j] * x[j] + y[i];
		}

		y[i] = ALPHA * tmp[i] + BETA * y[i];
	}
}
