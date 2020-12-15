#include "mvt.h"

void mvt(data_t x1[N], data_t x2[N], data_t y_1[N], data_t y_2[N], data_t A[N * N]) {
	for(unsigned i = 0; i < N; i++) {
		for(unsigned j = 0; j < N; j++) {
			x1[i] += A[i * N + j] * y_1[j];
			x2[i] += A[j * N + i] * y_2[j];
		}
	}
}
