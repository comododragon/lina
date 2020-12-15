#include "floyd_warshall.h"

void floyd_warshall(data_t path[N * N]) {
	for(unsigned k = 0; k < N; k++) {
		for(unsigned i = 0; i < N; i++) {
			for(unsigned j = 0; j < N; j++) {
				data_t cand = path[i * N + k] + path[k * N + j];
				if(path[i * N + j] >= cand)
					path[i * N + j] = cand;
			}
		}
	}
}
