#ifndef SEIDEL_2D_H
#define SEIDEL_2D_H

#define data_t float

#define DATASET_S

#ifdef DATASET_XS
#define TSTEPS 20
#define N 40
#endif
#ifdef DATASET_S
#define TSTEPS 40
#define N 122
#endif
#ifdef DATASET_M
#define TSTEPS 100
#define N 400
#endif
#ifdef DATASET_L
#define TSTEPS 500
#define N 2000
#endif
#ifdef DATASET_XL
#define TSTEPS 1000
#define N 4000
#endif

void seidel_2d(data_t A[N * N]);

#endif
