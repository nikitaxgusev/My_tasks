#ifndef _ARRAY2D_H_INCLUDED
#define _ARRAY2D_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct _Array2D
{
    int rows; // number of rows
    int cols; // number of columns
    int** Array;
}_Array2D;

_Array2D* Array_create(int n, int m)
{
    struct _Array2D* ar2D=malloc(sizeof(_Array2D));
      int i;

    ar2D->rows=n;
    ar2D->cols=m;

    int** ARR=(int**)malloc(sizeof(int*)*n);
    if(!ARR)
    {
        printf("Allocatinon memory\n");
        exit(-1);
    }
    for(i=0;i<n;i++)
    {
        ARR[i]=(int*)malloc(sizeof(int)*m);
        if(!ARR[i])
        {
            printf("Allocatinon memory\n");
            exit(-1);
        }
    }

    ar2D->Array=ARR;
    return ar2D;

}

void Array_fill(_Array2D *arr, int value)
{
   int i,j,n,m;
   int** ARR;

    n=arr->rows;
    m=arr->cols;
    ARR=arr->Array;


    printf("Array filling: \n\n");
    for (i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            arr->Array[i][j]=value;
            printf("A[%d][%d] =[%d] \n",i,j ,arr->Array[i][j]);
        }
    }


}

void Array_delete(_Array2D *arr)
{
    int i=0;
    for(i=0;i<arr->rows;i++)
    {
        free(arr->Array[i]);
    }
    free(arr->Array);
    arr->Array=NULL;
}

int array_get(_Array2D *arr, int i, int j)
{
    return arr->Array[i][j];
}
void array_set(_Array2D *arr, int i, int j, int value)
{
    arr->Array[i][j]=value;
    printf("Array[%d][%d]=%d",i,j,arr->Array[i][j]);
}


#endif // _ARRAY2D_H_INCLUDED
