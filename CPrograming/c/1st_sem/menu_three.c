#include <stdio.h>
#include <math.h>

// FUNCTION DECLARATIONS
void sum_first_10();
void sum_m_to_n();
void multiplication_table();
void factorial_num();
void largest_10();
void palindrome_check();
void armstrong_check();
void prime_check();
void prime_check_other_logic();
void decimal_to_binary();
void binary_to_decimal();
void fibonacci_series();
void gcd_two_numbers();
void series_sum();

int main() {
    int choice;

    while (1) {
        printf("\n========== MENU ==========\n");
        printf("1. Sum of first 10 numbers\n");
        printf("2. Sum from m to n\n");
        printf("3. Multiplication table\n");
        printf("4. Factorial of a number\n");
        printf("5. Largest among 10 numbers\n");
        printf("6. Check Palindrome number\n");
        printf("7. Check Armstrong number\n");
        printf("8. Check Prime number (standard)\n");
        printf("9. Check Prime number (other logic)\n");
        printf("10. Decimal to Binary\n");
        printf("11. Binary to Decimal\n");
        printf("12. Fibonacci series up to n terms\n");
        printf("13. GCD of two numbers\n");
        printf("14. Sum of series: 1/1! + 1/2! + ...\n");
        printf("15. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: sum_first_10(); break;
            case 2: sum_m_to_n(); break;
            case 3: multiplication_table(); break;
            case 4: factorial_num(); break;
            case 5: largest_10(); break;
            case 6: palindrome_check(); break;
            case 7: armstrong_check(); break;
            case 8: prime_check(); break;
            case 9: prime_check_other_logic(); break;
            case 10: decimal_to_binary(); break;
            case 11: binary_to_decimal(); break;
            case 12: fibonacci_series(); break;
            case 13: gcd_two_numbers(); break;
            case 14: series_sum(); break;
            case 15: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}


void sum_first_10() {
    int sum = 0;
    for (int i = 1; i <= 10; i++)
        sum += i;
    printf("Sum = %d\n", sum);
}


// 2. SUM FROM M TO N
void sum_m_to_n() {
    int m, n, sum = 0;
    printf("Enter m and n: ");
    scanf("%d %d", &m, &n);
    for (int i = m; i <= n; i++)
        sum += i;
    printf("Sum = %d\n", sum);
}


// 3. MULTIPLICATION TABLE
void multiplication_table() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    for (int i = 1; i <= 10; i++)
        printf("%d x %d = %d\n", n, i, n*i);
}


// 4. FACTORIAL
void factorial_num() {
    int n;
    long long fact = 1;
    printf("Enter number: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        fact *= i;

    printf("Factorial = %lld\n", fact);
}


// 5. LARGEST AMONG 10 NUMBERS
void largest_10() {
    int n, max;
    printf("Enter 10 numbers:\n");
    scanf("%d", &max);

    for (int i = 2; i <= 10; i++) {
        scanf("%d", &n);
        if (n > max)
            max = n;
    }

    printf("Largest = %d\n", max);
}


// 6. PALINDROME NUMBER
void palindrome_check() {
    int n, temp, rev = 0;
    printf("Enter number: ");
    scanf("%d", &n);

    temp = n;
    while (temp > 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }

    if (rev == n)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
}


// 7. ARMSTRONG NUMBER
void armstrong_check() {
    int n, temp, sum = 0, digit;
    printf("Enter number: ");
    scanf("%d", &n);

    temp = n;
    while (temp > 0) {
        digit = temp % 10;
        sum += digit * digit * digit; // for 3-digit Armstrong
        temp /= 10;
    }

    if (sum == n)
        printf("Armstrong\n");
    else
        printf("Not Armstrong\n");
}


// 8. PRIME CHECK (STANDARD)
void prime_check() {
    int n, flag = 1;
    printf("Enter number: ");
    scanf("%d", &n);

    if (n <= 1)
        flag = 0;

    for (int i = 2; i <= n/2; i++)
        if (n % i == 0)
            flag = 0;

    if (flag)
        printf("Prime\n");
    else
        printf("Not Prime\n");
}


// 9. PRIME CHECK (OTHER LOGIC – √n METHOD)
void prime_check_other_logic() {
    int n, flag = 1;
    printf("Enter number: ");
    scanf("%d", &n);

    if (n <= 1)
        flag = 0;

    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            flag = 0;

    if (flag)
        printf("Prime\n");
    else
        printf("Not Prime\n");
}


// 10. DECIMAL TO BINARY
void decimal_to_binary() {
    int n, bin[32], i = 0;
    printf("Enter decimal number: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("Binary = 0\n");
        return;
    }

    while (n > 0) {
        bin[i++] = n % 2;
        n /= 2;
    }

    printf("Binary = ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", bin[j]);
    printf("\n");
}


// 11. BINARY TO DECIMAL
void binary_to_decimal() {
    long bin;
    int dec = 0, base = 1;
    printf("Enter binary number: ");
    scanf("%ld", &bin);

    while (bin > 0) {
        dec += (bin % 10) * base;
        bin /= 10;
        base *= 2;
    }

    printf("Decimal = %d\n", dec);
}


// 12. FIBONACCI SERIES
void fibonacci_series() {
    int n, a = 0, b = 1, c;
    printf("Enter n: ");
    scanf("%d", &n);

    printf("%d %d ", a, b);
    for (int i = 3; i <= n; i++) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
    printf("\n");
}


// 13. GCD USING LOOP
void gcd_two_numbers() {
    int a, b, gcd = 1;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    for (int i = 1; i <= a && i <= b; i++)
        if (a % i == 0 && b % i == 0)
            gcd = i;

    printf("GCD = %d\n", gcd);
}


// 14. SERIES SUM 1/1! + 1/2! + ....
void series_sum() {
    int n;
    double sum = 0, fact;
    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        fact = 1;
        for (int j = 1; j <= i; j++)
            fact *= j;
        sum += 1.0 / fact;
    }

    printf("Sum = %lf\n", sum);
}
