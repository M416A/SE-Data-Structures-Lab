// Program to implement double linked list
// @Author: D. Kasi Pavan Kumar
// @Date: 15 September 2019

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Node {
    int data; // Data part
    struct Node *next; // Next node's address
    struct Node *previous; // Previous node's address
};

void InsertAtFront(struct Node **first, int data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = *first;
    newNode -> previous = NULL;

    if((*first) != NULL) {
        (*first) -> previous = newNode;
    }

    (*first) = newNode;
}

void InsertAtEnd(struct Node **first, int data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *first;

    newNode -> data = data;
    newNode -> next = NULL;

    if(*first == NULL) {
        newNode -> previous = NULL;
        *first = newNode;
        return;
    }
    else {
        while(last -> next != NULL) {
            last = last -> next;
        }

        last -> next = newNode;
        newNode -> previous = last;
    }
}

void InsertAfterGivenNode(struct Node *previous, int data) {
    if(previous == NULL) {
        printf("\nPrevious cannot be empty!");
        return;
    }
    else {
        struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode -> data = data;
        newNode -> next = previous -> next;
        previous -> next = newNode;
        newNode -> previous = previous;

        if(newNode -> next != NULL) {
            newNode -> next -> previous = newNode;
        }
    }
}

void DeleteNodeFromFront(struct Node **first) {
    if((*first) == NULL) {
        printf("Underflow!");
        return;
    }
    else {
        struct Node *temp = *first;
        (*first) = temp -> next;
        (*first) -> previous = NULL;
        free(temp);
    }
}

void DeleteNodeFromEnd(struct Node **first) {
    if((*first) == NULL) {
        printf("Underflow!");
        return;
    }
    else {
        struct Node *temp = (*first);

        while(temp -> next -> next != NULL) {
            temp = temp -> next;
        }

        struct Node *buffer = temp -> next;
        temp -> next = NULL;
        free(buffer);

    }
}

void DisplayLinkedList(struct Node *node) {
    struct Node *last;

    printf("\nForward traversal is: ");
    while(node != NULL) {
        printf("%d ", node -> data);
        last = node;
        node = node -> next;
    }

    printf("\nBackward traversal is: ");
    while(last != NULL) {
        printf("%d ", last -> data);
        last = last -> previous;
    }

    printf("\n");
}

// Method to display menu
int DisplayMenu() {
    system("cls");
    printf("DOUBLE LINKED LIST");
    printf("\n1. Insert At Front \n2. Insert At End \n3. Insert After Given Node");
    printf("\n4. Delete From Front \n5. Delete From End \n6. Display \n7. Exit");
    printf("\nEnter your choice > ");
    int choice; scanf("%d", &choice);
    return choice;
}

// Method to take data as input
int GetData() {
    int data;
    printf("\nEnter the data: ");
    scanf("%d", &data);
    return data;
}

int main() {
    struct Node *first = NULL;
    int choice;
    int data;

    do {
        choice = DisplayMenu();
        switch(choice) {
            case 1:
                data = GetData();
                InsertAtFront(&first, data);
                printf("\nPress enter to continue \n> ");
                getch();
                break;
            case 2:
                data = GetData();
                InsertAtEnd(&first, data);
                printf("\nPress enter to continue \n> ");
                getch();
                break;
            case 3:
                data = GetData();
                InsertAfterGivenNode(first -> next, data);
                printf("\nPress enter to continue \n> ");
                getch();
                break;
            case 4:
                DeleteNodeFromFront(&first);
                printf("\nPress enter to continue \n> ");
                getch();
                break;
            case 5:
                DeleteNodeFromEnd(&first);
                printf("\nPress enter to continue \n> ");
                getch();
                break;
            case 6:
                DisplayLinkedList(first);
                printf("\nPress enter to continue \n> ");
                getch();
                break;
            case 7:
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    } while(choice > 0 && choice <= 7);
    
    getch();
    return 0;
}