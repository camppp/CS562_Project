#include <stdio.h>

/*
* Gets an integer input from the user
*/
int get_user_input()
{
    int input;
    while (1)
    {
        printf("Enter a non-negative integer: ");
        if (scanf("%d", &input) == 1 && input >= 0)
        {
            return input;
        }
        else
        {
            printf("Invalid input. Please enter a non-negative integer.\n");
            while (getchar() != '\n'); // Clear input buffer
        }
    }
}

/*
* Calculates the factorial of a given non-negative integer
*/
unsigned long long factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        unsigned long long result = 1;
        for (int i = 2; i <= n; i++)
        {
            result *= i;
        }
        return result;
    }
}

int main()
{
    int input = get_user_input();
    unsigned long long result = factorial(input);
    printf("%d! = %llu\n", input, result);
    return 0;
}
