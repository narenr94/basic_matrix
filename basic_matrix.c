
////////////////////////////////////////////////////////////////////////////////////
/*
Made by R.Naren
Date: 24/6/2021
*/
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/*

matrix =    | 1 2 3 4 |
            | 5 6 7 8 |

is represented in structure as matrix[] = {1,2,3,4,5,6,7,8};
i.e., row followed by column


*/
/////////////////////////////////////////////////////////////////////////////////////////////
#include "basic_matrix.h"

void initMatrix(matrix *mat, unsigned int col, unsigned int row)
{

    unsigned int i = 0;
    int j = 0;

    mat->col = col;
    mat->row = row;

    mat->val = (double *)malloc(sizeof(double) * row * col);

    

}

void transpose(matrix *mat)
{
    int i = 0;
    int j = 0;
    int tempRow = 0;
    int tempRow1 = 0;
    

    double * temp = (double *)malloc(sizeof(double) * mat->row * mat->col);

    for( i = 0; i < mat->row; i++)
    {
        for(j = 0; j < mat->col; j++)
        {
            tempRow = (i * mat->col) + j;
            temp[tempRow] = mat->val[tempRow];
        }
        
    }

    //mat->row =2 mat->col = 4
    ////////////////////////////////0123 4567 -> 04 15 26 37////////////////////////////// 
    for(i = 0; i < mat->row; i++)
    {

        for(j = 0; j < mat->col; j++)
        {
            tempRow = (i * mat->col) + j;
            tempRow1 = (j * mat->row) + i;

            
            mat->val[tempRow1] = temp[tempRow];
        }

    }

    tempRow = mat->row;
    mat->row = mat->col;
    mat->col = tempRow;

    

    //update number of rows and columns
    

    free(temp);
}

matrix * transpose_ret(matrix *mat)
{
    matrix * new = (matrix *)malloc(sizeof(matrix));

    initMatrix(new, mat->row, mat->col);

    int i = 0;
    int j = 0;
    int tempRow = 0;
    int tempRow1 = 0;

    for(i = 0; i < mat->row; i++)
    {

        for(j = 0; j < mat->col; j++)
        {
            tempRow = (i * mat->col) + j;
            tempRow1 = (j * mat->row) + i;

            
            new->val[tempRow1] = mat->val[tempRow];
        }

    }


    return new;

}

bool addMatrix(matrix *dstMat, matrix *srcMat)
{
    int i = 0;
    int j = 0;
    int tempRow = 0;

    if(dstMat->row != srcMat->row || dstMat->col != srcMat->col)
    {
        return false;
    }

    for(i = 0; i < dstMat->row; i++)
    {  
        for (j = 0; j < dstMat->col; j++)
        {
            tempRow = (i * dstMat->col) + j;
            dstMat->val[tempRow] += srcMat->val[tempRow];
        }
        
    }

    return true;
}

matrix * addMatrix_ret(matrix *dstMat, matrix *srcMat)
{

    if(dstMat->row != srcMat->row || dstMat->col != srcMat->col)
    {
        return NULL;
    }
    matrix * new = (matrix *)malloc(sizeof(matrix));

    initMatrix(new, dstMat->col, dstMat->row);
    int i = 0;
    int j = 0;
    int tempRow = 0;

    for(i = 0; i < dstMat->row; i++)
    {  
        for (j = 0; j < dstMat->col; j++)
        {
            tempRow = (i * dstMat->col) + j;
            new->val[tempRow] = dstMat->val[tempRow] + srcMat->val[tempRow];
        }
        
    }

    return new;

}

bool subMatrix(matrix *dstMat, matrix *srcMat)
{
    int i = 0;
    int j = 0;
    int tempRow = 0;

    if(dstMat->row != srcMat->row || dstMat->col != srcMat->col)
    {
        return false;
    }

    for(i = 0; i < dstMat->row; i++)
    {  
        for (j = 0; j < dstMat->col; j++)
        {
            tempRow = (i * dstMat->col) + j;
            dstMat->val[tempRow] -= srcMat->val[tempRow];
        }
        
    }

    return true;
}

matrix * subMatrix_ret(matrix *dstMat, matrix *srcMat)
{
    if(dstMat->row != srcMat->row || dstMat->col != srcMat->col)
    {
        return NULL;
    }
    matrix * new = (matrix *)malloc(sizeof(matrix));

    initMatrix(new, dstMat->col, dstMat->row);
    int i = 0;
    int j = 0;
    int tempRow = 0;

    for(i = 0; i < dstMat->row; i++)
    {  
        for (j = 0; j < dstMat->col; j++)
        {
            tempRow = (i * dstMat->col) + j;
            new->val[tempRow] = dstMat->val[tempRow] - srcMat->val[tempRow];
        }
        
    }

    return new;
}

bool mulMatrix(matrix *dstMat, matrix *srcMat)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int tempRow = 0;
    int tempRow1 = 0;

    double tempVal = 0;

    

    if(dstMat->col != srcMat->row)
    {
        return false;
    }

    double *temp = (double *)calloc(dstMat->row * srcMat->col, sizeof(double));

    for(i = 0; i < dstMat->row; i++)
    {
        for(j = 0; j < srcMat->col; j++)
        {
            tempVal = 0;
            for(k = 0; k < dstMat->col; k++)
            {
                tempRow = (i * srcMat->row) + k;
                tempRow1 = (k * srcMat->col) + j;
                tempVal += (dstMat->val[tempRow] * srcMat->val[tempRow1]); 
                
            }
            tempRow = (i * srcMat->col) + j;
            temp[tempRow] = tempVal;
        }
    }

    free(dstMat->val);

    dstMat->val = (double *)calloc(dstMat->row * srcMat->col, sizeof(double));

    for(i = 0; i < dstMat->row; i++)
    {
        for(j = 0; j < srcMat->col; j++)
        {
            tempRow = (i * srcMat->col) + j;
            dstMat->val[tempRow] = temp[tempRow];
        }
    }

    dstMat->col = srcMat->col;

    free(temp);

    return true;

}

matrix * mulMatrix_ret(matrix *dstMat, matrix *srcMat)
{
    if(dstMat->col != srcMat->row)
    {
        return NULL;
    }
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int tempRow = 0;
    int tempRow1 = 0;

    double tempVal = 0;

    matrix * new = (matrix *)malloc(sizeof(matrix));

    initMatrix(new, srcMat->col, dstMat->row);

    for(i = 0; i < dstMat->row; i++)
    {
        for(j = 0; j < srcMat->col; j++)
        {
            tempVal = 0;
            for(k = 0; k < dstMat->col; k++)
            {
                tempRow = (i * srcMat->row) + k;
                tempRow1 = (k * srcMat->col) + j;
                tempVal += (dstMat->val[tempRow] * srcMat->val[tempRow1]); 
                
            }
            tempRow = (i * srcMat->col) + j;
            new->val[tempRow] = tempVal;
        }
    }

    return new;

}

void printMatrix(matrix *mat)
{
    int i = 0;
    int j = 0;
    int tempRow = 0;

    for(i = 0; i < mat->row; i++)
    {
        for(j = 0; j < mat->col; j++)
        {
            tempRow = (i * mat->col) + j;
            printf("%05f\t", mat->val[tempRow]);
        }
        printf("\n");
    }
}

bool enterElement(matrix *mat, unsigned int row, unsigned int col, double val)
{
    int tempRow = 0;

    if(row >= mat->row || col >= mat->col)
    {
        return false;
    }

    tempRow = (row * mat->col) + col;

    mat->val[tempRow] = val;

    return true;
}