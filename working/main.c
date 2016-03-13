#include <stdio.h>
#include <math.h>
#include "kernel.h"

#define DIFFARRAYS 0

int main() {

	int i;
	int length_mask;
	int user_choice;
	float sigma;
	

	/* Define your input Array (restricted to 25 samples) here */
	float sampleArray[25]  = {1.1, 1.1,  1.1, 3.9, 4.12, 5.13, 4.03, 3.2, 4.75, 6.3, 11.42, 1.5, -1.3, 2.2, -1.35, -1.78, -3.2, -4.38, 0.22, 1.23, 1.23, 1.23, 1.3, 1.5, 1.77 };

	
	printf("What would you like to perform?\n");
	printf("1.First Order Convolution\n2.Second Order Convolution\n");
	#if DIFF_ARRAYS
	printf("3.Central Difference Convolution\n4.Forward Difference\n");
	#endif
	printf("Enter a choice(1 or 2): ");
	scanf("%d", &user_choice);
	
#if DIFF_ARRAYS
	/*Result Array Storage*/
	float forwardDiffArray[24];
	float centralDiffArray[23];
#endif	


	printf("Enter the Length of the Mask( >= 3)\n");
	do {

	scanf("%d", &length_mask);

		if(length_mask < 3)
			printf("Enter a Value greater than or equal to 3\n");

	} while(length_mask < 3);

	float g_mask[length_mask];
	float firstOrderArray[25 - (length_mask - 1)];
	float secondOrderArray[25 - (length_mask - 1)];

	printf("Enter a Value for Sigma\n");
	scanf("%f", &sigma);

	printf("Input Array-\n");
	printArray(sampleArray, 25);

	switch(user_choice) {
		
		case 1:
		genFirstOrder(g_mask, length_mask, sigma);
		mask_Gaussian(sampleArray, g_mask, length_mask, firstOrderArray);
		printf("First Order Convolution - \n");
		printArray(firstOrderArray, (25 - (length_mask - 1)));
		break;

		case 2:
		genSecondOrder(g_mask, length_mask, sigma);
		mask_Gaussian2(sampleArray, g_mask, length_mask, secondOrderArray);
		printf("Second Order Convolution - \n");	
		printArray(secondOrderArray, (25 - (length_mask - 1)));

		#if DIFF_ARRAYS
		case 3:
		mask_CentralDiff(sampleArray, 25, centralDiffArray);
		printArray(centralDiffArray, 23);
		break;

		case 4:
		mask_ForwardDiff(sampleArray, 25, forwardDiffArray);
		printArray(forwardDiffArray, 24);
		break;

		#endif

	}

	return 0;

}