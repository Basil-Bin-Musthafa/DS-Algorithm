#include <stdio.h>

int main() {
    int n, n1, rem = 0, num = 0, dig, pow;

    printf("Check if the given number is an Armstrong number.\n");
    printf("Enter the number of digits in the number (must be greater than 2): ");
    scanf("%d", &dig);
    printf("Enter the number: ");
    scanf("%d", &n);

    n1 = n;

    while (n1 != 0) 
    {
        rem = n1 % 10;
        pow = 1;
        for (int i = 0; i < dig; i++) 
        {
            pow *= rem;
        }

        num += pow;
        n1 /= 10;
    }

    if (num == n) {
        printf("%d is an Armstrong number.\n", n);
    } else {
        printf("%d is not an Armstrong number.\n", n);
    }

    return 0;
}
