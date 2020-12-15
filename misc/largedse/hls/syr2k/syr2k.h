#ifndef SYR2K_H
#define SYR2K_H

#define data_t float
#define ALPHA 1.5f
#define BETA 1.2f

#define DATASET_S

#ifdef DATASET_S
#define M 60
#define N 80
#endif
#ifdef DATASET_M
#define M 200
#define N 240
#endif
#ifdef DATASET_L
#define M 1000
#define N 1200
#endif

void syr2k(data_t C[N * N], data_t A[N * M], data_t B[N * M]);

#endif
