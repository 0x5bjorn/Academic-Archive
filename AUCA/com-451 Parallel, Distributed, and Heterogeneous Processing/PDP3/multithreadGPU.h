#ifndef multithreadGPULib
#define multithreadGPULib

#include "struct.h"
#include "interface.h"

#define CUDA_CALL(x) {cudaError_t cuda_error__ = (x); if (cuda_error__) printf("CUDA error: " #x " returned \"%s\"\n", cudaGetErrorString(cuda_error__));}

struct GPU_threading {
    Points* points;
    Parameters* parameters;
};

Points initPointMem_GPU(Points*);
Parameters initParametersMem_GPU(Parameters*);
int updatePoint_GPU(Points*, Parameters*);
int freePointMem_GPU(Points*, Parameters*);
int shareFromGPUtoHost(Points*, Points*);
int initStartingPoints_GPU(Points*);

__global__ void initStartingPoint(Points*);
__global__ void calculatePoint(Points*, Parameters*);

#endif