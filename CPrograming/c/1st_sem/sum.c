#include<stdio.h>
int sum(int a, int b) {
    return a + b;
}
int main() {
    int x ,y;
    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);
    printf("Sum of %d and %d is %d\n", x, y, sum(x, y));
    return 0;
}