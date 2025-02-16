#include "multithreadGPU.h"
#include <stdio.h>

unsigned long size_Points = NUMBER_OF_POINTS * sizeof(Points);
unsigned long size_Parameters = sizeof(Parameters);


// GPU_Palette openPallete_Points() {
  
//   unsigned long theSize = NUMBER_OF_POINTS * 3;
//   unsigned long memSize = theSize * sizeof(float);

//   float* xmap = (float*) malloc(memSize);
//   float* ymap = (float*) malloc(memSize);
//   float* zmap = (float*) malloc(memSize);

//   for(int i = 0; i < theSize; i++){
//     xmap[i] = getRandNum();
//     ymap[i] = getRandNum();
//     zmap[i] = getRandNum();
//   }

//   GPU_Palette P2 = initGPUPalette(NUMBER_OF_POINTS, 1);

//   cudaMemcpy(P2.red,    xmap, memSize, cH2D);
//   cudaMemcpy(P2.green,  ymap, memSize, cH2D);
//   cudaMemcpy(P2.blue,   zmap, memSize, cH2D);

//   free(xmap);
//   free(ymap);
//   free(zmap);
// }

// int updatePoint(GPU_Palette* P) {
//   calculatePoint <<<P->gBlocks, P->gThreads>>> (P->red, P->green, P->blue);  
// }

// __global__ void calculatePoint(float* xP, float* yP, float* zP) {

//   int x = threadIdx.x + (blockIdx.x * blockDim.x);
//   int y = threadIdx.y + (blockIdx.y * blockDim.y);
//   int vecIdx = x + (y * blockDim.x * gridDim.x);

//   double delta_x, delta_y, delta_z;
  
//   delta_x = t * (10.0 * (yP[vecIdx] - xP[vecIdx]));
//   delta_y = t * ( (xP[vecIdx] * (28.0 - xP[vecIdx])) - yP[vecIdx]);
//   delta_z = t * ( (xP[vecIdx] * yP[vecIdx]) - (2.666 * xP[vecIdx]) );

//   xP[vecIdx] += delta_x;
//   yP[vecIdx] += delta_y;
//   zP[vecIdx] += delta_z;

// //   static float minX = -20.0;
// //   static float maxX = 20.0;
// //   static float minY = -30.0;
// //   static float maxY = 30.0;

// //   static float xRange = fabs(maxX - minX);
// //   static float xScalar = 0.9 * (gWIDTH/xRange);

// //   static float yRange = fabs(maxY - minY);
// //   static float yScalar = 0.9 * (gHEIGHT/yRange);

// //   Points->points[tid].xIdx = round(xScalar * (Points->points[tid].x - minX));
// //   Points->points[tid].yIdx = round(yScalar * (Points->points[tid].y - minY));

//   Points->points[tid].xIdx = floor((Points->points[tid].x * 32) + 960); // (X * scalar) + (gWidth/2)
//   Points->points[tid].yIdx = floor((Points->points[tid].y * 18) + 540); // (Y * scalar) + (gHeight/2)
// }


Points initPointMem_GPU(Points* points) {

  Points *PointsGPU;

  cudaMalloc((void**) &PointsGPU, size_Points);  
  cudaMemcpy(PointsGPU, &points, size_Points, cH2D);
  
  printf("%f\n", points->points[0].start_x);
  printf("%f\n", PointsGPU->points[0].start_x);
  
  cudaError_t err = cudaGetLastError();
  if ( err != cudaSuccess ) {
    printf("\nCUDA Error: %s\n", cudaGetErrorString(err));
    exit(-1);
  }

  return *PointsGPU;
}

Parameters initParametersMem_GPU(Parameters* parameters) {

  Parameters *ParametersGPU;

  cudaMalloc((void**) &ParametersGPU, size_Parameters);  
  cudaMemcpy(ParametersGPU, &parameters, size_Parameters, cH2D);
  
  printf("%f\n", parameters->b);
  printf("%f\n", &(ParametersGPU->b));
  
  cudaError_t err = cudaGetLastError();
  if ( err != cudaSuccess ) {
    printf("\nCUDA Error: %s\n", cudaGetErrorString(err));
    exit(-1);
  }

  return *ParametersGPU;
}

