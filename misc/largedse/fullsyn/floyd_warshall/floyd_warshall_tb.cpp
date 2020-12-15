#include "floyd_warshall_tb.h"
#include "floyd_warshall.h"

#include <cstdlib>

void init(data_t path[N * N]) {
	for(unsigned i = 0; i < N; i++) {
		for(unsigned j = 0; j < N; j++) {
			path[i * N + j] = i * j % 7 + 1;
			if((i + j) % 13 == 0 || (i + j) % 7 == 0 || (i + j) % 11 == 0)
				path[i * N + j] = 999;
		}
	}
}

int main(void) {
	data_t *path = (data_t *) malloc(sizeof(data_t) * N * N);

	init(path);
	floyd_warshall(path);

_err:

	if(path) free(path);

	return 0;
}
