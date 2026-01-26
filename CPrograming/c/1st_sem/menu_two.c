#include <stdio.h>
#include <ctype.h>
#include <math.h>

void largest_two();
void even_odd();
void vowel_check();
void upper_lower();
void leap_year();
void num_type();
void income_tax();
void electricity_bill();
void triangle_validity();
void quadratic_roots();

int main() {
    int choice;

    while (1) {
        printf("\n======= MENU =======\n");
        printf("1. Largest between 2 numbers\n");
        printf("2. Check even or odd\n");
        printf("3. Check vowel or not\n");
        printf("4. Convert upper-case <-> lower-case\n");
        printf("5. Check leap year\n");
        printf("6. Number equal / positive / negative\n");
        printf("7. Calculate Income Tax\n");
        printf("8. Electricity Bill Calculation\n");
        printf("9. Check triangle validity\n");
        printf("10. Roots of quadratic equation\n");
        printf("11. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: largest_two(); break;
            case 2: even_odd(); break;
            case 3: vowel_check(); break;
            case 4: upper_lower(); break;
            case 5: leap_year(); break;
            case 6: num_type(); break;
            case 7: income_tax(); break;
            case 8: electricity_bill(); break;
            case 9: triangle_validity(); break;
            case 10: quadratic_roots(); break;
            case 11: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

void largest_two() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    if (a > b)
        printf("%d is larger\n", a);
    else if (b > a)
        printf("%d is larger\n", b);
    else
        printf("Both numbers are equal\n");
}

void even_odd() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n % 2 == 0)
        printf("Even\n");
    else
        printf("Odd\n");
}

void vowel_check() {
    char ch;
    printf("Enter a character: ");
    scanf(" %c", &ch);
    ch = tolower(ch);

    if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
        printf("Vowel\n");
    else
        printf("Not a vowel\n");
}

void upper_lower() {
    char ch;
    printf("Enter a character: ");
    scanf(" %c", &ch);

    if (islower(ch))
        printf("Uppercase = %c\n", toupper(ch));
    else if (isupper(ch))
        printf("Lowercase = %c\n", tolower(ch));
    else
        printf("Not an alphabet!\n");
}

void leap_year() {
    int y;
    printf("Enter year: ");
    scanf("%d", &y);

    if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
        printf("Leap year\n");
    else
        printf("Not a leap year\n");
}

void num_type() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    if (n == 0)
        printf("Number is Zero\n");
    else if (n > 0)
        printf("Positive\n");
    else
        printf("Negative\n");
}

void income_tax() {
    float inc, tax = 0;
    printf("Enter income: ");
    scanf("%f", &inc);

    if (inc <= 150000)
        tax = 0;
    else if (inc <= 300000)
        tax = (inc - 150000) * 0.10;
    else if (inc <= 500000)
        tax = 15000 + (inc - 300000) * 0.20;
    else
        tax = 55000 + (inc - 500000) * 0.30;

    printf("Income Tax = %.2f\n", tax);
}

void electricity_bill() {
    float units, amt;
    printf("Enter units consumed: ");
    scanf("%f", &units);

    if (units <= 100)
        amt = units * 3.20;
    else if (units <= 300)
        amt = 100 * 3.20 + (units - 100) * 5.40;
    else
        amt = 100 * 3.20 + 200 * 5.40 + (units - 300) * 6.10;

    printf("Electricity Bill = %.2f\n", amt);
}

void triangle_validity() {
    float a, b, c;

    printf("Enter 3 sides: ");
    scanf("%f %f %f", &a, &b, &c);

    if (a + b > c && a + c > b && b + c > a)
        printf("Valid Triangle\n");
    else
        printf("Not a Valid Triangle\n");
}

void quadratic_roots() {
    float a, b, c, d, r1, r2;

    printf("Enter a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);

    d = b*b - 4*a*c;

    if (d > 0) {
        r1 = (-b + sqrt(d)) / (2*a);
        r2 = (-b - sqrt(d)) / (2*a);
        printf("Real and distinct roots: %.2f , %.2f\n", r1, r2);
    }
    else if (d == 0) {
        r1 = -b / (2*a);
        printf("Real and equal roots: %.2f , %.2f\n", r1, r1);
    }
    else {
        float real = -b / (2*a);
        float img = sqrt(-d) / (2*a);
        printf("Complex roots: %.2f + %.2fi , %.2f - %.2fi\n", real, img, real, img);
    }
}
