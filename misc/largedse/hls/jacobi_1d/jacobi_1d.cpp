#include "jacobi_1d.h"

void jacobi_1d(data_t A[N], data_t B[N]) {
	for(unsigned i = 1; i < N - 1; i++) {
		B[i] = 0.33333f * (A[i - 1] + A[i] + A[i + 1]);
	}
}
