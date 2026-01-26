#include <stdio.h>

// Function to count digits
int countDigits(int n) {
    int c = 0;
    while(n != 0) {
        c++;
        n /= 10;
    }
    return c;
}

// Function to sum digits
int sumDigits(int n) {
    int sum = 0;
    while(n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Reverse number
int reverse(int n) {
    int rev = 0;
    while(n != 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return rev;
}

// Factorial function
int fact(int n){
    int f = 1;
    for(int i = 1; i <= n; i++)
        f *= i;
    return f;
}

// Strong number
int isStrong(int n) {
    int temp = n, sum = 0;
    while(temp != 0) {
        sum += fact(temp % 10);
        temp /= 10;
    }
    return sum == n;
}

// Perfect number
int isPerfect(int n) {
    int sum = 0;
    for(int i = 1; i <= n/2; i++)
        if(n % i == 0)
            sum += i;

    return sum == n;
}

// Reverse Fibonacci
void reverseFibo(int n) {
    int a = 0, b = 1, c;
    int arr[100], k = 0;

    for(int i = 0; i < n; i++) {
        arr[k++] = a;
        c = a + b;
        a = b;
        b = c;
    }

    printf("\nReverse Fibonacci: ");
    for(int i = k-1; i >= 0; i--)
        printf("%d ", arr[i]);
}

void diamond() {
    int i, j;
    
    // upper part
    for(i = 1; i <= 3; i++) {
        for(j = 1; j <= 3-i; j++) printf(" ");
        for(j = 1; j <= 2*i-1; j++) printf("*");
        printf("\n");
    }

    // lower part
    for(i = 2; i >= 1; i--) {
        for(j = 1; j <= 3-i; j++) printf(" ");
        for(j = 1; j <= 2*i-1; j++) printf("*");
        printf("\n");
    }
}

int main() {

    int choice, n;

    do {
        printf("\n================ MENU ===============\n");
        printf("1. Reverse a Number\n");
        printf("2. Count Number of Digits\n");
        printf("3. Sum of Digits\n");
        printf("4. Check Strong Number\n");
        printf("5. Check Perfect Number\n");
        printf("6. ASCII Value of Character\n");
        printf("7. Print Diamond Pattern\n");
        printf("8. Reverse Fibonacci Series\n");
        printf("9. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter number: ");
                scanf("%d", &n);
                printf("Reversed Number = %d\n", reverse(n));
                break;

            case 2:
                printf("Enter number: ");
                scanf("%d", &n);
                printf("Number of digits = %d\n", countDigits(n));
                break;

            case 3:
                printf("Enter number: ");
                scanf("%d", &n);
                printf("Sum of digits = %d\n", sumDigits(n));
                break;

            case 4:
                printf("Enter number: ");
                scanf("%d", &n);
                if(isStrong(n))
                    printf("Strong Number\n");
                else
                    printf("Not a Strong Number\n");
                break;

            case 5:
                printf("Enter number: ");
                scanf("%d", &n);
                if(isPerfect(n))
                    printf("Perfect Number\n");
                else
                    printf("Not a Perfect Number\n");
                break;

            case 6: {
                char ch;
                printf("Enter Character: ");
                scanf(" %c", &ch);
                printf("ASCII Value = %d\n", ch);
                break;
            }

            case 7:
                diamond();
                break;

            case 8:
                printf("Enter n: ");
                scanf("%d", &n);
                reverseFibo(n);
                break;

            case 9:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 9);

    return 0;
}
