/* 
    Program to implement circular queue and perform the following operations:
        - Insertion (Enqueue)
        - Deletion (Dequeue)
        - Display
    @Author: D. Kasi Pavan Kumar
    @Date: 07 September 2019 
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define SIZE 64

// Method to insert (enqueue) elements in the queue
void enqueue(int *front, int *rear, int Queue[], int dataItem) {
    // Check if queue is full
    if((*rear == SIZE && *front == 0) || (*front == *rear + 1)) {
        printf("Overflow!");
        return;
    }
    // If there is memory to add more elements
    else {
        if(*rear == SIZE - 1 && *front != 0) {
            *rear = -1;
        }
        else {
            *rear = *rear + 1;
            Queue[*rear] = dataItem;
            
            if(*front == -1)
                *front = 0; 
        }
    }
}

// Method to delete elements from the queue
int dequeue(int *front, int *rear, int Queue[]) {
    // Check if queue is empty
    if(*front == -1) {
        printf("\nUnderflow, Queue is empty!");
        return -1;
    }

    int dataItem = Queue[*front];
    Queue[*front] = -1;

    if(*front == *rear) {
        *front = *rear = -1;
    }
    else if(*front == SIZE - 1) {
        *front = 0;
    }
    else {
        *front++;
    }

    return dataItem;
}

// Method to display elements from the queue
void displayQueue(int *front, int *rear, int Queue[]) {
    // Check if queue is empty
    if(*front == -1) {
        printf("Underflow!");
        return;
    }
    else {
        int i;
        printf("\nQueue contains the following elements:\n");
        if(*front <= *rear) {
            for(i = *front; i <= *rear; ++i) {
                printf("%d ", Queue[i]);
            }
        }
        else {
            int i;
            for(i = *front; i < SIZE; ++i) {
                printf("%d ", Queue[i]);
            }

            for(i = 0; i <= *rear; ++i) {
                printf("%d ", Queue[i]);
            }
        }
    }
    printf("\n");
}

// Method to display menu
int displayMenu() {
    int choice = 0;
    printf("\nCIRCULAR QUEUE");
    printf("\n1. Enqueue \n2. Dequeue \n3. Display \n4. Exit");
    printf("\nEnter your choice here > ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    int Queue[SIZE]; // Queue
    int front = -1, rear = -1; // Initial values of Front & Rear
    int dataItem; // Data item
    int deletedDataItem = 0;
    int choice = 0;

    do {
        choice = displayMenu();
        switch(choice) {
            case 1:
                // Taking data as input
                printf("\nEnter the data: ");
                scanf("%d", &dataItem);

                // Inserting data in the queue
                enqueue(&front, &rear, Queue, dataItem);
                printf("\nPress enter to continue.");
                getch();
                system("cls");
                break;

            case 2:
                // Storing deleted data item to display
                deletedDataItem = dequeue(&front, &rear, Queue);
                if(deletedDataItem != -1) {
                    printf("\n%d removed from the queue\n", deletedDataItem);
                }
                printf("\nPress enter to continue.");
                getch();
                system("cls");
                break;
                
            case 3:
                // Displaying elements from the queue
                displayQueue(&front, &rear, Queue);
                printf("\nPress enter to continue.");
                getch();
                system("cls");
                break;
        }
    } while(choice != 4);
    
    getch();
    return 0;
} // [END OF PROGRAM]