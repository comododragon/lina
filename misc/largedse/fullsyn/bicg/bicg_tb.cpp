#include "bicg_tb.h"
#include "bicg.h"

#include <cstdlib>

void init(data_t A[N * M], data_t s[M], data_t q[N], data_t p[M], data_t r[N]) {
	for(unsigned i = 0; i < M; i++)
		p[i] = (data_t) (i % M) / M;
	for(unsigned i = 0; i < N; i++) {
		r[i] = (data_t) (i % N) / N;
		for(unsigned j = 0; j < M; j++)
			A[i * M + j] = (data_t) (i * (j + 1) % N) / M;
	}
	for(unsigned i = 0; i < M; i++)
		s[i] = 0.0;
	for(unsigned i = 0; i < N; i++)
		q[i] = 0.0;
}

int main(void) {
	data_t *A = (data_t *) malloc(sizeof(data_t) * N * M);
	data_t *s = (data_t *) malloc(sizeof(data_t) * M);
	data_t *q = (data_t *) malloc(sizeof(data_t) * N);
	data_t *p = (data_t *) malloc(sizeof(data_t) * M);
	data_t *r = (data_t *) malloc(sizeof(data_t) * N);

	init(A, s, q, p, r);
	bicg(A, s, q, p, r);

_err:

	if(r) free(r);
	if(p) free(p);
	if(q) free(q);
	if(s) free(s);
	if(A) free(A);

	return 0;
}
