#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int power;
    struct node *next;
};

struct node *head = NULL;

struct node *create()
{
    int n;
    struct node *newnode, *temp;

    printf("Enter number of terms: ");
    scanf("%d", &n);
    int t = n;
    for (int i = 0; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("Memory allocation failed");
            return head;
        }

        printf("Enter coefficient of term %d: ", t);
        scanf("%d", &newnode->coeff);

        printf("Enter power of term %d: ", t);
        scanf("%d", &newnode->power);
        t--;

        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("Polynomial is empty");
        return;
    }

    printf("Polynomial: ");

    while (head != NULL)
    {
        /* Printing term */
        if (head->power == 0)
            printf("%d", head->coeff);
        else if (head->power == 1)
            printf("%dx", head->coeff);
        else
            printf("%dx^%d", head->coeff, head->power);

        /* Print + ONLY if next node exists */
        if (head->next != NULL)
            printf(" + ");

        head = head->next;
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n\n--- POLYNOMIAL USING LINKED LIST ---\n");
        printf("1. Create Polynomial\n");
        printf("2. Display Polynomial\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = create();
            break;

        case 2:
            display(head);
            break;

        case 3:
            printf("ThankYou! The program Ended");
            exit(0);

        default:
            printf("Invalid choice");
        }
    }
}
