#include "floyd_warshall.h"

void floyd_warshall(data_t path[N * N]) {
	data_t lpath[N * N];

	for(unsigned i = 0; i < N * N; i++)
		lpath[i] = path[i];

	/* -------------------------------------------------------------------------------------- */

	for(unsigned k = 0; k < N; k++) {
		for(unsigned i = 0; i < N; i++) {
			for(unsigned j = 0; j < N; j++) {
				data_t cand = lpath[i * N + k] + lpath[k * N + j];
				if(lpath[i * N + j] >= cand)
					lpath[i * N + j] = cand;
			}
		}
	}

	/* -------------------------------------------------------------------------------------- */

	for(unsigned i = 0; i < N * N; i++)
		path[i] = lpath[i];
}
