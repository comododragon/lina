#include "gesummv.h"

void gesummv(data_t A[N * N], data_t B[N * N], data_t tmp[N], data_t x[N], data_t y[N]) {
	data_t lA[N * N];
	data_t lB[N * N];
	data_t ltmp[N];
	data_t lx[N];
	data_t ly[N];

	for(unsigned i = 0; i < N * N; i++)
		lA[i] = A[i];
	for(unsigned i = 0; i < N * N; i++)
		lB[i] = B[i];
	for(unsigned i = 0; i < N; i++)
		ltmp[i] = tmp[i];
	for(unsigned i = 0; i < N; i++)
		lx[i] = x[i];
	for(unsigned i = 0; i < N; i++)
		ly[i] = y[i];

	/* -------------------------------------------------------------------------------------- */

	for(unsigned i = 0; i < N; i++) {
		for(unsigned j = 0; j < N; j++) {
			ltmp[i] = lA[i * N + j] * lx[j] + ltmp[i];
			ly[i] = lB[i * N + j] * lx[j] + ly[i];
		}

		ly[i] = ALPHA * ltmp[i] + BETA * ly[i];
	}

	/* -------------------------------------------------------------------------------------- */

	for(unsigned i = 0; i < N; i++)
		tmp[i] = ltmp[i];
	for(unsigned i = 0; i < N; i++)
		y[i] = ly[i];
}
