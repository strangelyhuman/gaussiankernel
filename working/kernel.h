
/*
* This header file contains the function prototypes and descriptions 
* of those functions.
*/

/*Defining a value for PI*/
#define PI 3.14159

void mask_CentralDiff(float* sampleArray, int length_of_array, float* resultArray);
/*
Given the length of the sampleArray, Performs a Convolution of sampleArray with mask
based on the Central Difference and stores the resultant array in resultArray
*/

void mask_ForwardDiff(float* sampleArray, int length_of_array, float* resultArray);
/*
Given the length of the sampleArray, performs a convolution of the sampleArray with mask
based on the Forward Difference and stores the resultant array in resultArray
*/

void genFirstOrder(float* g_mask, int length, float sigma);
/*
Pre-condition: length % 2 != 0 
Generates a first order Gaussian Mask of length 'length' for a specified value of standard deviation
sigma and stores the mask at g_mask
*/

void mask_Gaussian(float* sampleArray, float* g_mask, int length_mask, float* firstOrderArray);
/*
Performs convolution of sampleArray with first order gaussian mask of length length_mask
and stores the resultant array at firstOrderArray
*/

void genSecondOrder(float* g_mask, int length, float sigma);
/*
Pre-condition: length % 2 != 0 
Generates a second order Gaussian Mask of length 'length' for a specified value of standard deviation
sigma and stores the mask at g_mask
*/

void mask_Gaussian2(float* sampleArray, float* g_mask, int length_mask, float* secondOrderArray);
/*
Performs convolution of sampleArray with first order gaussian mask of length length_mask
and stores the resultant array at firstOrderArray
*/

void printArray(float* resultArray, int length_of_array);
/*
Prints all elements of resultArray of length length_of_array
*/