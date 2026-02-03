#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *create()
{
    int n;
    struct node *newnode, *temp;

    printf("Enter how many nodes you want to create: ");
    scanf("%d", &n);

    if (n <= 0)
        return head;

    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Out of memory");
        return head;
    }

    head = newnode;
    printf("Enter data for node 1: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    temp = newnode;

    for (int i = 2; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("Out of memory");
            return head;
        }
        printf("Enter data for node %d: ", i);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
    }
    return head;
}

void traverse(struct node *head)
{
    int i = 1;
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    while (head != NULL)
    {
        printf("\nNode %d data: %d", i, head->data);
        head = head->next;
        i++;
    }
}

struct node *insertbeg(struct node *head)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Out of memory");
        return head;
    }
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    return newnode;
}

struct node *insertend(struct node *head)
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Out of memory");
        return head;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL)
        return newnode;

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    return head;
}

struct node *insertpos(struct node *head)
{
    int pos, count = 1;
    struct node *newnode, *temp, *prev = NULL;

    printf("Enter position: ");
    scanf("%d", &pos);

    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Out of memory");
        return head;
    }
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (pos == 1)
    {
        newnode->next = head;
        return newnode;
    }

    temp = head;
    while (temp != NULL && count < pos)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (prev == NULL)
    {
        printf("Invalid position");
        free(newnode);
        return head;
    }

    prev->next = newnode;
    newnode->next = temp;
    return head;
}

struct node *deletfirst(struct node *head)
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty");
        return head;
    }
    temp = head;
    head = head->next;
    printf("Deleted data: %d", temp->data);
    free(temp);
    return head;
}


struct node *deletend(struct node *head)
{
    struct node *temp, *prev = NULL;

    if (head == NULL)
    {
        printf("List is empty");
        return head;
    }

    if (head->next == NULL)
    {
        printf("Deleted data: %d", head->data);
        free(head);
        return NULL;
    }

    temp = head;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    printf("Deleted data: %d", temp->data);
    free(temp);
    return head;
}


struct node *deletpos(struct node *head)
{
    int pos, count = 1;
    struct node *temp, *prev = NULL;

    if (head == NULL)
    {
        printf("List is empty");
        return head;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1)
        return deletfirst(head);

    temp = head;
    while (temp != NULL && count < pos)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        printf("Invalid position");
        return head;
    }

    prev->next = temp->next;
    printf("Deleted data: %d", temp->data);
    free(temp);
    return head;
}

void sort(struct node *head)
{
    int temp;
    struct node *i, *j;

    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted");
}


void search(struct node *head)
{
    int key, pos = 1;
    printf("Enter element to search: ");
    scanf("%d", &key);

    while (head != NULL)
    {
        if (head->data == key)
        {
            printf("Element found at position %d", pos);
            return;
        }
        head = head->next;
        pos++;
    }
    printf("Element not found");
}


struct node *reverse(struct node *head)
{
    struct node *prev = NULL, *curr = head, *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    printf("List reversed");
    return prev;
}

struct node* merge(struct node* l1, struct node* l2)
{
    if (l1 == NULL) 
	    return l2;   
    if (l2 == NULL) 
	    return l1;   
    struct node* temp = l1;
    while (temp->next != NULL)
	    temp = temp->next;
    temp->next = l2;
    return l1;
}


int main()
{
    struct node *head1 = NULL, *head2 = NULL, *merged = NULL;
    int choice;
    while (1)
    {
        printf("\n\n--- SINGLE LINKED LIST MENU ---\n");
        printf("1. Exit\n2. Create\n3. Traverse\n4. Insert Begin\n");
        printf("5. Insert End\n6. Insert Position\n7. Delete Begin\n");
        printf("8. Delete End\n9. Delete Position\n10. Sort\n");
        printf("11. Search\n12. Reverse\n13. Merge\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: 
		printf("\nThe Program was  Ended. Thankyou!\n");
		exit(0);
        case 2: 
		head = create(); 
		break;
        case 3: 
		traverse(head); 
		break;
        case 4: 
		head = insertbeg(head); 
		break;
        case 5: 
		head = insertend(head); 
		break;
        case 6: 
		head = insertpos(head); 
		break;
        case 7: 
		head = deletfirst(head); 
		break;
        case 8: 
		head = deletend(head); 
		break;
        case 9: 
		head = deletpos(head); 
		break;
        case 10:
	        sort(head); 
		break;
        case 11: 
		search(head); 
		break;
        case 12: 
		head = reverse(head); 
		break;
	case 13: 
    		printf("Create firstlist:\n");
    		head1 = create();

    		printf("\nCreate secondlist:\n");
    		head2 = create();

    		merged = merge(head1, head2);
    		printf("\nList got Merged\n");
		traverse(merged);
    		break;

        default: printf("Invalid choice\n");
        }
    }
}
