#include<stdio.h>
void swap(int a, int b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void main()
{
    int min,n;
    printf("Enter array limit :");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0; i<n; i++)
    {
        min = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        if(arr[min] != i)
        {
            swap(&arr[i],&arr[min]);
        }
    }
    printf("Array elements in ascending order :\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t",arr[i]);
    }
}