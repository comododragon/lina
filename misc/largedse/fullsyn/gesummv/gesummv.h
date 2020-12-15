#ifndef GESUMMV_H
#define GESUMMV_H

#define data_t float
#define ALPHA 1.5f
#define BETA 1.2f

#define DATASET_M

#ifdef DATASET_S
#define N 90
#endif
#ifdef DATASET_M
#define N 250
#endif
#ifdef DATASET_L
#define N 1300
#endif

void gesummv(data_t A[N * N], data_t B[N * N], data_t tmp[N], data_t x[N], data_t y[N]);

#endif
