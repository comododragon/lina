#include "mvt.h"

void mvt(data_t x1[N], data_t x2[N], data_t y_1[N], data_t y_2[N], data_t A[N * N]) {
	data_t lx1[N];
	data_t lx2[N];
	data_t ly_1[N];
	data_t ly_2[N];
	data_t lA[N * N];

	for(unsigned i = 0; i < N; i++)
		lx1[i] = x1[i];

	for(unsigned i = 0; i < N; i++)
		lx2[i] = x2[i];

	for(unsigned i = 0; i < N; i++)
		ly_1[i] = y_1[i];

	for(unsigned i = 0; i < N; i++)
		ly_2[i] = y_2[i];

	for(unsigned i = 0; i < N * N; i++)
		lA[i] = A[i];

	/* -------------------------------------------------------------------------------------- */

	for(unsigned i = 0; i < N; i++) {
		for(unsigned j = 0; j < N; j++) {
			lx1[i] += lA[i * N + j] * ly_1[j];
			lx2[i] += lA[j * N + i] * ly_2[j];
		}
	}

	/* -------------------------------------------------------------------------------------- */

	for(unsigned i = 0; i < N; i++)
		x1[i] = lx1[i];

	for(unsigned i = 0; i < N; i++)
		x2[i] = lx2[i];
}
