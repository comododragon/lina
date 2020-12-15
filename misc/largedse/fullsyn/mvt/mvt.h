#ifndef MVT_H
#define MVT_H

#define data_t float

#define DATASET_M

#ifdef DATASET_S
#define N 120
#endif
#ifdef DATASET_M
#define N 400
#endif
#ifdef DATASET_L
#define N 2000
#endif

void mvt(data_t x1[N], data_t x2[N], data_t y_1[N], data_t y_2[N], data_t A[N * N]);

#endif
