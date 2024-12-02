#include<stdio.h>
int main()
{
    int row,col;
    printf("Enter row and column of the matrix :");
    scanf("%d %d",&row,&col);
    int arr[row][col];
    printf("Enter elements of matrix :\n");
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Matrix after insertion :\n");
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("Transpose of the matrix :\n");
    for(int i=0; i<col; i++)
    {
        for(int j=0; j<row; j++)
        {
            printf("%d ",arr[j][i]);
        }
        printf("\n");
    }
}