int updatePoint_GPU(Points* PointsGPU, Parameters* ParametersGPU) {
  calculatePoint <<<NUMBER_OF_POINTS, 1>>> (PointsGPU, ParametersGPU);
  return 0;
}

int shareFromGPUtoHost(Points* points, Points* Points_GPU) {
  cudaMemcpy(points, Points_GPU, size_Points, cD2H);

  return 0;
}

int freePointMem_GPU(Points* Points_GPU, Parameters* ParametersGPU) {
  cudaFree(&Points_GPU);
  cudaFree(&ParametersGPU);

  return 0;
}

int initStartingPoints_GPU(Points* Points_GPU) {
  initStartingPoint <<<1, NUMBER_OF_POINTS>>> (Points_GPU);

  return 0;
}

__global__ void initStartingPoint(Points* Points) {

  int tid = threadIdx.x;
  printf("tid: %d\n", tid);

  Points->points[tid].start_x = 0.5;
  Points->points[tid].start_y = 0.5;
  Points->points[tid].start_z = 0.5;

  Points->points[tid].x = Points->points[tid].start_x*10;
  Points->points[tid].y = Points->points[tid].start_y*10;
  Points->points[tid].z = Points->points[tid].start_z*10;

  Points->points[tid].red = Points->points[tid].start_x;
  Points->points[tid].green = Points->points[tid].start_y;
  Points->points[tid].blue = Points->points[tid].start_z;

  if((Points->points[tid].red >= Points->points[tid].green) && (Points->points[tid].red >= Points->points[tid].blue))
    Points->points[tid].color_heatTransfer = 0;
  else if (Points->points[tid].green >= Points->points[tid].blue)
    Points->points[tid].color_heatTransfer = 1;
  else
    Points->points[tid].color_heatTransfer = 2;
}

__global__ void calculatePoint(Points* PointsGPU, Parameters* ParametersGPU) {

  int tid = blockIdx.x;
  printf("gpu_mt_tid: %d\n", tid);
  // printf("%f\n", (&gpu_t)->points->points[tid].start_x);

//   gpu_t->points->points[tid].delta_x = t * (gpu_t->parameters.a * (gpu_t->points->points[tid].y - gpu_t->points->points[tid].x));
//   gpu_t->points->points[tid].delta_y = t * ( (gpu_t->points->points[tid].x * (gpu_t->parameters.b - gpu_t->points->points[tid].z)) - gpu_t->points->points[tid].y);
//   gpu_t->points->points[tid].delta_z = t * ( (gpu_t->points->points[tid].x * gpu_t->points->points[tid].y) - (gpu_t->parameters.c * gpu_t->points->points[tid].z) );

//   gpu_t->points->points[tid].x += gpu_t->points->points[tid].delta_x;
//   gpu_t->points->points[tid].y += gpu_t->points->points[tid].delta_y;
//   gpu_t->points->points[tid].z += gpu_t->points->points[tid].delta_z;

//   printf("%d: %f\n", tid, gpu_t->points->points[tid].x);

// //   static float minX = -20.0;
// //   static float maxX = 20.0;
// //   static float minY = -30.0;
// //   static float maxY = 30.0;

// //   static float xRange = fabs(maxX - minX);
// //   static float xScalar = 0.9 * (gWIDTH/xRange);

// //   static float yRange = fabs(maxY - minY);
// //   static float yScalar = 0.9 * (gHEIGHT/yRange);

// //   gpu_t->points->points[tid].xIdx = round(xScalar * (gpu_t->points->points[tid].x - minX));
// //   gpu_t->points->points[tid].yIdx = round(yScalar * (gpu_t->points->points[tid].y - minY));

//   gpu_t->points->points[tid].xIdx = floor((gpu_t->points->points[tid].x * 32) + 960); // (X * scalar) + (gWidth/2)
//   gpu_t->points->points[tid].yIdx = floor((gpu_t->points->points[tid].y * 18) + 540); // (Y * scalar) + (gHeight/2)
}