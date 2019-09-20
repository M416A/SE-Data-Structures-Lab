// Program to implement single linked list & perform operations like
// insertion, deletion, searching & display
// @Author: D. Kasi Pavan Kumar
// @Date: 15 September 2019

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node {
    int data; // Data part
    struct Node *next; // Address part
};

// Method to insert data node at front of the list
void InsertAtFront(struct Node **first, int data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = *first;
    *first = newNode;   
}

// Method to delete data node at front of the list
void DeleteAtFront(struct Node **first) {
    if(*first == NULL) {
        return;
    }
    else {
        struct Node *temp = *first;
        *first = temp -> next;
        free(temp);
    }
}

// Method to insert data node at end of the list
void InsertAtEnd(struct Node **first, int data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    struct Node *temp = *first;
    newNode -> data = data;
    newNode -> next = NULL;

    if(first == NULL) {
        *first = newNode;
        return;
    }
    else {
        while(temp -> next != NULL) {
            temp = temp -> next;
        }

        temp -> next = newNode;
    }
}

// Method to delete data node from end of the list
void DeleteAtEnd(struct Node **first) {
    if(*first == NULL) {
        printf("Underflow!");
        return;
    }
    else {
        struct Node *temp = *first;
        while(temp -> next -> next != NULL) {
            temp = temp -> next;
        }
        struct Node *buffer = temp -> next;
        temp -> next = NULL;
        free(buffer);

    }
}

// Method to delete data node after a given node
void InsertAfterGivenNode(struct Node *previousNode, int data) {
    if(previousNode == NULL) {
        return;
    }
    else {
        struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode -> data = data;
        newNode -> next = previousNode -> next;
        previousNode -> next = newNode;
    }
}

// Method to display data from the list 
void Display(struct Node *node) {
    printf("\nList contains the following data:\n");
    while(node != NULL) {
        printf("%d > ", node -> data);
        node = node -> next;
    }
    printf("\n");
}

// Method to display menu
int DisplayMenu() {
    system("cls");
    printf("SINGLE LINKED LIST");
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
                DeleteAtFront(&first);
                printf("\nPress enter to continue \n> ");
                getch();
                break;
            case 5:
                DeleteAtEnd(&first);
                printf("\nPress enter to continue \n> ");
                getch();
                break;
            case 6:
                Display(first);
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
} // [END OF PROGRAM]