#include "bicg.h"

void bicg(data_t A[N * M], data_t s[M], data_t q[N], data_t p[M], data_t r[N]) {
	for(unsigned i = 0; i < N; i++) {
		for(unsigned j = 0; j < M; j++) {
			s[j] += r[i] * A[i * M + j];
			q[i] += A[i * M + j] * p[j];
		}
	}
}
