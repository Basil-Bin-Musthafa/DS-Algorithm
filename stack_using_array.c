#include <stdio.h>

int stack[5], top = -1, n, choose = 0;

void push();
void pop();
void display();

int main()
{
    printf("Enter the size of stack: ");
    scanf("%d", &n);

    printf("---Stack operations using array---\n");
    while (choose != 4)
    {
        printf("\nChoose one option from below\n");
        printf("1. Push\n2. Pop\n3. Display elements\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choose);

        switch (choose)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void push()
{
    int value;

    if (top == n - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        printf("Enter value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("Value %d pushed to stack\n", value);
    }
}

void pop()
{
    if (top == -1) 
    {
        printf("Stack underflow\n");
    }
    else
    {
        printf("Popped value: %d\n", stack[top]);
        top--;
    }
}

void display()
{
    if (top == -1) 
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
