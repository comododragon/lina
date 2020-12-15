#ifndef HEAT_3D_H
#define HEAT_3D_H

#define data_t float

#define DATASET_M

#ifdef DATASET_XS
#define N 10
#endif
#ifdef DATASET_S
#define N 20
#endif
#ifdef DATASET_M
#define N 50
#endif
#ifdef DATASET_L
#define N 120
#endif

void heat_3d(data_t A[N * N * N], data_t B[N * N * N]);

#endif
