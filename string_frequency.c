#include <stdio.h>
#include <string.h>

int main() 
{
    char s[1000], num[10] = {'0','1','2','3','4','5','6','7','8','9'};
    int count;
    printf("Enter an alphanumeric string :");
    scanf("%s", s);
    for(int i=0; i < 10; i++)
    {
        count = 0;
        for(int j=0; j < strlen(s); j++)
        {
            if(s[j] == num[i])
            {
                count ++;
            }
        }
        printf("%d ",count);
    }
    return 0;
}
