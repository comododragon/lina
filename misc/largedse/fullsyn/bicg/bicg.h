#ifndef BICG_H
#define BICG_H

#define data_t float

#define DATASET_M

#ifdef DATASET_S
#define M 116
#define N 124
#endif
#ifdef DATASET_M
#define M 390
#define N 410
#endif
#ifdef DATASET_L
#define M 1900
#define N 2100
#endif

void bicg(data_t A[N * M], data_t s[M], data_t q[N], data_t p[M], data_t r[N]);

#endif
