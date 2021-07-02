
#ifndef _BASIC_MATRIX_H
#define _BASIC_MATRIX_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


////////////////////////////////////////////////////////////////////////////////////
/*
Made by R.Naren
Date: 24/6/2021
*/
/////////////////////////////////////////////////////////////////////////////////////

//data structure of matrix
typedef struct _matrix{

unsigned int col;
unsigned int row;

double *val;

}matrix;

//initMatrix()
//initialise a matrix of row size row and column size col with 0
//needs to be done for all newly created matrices
//mat: pointer to matrix struct to be initialized
//row is size of row
//col is size of col
void initMatrix(matrix *mat, unsigned int row, unsigned int col);

//transpose()
//transposes input matrix
//mat: pointer to input matrix
void transpose(matrix *mat);


//addMatrix()
//adds two matrices dstMat and srcMat, result is stored in dstMat
bool addMatrix(matrix *dstMat, matrix *srcMat);

//subMatric()
//subtracts srcMat from dstMat, result is stored in dstMat
bool subMatrix(matrix *dstMat, matrix *srcMat);

//mulMatrix()
//dot multiplication of dstMat and scrMat, dstMat column should be equal to srcMat row, result is stored in dstMat
bool mulMatrix(matrix *dstMat, matrix *srcMat);

//printMatrix()
//prints values of matrix on terminal
//mat:pointer to matrix to be printed
void printMatrix(matrix *mat);

//enterElement()
//enter new value to repespective element of matrix
//row is the row of element
//col is the column of the element
//val is the new value to be entered
//mat is the pointer to the matrix
bool enterElement(matrix *mat, unsigned int row, unsigned int col, double val);

//transpose_ret()
//transposes input matrix and returns the transposed matrix
//mat is the pointer to the input matrix
matrix * transpose_ret(matrix *mat);

//addMatrix_ret()
//returns a matrix containing the sum of the input matrices
matrix * addMatrix_ret(matrix *dstMat, matrix *srcMat);

//subMatric_ret()
//returns the difference of the input matrices, dst- src
matrix * subMatrix_ret(matrix *dstMat, matrix *srcMat);

//mulMatrix()
//returns dot multiplication of dstMat and scrMat, dstMat column should be equal to srcMat row, result is stored in dstMat
matrix * mulMatrix_ret(matrix *dstMat, matrix *srcMat);

//getMatrix_ele()
//return values stored in respective row/column
double getMatrix_ele(matrix *mat, unsigned int row, unsigned int col);

//eleMulMatrix()
//multiplies each element of mat with val
void eleMulMatrix(matrix *mat, double val);

#endif