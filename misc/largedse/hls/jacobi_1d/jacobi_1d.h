#ifndef JACOBI_1D_H
#define JACOBI_1D_H

#define data_t float

#define DATASET_XL

#ifdef DATASET_XS
#define N 30
#endif
#ifdef DATASET_S
#define N 120
#endif
#ifdef DATASET_M
#define N 400
#endif
#ifdef DATASET_L
#define N 2000
#endif
#ifdef DATASET_XL
#define N 5000
#endif

void jacobi_1d(data_t A[N], data_t B[N]);

#endif
