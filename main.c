#include "basic_matrix.h"

int main()
{
    int i = 0;
    int j = 0;
    double val = 0;
    matrix mat1, mat2, mat3;
    matrix * mat4;

    initMatrix(&mat1, 4, 2);
    initMatrix(&mat2, 2, 4);
    initMatrix(&mat3, 2, 4);
    for(i = 0; i < mat1.row; i++)
    {
        for(j = 0; j < mat1.col; j++)
        {
            val = (i * mat1.col) + j;
            printf("%d\n", val);
            enterElement(&mat1, i, j, val);
            enterElement(&mat2, j, i, val);
            enterElement(&mat3, j, i, val);
        }
    }

    printf("mat1:\n");
    printMatrix(&mat1);
    printf("\n");

    printf("mat2:\n");
    printMatrix(&mat2);
    printf("\n");

    printf("mat3:\n");
    printMatrix(&mat3);
    printf("\n");

    mat4 = mulMatrix_ret(&mat1,&mat2);
    printf("Result Matrix:\n");
    printMatrix(mat4);
    printf("\n");
    free(mat4);

    printf("mat2_transpose:\n");
    mat4 = transpose_ret(&mat2);
    printMatrix(mat4);
    printf("\n");
    free(mat4);

    printf("mat2_add:\n");
    mat4 = addMatrix_ret(&mat2, &mat2);
    printMatrix(mat4);
    printf("\n");


    return 0;
}