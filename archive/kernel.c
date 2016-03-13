#include <stdio.h>
#include <math.h>

#define PI 3.14
#define ECONST 2.718

float getGaussian(int val, float stdev) {
	float denom = sqrt(2 * PI) * stdev;
	float radix = -1 * ((val * val) / (2 * stdev * stdev));
	float gaussian = (1 / denom) * pow(ECONST, radix);
	return gaussian;
}

int main() {

	const int array_length = 25;

	float i2c_sample[] = { 1.1, 1.1,  1.1, 3.9, 4.12, 5.13, 4.03, 3.2, 4.75, 6.3, 11.42, 1.5, -1.3, 2.2, -1.35, -1.78, -3.2, -4.38, 0.22, 1.23, 1.23, 1.23, 1.3, 1.5, 1.77 };
	float sigma = 3.229517;
	float kernel[3] = {};
	float convolved[28] = {0};
	int i ,j;

	//generate your gaussian generation
	for(i = 0, j = -1; i < 3; ++j, ++i)
		kernel[i] = getGaussian(j, sigma);

	//multiply samples with kernel
	for(i = 0; i < array_length - 2; i++) {
		float product = (i2c_sample[i] * kernel[0]) + (i2c_sample[i + 1] * kernel[1] + i2c_sample[i + 2] * kernel[2]);
		convolved[i] = product;
	}

	for(i = 0; i < 3; i < ++i) {
		printf("%f\n", kernel[i]);
	}

	return 0;
}