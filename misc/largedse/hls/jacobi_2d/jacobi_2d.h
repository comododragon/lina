#ifndef JACOBI_2D_H
#define JACOBI_2D_H

#define data_t float

#define DATASET_M

#ifdef DATASET_XS
#define N 30
#endif
#ifdef DATASET_S
#define N 90
#endif
#ifdef DATASET_M
#define N 302
#endif
#ifdef DATASET_L
#define N 1300
#endif
#ifdef DATASET_XL
#define N 2800
#endif

void jacobi_2d(data_t A[N * N], data_t B[N * N]);

#endif
