/*  Program to implement Double Ended Queue and
 *  operations like insertion, deletion & display
 *  @Author: D. Kasi Pavan Kumar
 *  @Date: 11 September 2019 
 */

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define SIZE 64

int queue[SIZE];
int front = 0, rear = 0;

// Method for adding (enqueue) data to the front of queue
void enqueueFront(int dataItem) {
    // Check for overflow condition
    if(front == SIZE / 2) {
        printf("\nOverflow!");
        return;
    }

    // Update rear
    rear--;

    // Insert data at rear end
    queue[rear] = dataItem;
}

// Method for adding (enqueue) data to the rear of queue
void enqueueRear(int dataItem) {
    // Check for overflow condition
    if(front == SIZE / 2) {
        printf("\nOverflow!");
        return;
    }

    // Insert data at front end
    queue[front] = dataItem;
    
    // Update front
    front++;
}

// Method to delete data from rear of queue 
int dequeueRear() {
    int dequeuedItem;

    // Check for underflow condition
    if(front == rear) {
        printf("\nUnderflow!");
        return -1;
    }

    // Update front
    front--;

    // Delete element at the front end
    dequeuedItem = queue[front + 1];
    return dequeuedItem;
}

// Method to delete data from front of queue 
int dequeueFront() {
    int dequeuedItem;

    // Check for underflow condition
    if(front == rear) {
        printf("\nUnderflow!");
        return -1;
    }

    // Update rear
    rear++;

    // Delete element at the rear end
    dequeuedItem = queue[rear - 1];
    return dequeuedItem;
}

// Method to display data from the queue
void display() {
    int i;

    // Check for underflow
    if(front == rear) {
        printf("\nUnderflow!");
        return;
    }
    else {
        for(i = rear; i < front; ++i) {
            printf("%d ", queue[i]);
        }
    }
}

// Method to display menu
int displayMenu() {
    int choice = 0;
    printf("\nDOUBLE ENDED QUEUE");
    printf("\n1. Enqueue Front \n2. Enqueue Rear \n3. Dequeue Front \n4. Dequeue Rear \n5. Display \n6. Exit");
    printf("\nEnter your choice here > ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    // int queue[SIZE];
    // int front = 0, rear = 0;
    int dataItem = 0;
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
                enqueueFront(dataItem);
                printf("\nPress enter to continue.");
                getch();
                system("cls");
                break;

            case 2:
                // Taking data as input
                printf("\nEnter the data: ");
                scanf("%d", &dataItem);

                // Inserting data in the queue
                enqueueRear(dataItem);
                printf("\nPress enter to continue.");
                getch();
                system("cls");
                break;

            case 3:
                // Storing deleted data item to display
                deletedDataItem = dequeueFront();
                if(deletedDataItem != -1) {
                    printf("\n%d removed from the queue\n", deletedDataItem);
                }
                printf("\nPress enter to continue.");
                getch();
                system("cls");
                break;

            case 4:
                // Storing deleted data item to display
                deletedDataItem = dequeueRear();
                if(deletedDataItem != -1) {
                    printf("\n%d removed from the queue\n", deletedDataItem);
                }
                printf("\nPress enter to continue.");
                getch();
                system("cls");
                break;
                
            case 5:
                // Displaying elements from the queue
                display();
                printf("\nPress enter to continue.");
                getch();
                system("cls");
                break;
        }
    } while(choice != 6);

    getch();
    return 0;
}