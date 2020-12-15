#ifndef GEMM_H
#define GEMM_H

#define data_t float
#define ALPHA 1.5f
#define BETA 1.2f

#define DATASET_S

#ifdef DATASET_S
#define NI 60
#define NJ 70
#define NK 80
#endif
#ifdef DATASET_M
#define NI 200
#define NJ 220
#define NK 240
#endif
#ifdef DATASET_L
#define NI 1000
#define NJ 1100
#define NK 1200
#endif

void gemm(data_t C[NI * NJ], data_t A[NI * NK], data_t B[NK * NJ]);

#endif
