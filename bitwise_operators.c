#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void calculate_the_maximum(int n, int k) 
{
  int maxAND =0, maxOR =0, maxXOR=0, temp=0;
  for(int i=1; i<n; i++)
  {
      for(int j=i+1; j<=n; j++)
      {
          temp = i&j;
          maxAND = ((temp > maxAND) && (temp < k)) ? temp : maxAND;
          
          temp = i|j;
          maxOR = ((temp > maxOR) && (temp < k)) ? temp : maxOR;
          
          temp = i^j;
          maxXOR = ((temp > maxXOR) && (temp < k)) ? temp : maxXOR;
      }
  }
  printf("%d\n%d\n%d",maxAND,maxOR,maxXOR);
}

int main() 
{
    int n, k;
  printf("Enter two numbers :");
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}