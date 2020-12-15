#include "bicg.h"

void bicg(data_t A[N * M], data_t s[M], data_t q[N], data_t p[M], data_t r[N]) {
	data_t lA[N * M], ls[M], lq[N], lp[M], lr[N];

	for(unsigned i = 0; i < N * M; i++)
		lA[i] = A[i];
	for(unsigned i = 0; i < M; i++)
		ls[i] = s[i];
	for(unsigned i = 0; i < N; i++)
		lq[i] = q[i];
	for(unsigned i = 0; i < M; i++)
		lp[i] = p[i];
	for(unsigned i = 0; i < N; i++)
		lr[i] = r[i];

	/* -------------------------------------------------------------------------------------- */

	for(unsigned i = 0; i < N; i++) {
		for(unsigned j = 0; j < M; j++) {
			ls[j] += lr[i] * lA[i * M + j];
			lq[i] += lA[i * M + j] * lp[j];
		}
	}

	/* -------------------------------------------------------------------------------------- */

	for(unsigned i = 0; i < M; i++)
		s[i] = ls[i];
	for(unsigned i = 0; i < N; i++)
		q[i] = lq[i];
}
