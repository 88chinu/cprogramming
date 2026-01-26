#include <stdio.h>

void inputArray(int a[], int n) {
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void printArray(int a[], int n) {
    printf("Array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {

    int a[100], b[100], c[200];
    int n, m, pos, val, i, j, choice;

    printf("Enter size of array: ");
    scanf("%d", &n);
    inputArray(a, n);

    do {
        printf("\n=========== ARRAY MENU ===========\n");
        printf("1. Interchange largest and smallest element\n");
        printf("2. Insert element at any position\n");
        printf("3. Delete element from any position\n");
        printf("4. Linear Search\n");
        printf("5. Bubble Sort\n");
        printf("6. Reverse Array\n");
        printf("7. Merge Two Arrays\n");
        printf("8. Find Second Largest Element\n");
        printf("9. Check Duplicate Elements\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1: {
                int max = a[0], min = a[0];
                int maxIndex = 0, minIndex = 0;

                for(i = 1; i < n; i++) {
                    if(a[i] > max)  { max = a[i]; maxIndex = i; }
                    if(a[i] < min)  { min = a[i]; minIndex = i; }
                }

                // swap
                int temp = a[maxIndex];
                a[maxIndex] = a[minIndex];
                a[minIndex] = temp;

                printf("After interchanging largest and smallest:\n");
                printArray(a, n);
                break;
            }

            case 2: {
                printf("Enter position (0 to %d): ", n);
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &val);

                for(i = n; i > pos; i--)
                    a[i] = a[i - 1];

                a[pos] = val;
                n++;

                printf("After insertion:\n");
                printArray(a, n);
                break;
            }

            case 3: {
                printf("Enter position to delete (0 to %d): ", n - 1);
                scanf("%d", &pos);

                for(i = pos; i < n - 1; i++)
                    a[i] = a[i + 1];

                n--;

                printf("After deletion:\n");
                printArray(a, n);
                break;
            }

            case 4: {
                printf("Enter value to search: ");
                scanf("%d", &val);

                int found = 0;
                for(i = 0; i < n; i++) {
                    if(a[i] == val) {
                        printf("Element found at position %d\n", i);
                        found = 1;
                        break;
                    }
                }
                if(!found) printf("Element not found\n");
                break;
            }

            case 5: {
                for(i = 0; i < n - 1; i++) {
                    for(j = 0; j < n - i - 1; j++) {
                        if(a[j] > a[j + 1]) {
                            int temp = a[j];
                            a[j] = a[j + 1];
                            a[j + 1] = temp;
                        }
                    }
                }
                printf("After Bubble Sort:\n");
                printArray(a, n);
                break;
            }

            case 6: {
                for(i = 0, j = n - 1; i < j; i++, j--) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
                printf("Array reversed:\n");
                printArray(a, n);
                break;
            }

            case 7: {
                printf("Enter size of second array: ");
                scanf("%d", &m);
                inputArray(b, m);

                for(i = 0; i < n; i++)
                    c[i] = a[i];

                for(j = 0; j < m; j++)
                    c[n + j] = b[j];

                printf("Merged Array:\n");
                printArray(c, n + m);
                break;
            }

            case 8: {
                int max1 = -99999, max2 = -99999;

                for(i = 0; i < n; i++) {
                    if(a[i] > max1) {
                        max2 = max1;
                        max1 = a[i];
                    }
                    else if(a[i] > max2 && a[i] != max1) {
                        max2 = a[i];
                    }
                }

                printf("Second Largest Element = %d\n", max2);
                break;
            }

            case 9: {
                int dup = 0;
                for(i = 0; i < n; i++) {
                    for(j = i + 1; j < n; j++) {
                        if(a[i] == a[j]) {
                            dup = 1;
                            break;
                        }
                    }
                }
                if(dup) 
                    printf("Duplicate elements exist in the array\n");
                else
                    printf("No duplicate elements\n");
                break;
            }

            case 10:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 10);

    return 0;
}