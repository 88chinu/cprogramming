#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* create(struct node *head) {

}

struct node* insertBeg(struct node *head) {

}

struct node* insertEnd(struct node *head) {

}

struct node* insertPos(struct node *head) {

}

struct node* deleteBeg(struct node *head) {

}

struct node* deleteEnd(struct node *head) {

}

struct node* deletePos(struct node *head) {

}

struct node* display(struct node *head) {

}

struct node* search(struct node *head) {

}

struct node* merge(struct node *head, struct node *head2) {

}

int main(){
    struct node *head = NULL,*head2 = NULL;
    int choice;

    while(1){
        printf("\n\n----- SINGLE LINKED LIST MENU -----\n");
        printf("\n1. Create List");
        printf("\n2. Insert at Beginning");
        printf("\n3. Insert at End");
        printf("\n4. Insert at Any Position");
        printf("\n5. Delete from Beginning");
        printf("\n6. Delete from End");
        printf("\n7. Delete from Any Position");
        printf("\n8. Display List");
        printf("\n9. Search Element");
        printf("\n10. Merge Another List");
        printf("\n11. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                head = create(head);
                break;

            case 2:
                head = insertBeg(head);
                break;

            case 3:
                head = insertEnd(head);
                break;

            case 4:
                head = insertPos(head);
                break;
            
            case 5:
                head = deleteBeg(head);
                break;
            
            case 6:
                head = deleteEnd(head);
                break;

            case 7:
                head = deletePos(head);
                break;

            case 8:
                head = display(head);
                break;

            case 9:
                head = search(head);
                break;

            case 10:
                head = merge(head,head2);
                break;

            case 11:
                exit(0);

            default:
                printf("Invalid choice");
                break;
        }
    }
}
