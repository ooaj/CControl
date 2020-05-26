/*
 ============================================================================
 Name        : Model_Predictive_Control.c
 Author      : Daniel Mårtensson
 Version     : 1.0
 Copyright   : MIT
 Description : Model Predictive Control
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "CControl/Headers/Functions.h"

#define ADIM 2
#define RDIM 1
#define YDIM 1
#define HORIZON 10


int main() {

	// State space model
	float A[ADIM * ADIM] = { 1.05216,   1.00000,
		      	  	  	  	-0.60653,   0.00000};
	float B[ADIM * RDIM] = { 0.50129,
		       	   	   	   	 0.42266};
	float C[YDIM * ADIM] = { 1, 0 };

	// Print our state space matrix
	printf("System matrix: A\n");
	print(A, ADIM, ADIM);

	printf("Input matrix: B\n");
	print(B, ADIM, RDIM);

	printf("Output matrix: C\n");
	print(C, YDIM, ADIM);

	float x[ADIM] = { 4, 2};
	float u[RDIM] = { 0 };
	float r[YDIM] = { 12.5 };

	// Do Model Predictive Control where we selecting last u
	mpc(A, B, C, x, u, r, ADIM, YDIM, RDIM, HORIZON);

	// Print solution
	printf("Best input\n");
	print(u, RDIM, 1);

	return EXIT_SUCCESS;
}
