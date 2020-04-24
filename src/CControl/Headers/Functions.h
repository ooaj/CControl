/*
 * Functions.h
 *
 *  Created on: 5 oct. 2019
 *      Author: Daniel Mårtensson
 */

#ifndef CCONTROL_FUNCTIONS_H_
#define CCONTROL_FUNCTIONS_H_

/*
 * Necessary libraries
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>	// required for FLT_EPSILON
#include "Configurations.h"

/*
 * Control engineering
 * TODO:
 * gpc - Ta bort. mpc ersätter gpc
 * autotuning - Ta bort. mpc ersätter detta
 * integral - baka in i mrac och lqi
 * Skapa en function som lägger in integration i en tillståndsmodell - Se theta2ss
 * Skriv om alla funktioner så att man anger storkelarna i argumenten istället för header filen.
 */
void gpc(float* A, float* B, float* C, float* x, float* u, float* r);
void mpc(float* A, float* B, float* C, float* x, float* u, float* r);
void autotuning(float* A, float* B, float* C, float* L, float* Kr);
void kalman(float* A, float* B, float* C, float* K, float* u, float* x, float* y);
void lqi(float* y, float* u, float qi, float* r, float* L, float* Li, float* x, float* xi);
void mrac(float* y, float* u, float* r, float* K1, float* K2);
int stability(float* A);
void theta2ss(float* A, float* B, float* C, float* theta, float* K);
void cab(float* GAMMA, float* PHI, float* A, float* B, float* C);
void obsv(float* PHI, float* A, float* C);
void integral(float* xi, float* r, float* y);

/*
 * Miscellaneous
 * TODO:
 * movingaverage - ersätt med filtfilt2 från Mataveid
 */
void saturation(float* input, float lower_limit, float upper_limit);
void cut(float* A, int row, int column, float* B, int start_row, int stop_row, int start_column, int stop_column);
void insert(float* A, float* B, int row_a, int column_a, int column_b, int startRow_b, int startColumn_b);
void print(float* A, int row, int column);
float sign(float number);
void movingaverage(float* y, uint16_t l, uint8_t p);

/*
 * Linear algebra
 */
int inv(float* A, int row);
void linsolve_upper_triangular(float* A, float* x, float* b, int column);
void tran(float* A, int row, int column);
void mul(float* A, float* B, float* C, int row_a, int column_a, int column_b);
void svd_jacobi_one_sided(float *A, uint16_t row, uint8_t max_iterations, float *U, float *S, float *V);
void dlyap(float* A, float* P, float* Q, int row);
int svd_golub_reinsch(float *A, uint16_t row, uint16_t column, float *U, float *singular_values, float *V);
void qr(float* A, float* Q, float* R, int row_a, int column_a);
void triu(float* A, float* b, int row);
void linsolve_lower_triangular(float *A, float *x, float *b, int row);
void tikhonov(float* A, float* b, float* ATA, float* ATb, int row_a, int column_a, float alpha);
int lup(float *A, float *LU, int *P, int row);
float det(float *A, int row);
int linsolve_lup(float *A, float *x, float *b, int row);
void chol(float *A, float *L, int row);
void pinv(float* A, int row, int column);
void hankel(float* V, float* H, uint16_t row_v, uint16_t column_v, uint16_t row_h, uint16_t column_h, uint16_t shift);
void balance(float* A, uint16_t row);
void eig(float* A, float* wr, float* wi, uint16_t row);
void eig_sym(float* A, uint16_t row, float* d);

/*
 * Optimization
 * TODO:
 * Använd linprog för att skapa quadprog - Hur gör man det?
 */
void linprog(float* c, float* A, float* b, float* x, int row_a, int column_a, uint8_t max_or_min, int iteration_limit);

/*
 * AI-algorithms
 */
void Astar(int *map, int *path_x, int *path_y, int x_start, int y_start, int x_stop, int y_stop, int height, int width, int norm_mode, int* steps);

/*
 * System identification
 * TODO:
 * rls ska ha theta2ss inkluderat. rls skall generera tillståndsmodell direkt
 * okid behöver skrivas om till okid.m i Mataveid
 */
void rls(float* theta, float u, float y, int* count, float* past_e, float* past_y, float* past_u, float* phi, float* P);
void okid(float* u, float* y, float* g, uint16_t row, uint16_t column);
void era(float* u, float* y, uint16_t row, uint16_t column, float* A, float* B, float* C, uint8_t row_a, uint8_t inputs_outputs);

/*
 * Classification
 * TODO:
 * lbph - Ta bort. Dålig då den ej tål brus (olika färger i bakgrunden)
 * titta på Bytefish's Fisherfaces och skapa en funktion som kan använda k-nearest neighbors för att validera
 * rad 22 https://github.com/bytefish/facerec/blob/master/m/prediction_example.m
 *
 */
uint16_t lbph(uint8_t* picture, uint16_t row_p, uint16_t column_p, uint8_t* histograms, uint16_t row_h, bool save);


#endif /* CCONTROL_FUNCTIONS_H_ */
