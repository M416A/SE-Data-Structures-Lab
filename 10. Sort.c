/**
 * Program to implement the following sorting techniques:
 * Bubble Sort
 * Selection Sort
 * Insertion Sort
 * 
 * @author D. Kasi Pavan Kumar
 * @date 21 September 2019
 * @version 1.0
 */

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

// Method which swaps two elements by reference
void SwapElements(int *one, int *two) {
    int buffer = *one;
    *one = *two;
    *two = buffer;
}

// Method to perform bubble sort
void BubbleSort(int array[], int arraySize) {
    int isSwapped;
    int i, j;

    for(i = 0; i < arraySize; ++i) {
        isSwapped = 0;
        for(j = i + 1; j < arraySize; ++j) {
            if(array[j] < array[i]) {
                SwapElements(&array[i], &array[j]);
                isSwapped = 1;
            }
        }
    }

    if(isSwapped == 0) {
        return;
    }
}

// Method to perform selection sort
void SelectionSort(int array[], int arraySize) {
    int i, j;
    int smallestElementIndex;

    for(i = 0; i < arraySize - 1; ++i) {
        smallestElementIndex = i;

        for(j = i + 1; j < arraySize; ++j) {
            if(array[j] < array[smallestElementIndex]) {
                smallestElementIndex = j;

                int key = array[smallestElementIndex];

                while(smallestElementIndex > i) {
                    array[smallestElementIndex] = array[smallestElementIndex - 1];
                    --smallestElementIndex;
                }

                array[i] = key;
            }
        }
    }
}

// Method to perform insertion sort
void InsertionSort(int array[], int arraySize) {
    int i, j;
    int key;

    for(i = 1; i < arraySize; ++i) {
        key = array[i];
        j = i - 1;

        while(j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

// Method to display the array contents
void DisplayArray(int array[], int arraySize) {
    int i;
    for(i = 0; i < arraySize; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Method to display menu
int DisplayMenu() {
    printf("\nMENU");
    printf("\n\n1. Bubble Sort \n2. Selection Sort \n3. Insertion Sort \n4. Exit \nType your choice > ");
    int choice; scanf("%d", &choice);
    return(choice);
}

int main() {
    int array[64];
    int arraySize;
    int choice;

    printf("ARRAY SORTING\n");
    printf("\nWhat will be the size of our array? \n> ");
    scanf("%d", &arraySize);

    printf("\nType the elements to be inserted in the array: \n> ");
    for(int i = 0; i < arraySize; ++i) {
        scanf("%d", &array[i]);
    }

    do {
        choice = DisplayMenu();
        switch(choice) {
            case 1:
                BubbleSort(array, arraySize);
                printf("\nAfter Bubble Sort: ");
                DisplayArray(array, arraySize);

                printf("\nPress enter to continue > ");
                getch();
                break;
            
            case 2:
                SelectionSort(array, arraySize);
                printf("\nAfter Selection Sort: ");
                DisplayArray(array, arraySize);

                printf("\nPress enter to continue > ");
                getch();
                break;
            
            case 3:
                InsertionSort(array, arraySize);
                printf("\nAfter Insertion Sort: ");
                DisplayArray(array, arraySize);

                printf("\nPress enter to continue > ");
                getch();
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice!");
        }
    } while(choice > 0 && choice <= 4);
    getch();
    return 0;
}