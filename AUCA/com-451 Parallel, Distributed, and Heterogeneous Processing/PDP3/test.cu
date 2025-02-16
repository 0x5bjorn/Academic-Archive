#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    float a, b;
} point;

__global__ void testKernel(point *p)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    p[i].a = 1.1;
    p[i].b = 2.2;
}

int main(void)
{
        // set number of points 
    int numPoints    = 16,
        gpuBlockSize = 4,
        pointSize    = sizeof(point),
        numBytes     = numPoints * pointSize,
        gpuGridSize  = numPoints / gpuBlockSize;

        // allocate memory
    point *cpuPointArray,
          *gpuPointArray;
    cpuPointArray = (point*)malloc(numBytes);
    cudaMalloc((void**)&gpuPointArray, numBytes);

        // launch kernel
    testKernel<<<gpuGridSize,gpuBlockSize>>>(gpuPointArray);

        // retrieve the results
    cudaMemcpy(cpuPointArray, gpuPointArray, numBytes, cudaMemcpyDeviceToHost);
    printf("testKernel results:\n");
    for(int i = 0; i < numPoints; ++i)
    {
        printf("point.a: %f, point.b: %f\n",cpuPointArray[i].a,cpuPointArray[i].b);
    }
 
    printf("point.a: %f, point.b: %f\n", (gpuPointArray)->a, (gpuPointArray)->b);
 
        // deallocate memory
    free(cpuPointArray);
    cudaFree(gpuPointArray);

    return 0;
}