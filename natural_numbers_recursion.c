#include<stdio.h>
int natural_numbers(int i)
{
    if(i > 0)
    {
        natural_numbers(i-1);
        printf("%d\n",i);
    }
}
void main()
{
    int num;
    printf("Enter the limit :");
    scanf("%d",&num);
    natural_numbers(num);
}