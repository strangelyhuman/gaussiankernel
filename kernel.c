#include <stdio.h>
#include <math.h>
#include "kernel.h"

void mask_CentralDiff(float* sampleArray, int length_of_array, float* resultArray) {
	int centralDiff[3] = {-1, 0, 1};
	int i;
	for(i = 0; i < length_of_array - 2; i++) {

		*(resultArray + i) = (*(sampleArray + i) * centralDiff[0]) + (*(sampleArray + i + 1) * centralDiff[1]) + (*(sampleArray + i + 2) * centralDiff[2]);
	}
}

void mask_ForwardDiff(float* sampleArray, int length_of_array, float* resultArray) {
	int forwardDiff[2] = {-1, 1};
	int i;
	for(i = 0; i < length_of_array - 1; i++) {

		*(resultArray + i) = (*(sampleArray + i) * forwardDiff[0]) + (*(sampleArray + i + 1) * forwardDiff[1]);
	}
}

void genFirstOrder(float *g_mask, int length, float sigma) {	
	int i;
	int j = (-1 * length) / 2;
	
	/*generate g(x)*/
	for(i = 0; i < length; i++, j++) {
		g_mask[i] = j;
	}

	float numerator, denominator = sqrt(2 * PI) * (sigma * sigma * sigma);

	for(i = 0; i < length; i++) {
		float radix =  (g_mask[i] * g_mask[i]) / (2 * sigma *sigma);
		numerator = -1 * g_mask[i] * exp(-1 * radix);
		g_mask[i] = numerator/denominator;
	}
}

void mask_Gaussian(float *sampleArray, float *g_mask, int length_mask, float *firstOrderArray) {
	int i, j, k;
	for(i = 0; i < 25 - (length_mask - 1); i++) {
		float accumulator = 0;
		for(j = 0, k = i; j < length_mask; j++, k++) {
			accumulator += g_mask[j] * sampleArray[k];
		}
		firstOrderArray[i] = accumulator;
	}
}

void printArray(float* resultArray, int length_of_array) {
	int i;
	printf("\n");	
	for(i = 0; i < length_of_array; i++)
		printf("%f\n", resultArray[i]);
	printf("\n");	
}

void genSecondOrder(float *g_mask, int length, float sigma) {	
	int i;
	int j = (-1 * length) / 2;
	
	/*generate g(x)*/
	for(i = 0; i < length; i++, j++) {
		g_mask[i] = j;
	}

	float numerator, denominator = sqrt(2 * PI) * (sigma * sigma * sigma * sigma * sigma);

	for(i = 0; i < length; i++) {
		float radix =  (g_mask[i] * g_mask[i]) / (2 * sigma *sigma);
		numerator =  ((g_mask[i] * g_mask[i]) - (2 * sigma * sigma)) * exp(-1 * radix);
		g_mask[i] = numerator/denominator;
	}
}

void mask_Gaussian2(float *sampleArray, float *g_mask, int length_mask, float *secondOrderArray) {
	int i, j, k;
	for(i = 0; i < 25 - (length_mask - 1); i++) {
		float accumulator = 0;
		for(j = 0, k = i; j < length_mask; j++, k++) {
			accumulator += g_mask[j] * sampleArray[k];
		}
		secondOrderArray[i] = accumulator;
	}
}