#include<stdio.h>
#include<math.h>

void area_circle(){
    float r;
    printf("Enter radius:");
    scanf("%d",&r);
    printf("Area = %.2f\n",3.14*r*r);
}

void area_tri() {
    float a, b, c, s, area;
    printf("Enter 3 sides: ");
    scanf("%f %f %f", &a, &b, &c);
    s = (a + b + c) / 2;
    area = sqrt(s * (s - a) * (s - b) * (s - c));
    printf("Area = %.2f\n", area);
}

void area_rec() {
    float l, w;
    printf("Enter length & width: ");
    scanf("%f %f", &l, &w);
    printf("Area = %.2f\n", l * w);
}

void sum_n() {
    int n, sum = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    sum = n * (n + 1) / 2;
    printf("Sum = %d\n", sum);
}

void swap_num() {
    int a, b, temp;
    printf("Enter a & b: ");
    scanf("%d %d", &a, &b);
    temp = a; 
    a = b;
    b = temp;
    printf("After swap: a=%d b=%d\n", a, b);
}

void swap_without_vr() {
    int a, b;
    printf("Enter a & b: ");
    scanf("%d %d", &a, &b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("After swap: a=%d b=%d\n", a, b);
}

void sum_of_3digit() {
    int num, sum=0;
    printf("Enter 3-digit number: ");
    scanf("%d", &num);
    sum = num/100 + (num/10)%10 + num%10;
    printf("Sum of digits = %d\n", sum);
}

void interest() {
    float p, r, t;
    printf("Enter principal, rate, time: ");
    scanf("%f %f %f", &p, &r, &t);
    printf("Simple Interest = %.2f\n", (p*r*t)/100);
}

void tempreture() {
    float f, c;
    printf("Enter Fahrenheit: ");
    scanf("%f", &f);
    c = (f - 32) * 5/9;
    printf("Celsius = %.2f\n", c);

    printf("Enter Celsius: ");
    scanf("%f", &c);
    f = (c * 9/5) + 32;
    printf("Fahrenheit = %.2f\n", f);
}

void avg_mark() {
    int m[5][3], i, j;
    float avg;
    for (i = 0; i < 5; i++) {
        printf("Enter 3 marks for student %d: ", i+1);
        for (j = 0; j < 3; j++) scanf("%d", &m[i][j]);
    }

    for (i = 0; i < 5; i++) {
        avg = (m[i][0] + m[i][1] + m[i][2]) / 3.0;
        printf("Average of student %d = %.2f\n", i+1, avg);
    }
}

void convert_seconds() {
    int sec, h, m;
    printf("Enter seconds: ");
    scanf("%d", &sec);
    h = sec / 3600;
    sec %= 3600;
    m = sec / 60;
    sec %= 60;
    printf("%d hr %d min %d sec\n", h, m, sec);
}

void meter_km() {
    float m;
    printf("Enter meter: ");
    scanf("%f", &m);
    printf("Kilometer = %.2f\n", m / 1000);
}

void largest() {
    int a, b, c;
    printf("Enter 3 numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a >= b && a >= c)
        printf("%d is largest\n", a);
    else if (b >= a && b >= c)
        printf("%d is largest\n", b);
    else
        printf("%d is largest\n", c);
}

void largest_con_opr() {
    int a, b, c, largest;
    printf("Enter 3 numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    largest = (a>b && a>c) ? a : (b>c ? b : c);
    printf("Largest = %d\n", largest);
}

void distance_point() {
    float x1, y1, x2, y2, d;
    printf("Enter x1 y1: ");
    scanf("%f %f", &x1, &y1);
    printf("Enter x2 y2: ");
    scanf("%f %f", &x2, &y2);

    d = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    printf("Distance = %.2f\n", d);
}

int main()
{
    int chioce;
    while (1)
    {
        printf("\n--menu--\n");
        printf("1.are of circle\n");
        printf("2.area of triangle\n");
        printf("3.area of rectangle\n");
        printf("4.sum up to n number\n");
        printf("5.swap using 3rd var\n");
        printf("6.swap withput using 3rd var\n");
        printf("7.sum of digits(3)\n");
        printf("8.simple interest\n");
        printf("9.fah to cel & cel to fah\n");
        printf("10.avg mark of 5 student(3 sub)\n");
        printf("11.convert sec to hr:min:sec\n");
        printf("12.convert meter to km\n");
        printf("13.largest among 3\n");
        printf("14.largest among 3(con opr)\n");
        printf("15.Distence b/w (x1,y1) & (x2,y2)\n");
        printf("16.Exit\n");

        printf("\nEnter choice:");
        scanf("%d",&chioce);
        switch(chioce){
            case 1: area_circle(); break;
            case 2: area_tri(); break;
            case 3: area_rec(); break;
            case 4: sum_n(); break;
            case 5: swap_num(); break;
            case 6: swap_without_vr(); break;
            case 7: sum_of_3digit(); break;
            case 8: interest(); break;
            case 9: tempreture(); break;
            case 10: avg_mark(); break;
            case 11: convert_seconds(); break;
            case 12: meter_km(); break;
            case 13: largest(); break;
            case 14: largest_con_opr(); break;
            case 15: distance_point(); break;
            case 16: return 0; break;
            default: printf("invalid choice!\n");
        }
    }
    
}