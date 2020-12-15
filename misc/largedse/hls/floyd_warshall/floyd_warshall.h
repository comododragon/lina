#ifndef FLOYD_WARSHALL_H
#define FLOYD_WARSHALL_H

#define data_t float

#define DATASET_XS

#ifdef DATASET_XS
#define N 60
#endif
#ifdef DATASET_S
#define N 180
#endif
#ifdef DATASET_M
#define N 500
#endif
#ifdef DATASET_L
#define N 2800
#endif

void floyd_warshall(data_t path[N * N]);

#endif
