/**
 * Program to implement the following sorting & searching techniques:
 * Quick Sort
 * Merge Sort
 * Binary Search
 * 
 * @author D. Kasi Pavan Kumar
 * @date 21 September 2019
 * @version 1.0
 */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// -------------------------- BINARY SEARCH ----------------------------
int BinarySearch(int array[], int leftMostPosition, int rightMostPosition, int elementToBeSearched) {
    if(rightMostPosition >= leftMostPosition) {
        int middle = leftMostPosition + (rightMostPosition - 1) / 2;

        if(array[middle] == elementToBeSearched) {
            return middle;
        }

        if(array[middle] > elementToBeSearched) {
            return(BinarySearch(array, leftMostPosition, middle - 1, elementToBeSearched));
        }
        else {
            return(BinarySearch(array, middle + 1, rightMostPosition, elementToBeSearched));
        }
    }
    return -1;
}
// ------------------------------------------------------------------

// -------------------------- QUICK SORT ----------------------------
void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    int j;

    for(j = low; j <= high - 1; ++j) {
        if(array[j] < pivot) {
            ++i;
            Swap(&array[i], &array[j]);
        }
    }

    Swap(&array[i + 1], &array[j]);
    return(i + 1);
}

void QuickSort(int array[], int low, int high) {
    if(low < high) {
        int partitionIndex = Partition(array, low, high);

        QuickSort(array, low, partitionIndex - 1);
        QuickSort(array, partitionIndex + 1, high);
    }
}
// ------------------------------------------------------------------

// -------------------------- MERGE SORT ----------------------------
void MergeArray(int array[], int left, int middle, int right) {
    int i, j, k;
    int leftHalf = middle - left + 1;
    int rightHalf = right - middle;

    int leftTempArray[leftHalf], rightTempArray[rightHalf];

    for(i = 0; i < leftHalf; ++i) {
        leftTempArray[i] = array[left + i];
    }

    for(j = 0; j < rightHalf; ++j) {
        rightTempArray[j] = array[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while(i < leftHalf && j < rightHalf) {
        if(leftTempArray[i] <= rightTempArray[j]) {
            array[k] = leftTempArray[i];
            ++i;
        }
        else {
            array[k] = rightTempArray[j];
            ++j;
        }
        ++k;
    }

    while(i < leftHalf) {
        array[k] = leftTempArray[i];
        ++i; ++k;
    }

    while(j < rightHalf) {
        array[k] = rightTempArray[j];
        ++j; ++k;
    }
}

void MergeSort(int array[], int left, int right) {
    if(left < right) {
        int middle = left + (right - left) / 2;

        MergeSort(array, left, middle);
        MergeSort(array, middle + 1, right);

        MergeArray(array, left, middle, right);
    }
}
// ------------------------------------------------------------------

// Method to display array elements
void ShowArray(int array[], int arraySize) {
    int i;
    for(i = 0; i < arraySize; ++i) {
        printf("%d ", array[i]);
    }
}

// Method to display menu
int DisplayMenu() {
    printf("\n1. Binary Search \n2. Quick Sort \n3. Merge sort \n4. Exit");
    printf("\nEnter choice: ");
    int choice; scanf("%d", &choice);
    return(choice);
}

int main() {
    int array[64];
    int arraySize;
    int elementToBeSearched;
    int choice;

    printf("SEARCH / SORT\n");
    printf("\nWhat will be the size of our array? \n> ");
    scanf("%d", &arraySize);

    printf("\nType the elements to be inserted in the array: \n> ");
    for(int i = 0; i < arraySize; ++i) {
        scanf("%d", &array[i]);
    }

    printf("\nSelect the operation:\n");

    do {
        choice = DisplayMenu();
        switch(choice) {
            case 1:
                printf("\nEnter element to be searched: ");
                scanf("%d", &elementToBeSearched);

                int elementIndex = BinarySearch(array, 0, arraySize - 1, elementToBeSearched);

                elementIndex == -1 ? printf("\n%d not found in the array!\n", elementToBeSearched) : printf("\n%d found at %d index\n", elementToBeSearched, elementIndex);
                
                printf("\n\nPress enter to continue > ");
                getch();
                system("cls");
                break;

            case 2:
                QuickSort(array, 0, arraySize - 1);
                printf("\nArray after quick sort is: ");
                ShowArray(array, arraySize);

                printf("\n\nPress enter to continue > ");
                getch();
                system("cls");
                break;

            case 3:
                MergeSort(array, 0, arraySize - 1);
                printf("\nArray after merge sort is: ");
                ShowArray(array, arraySize);

                printf("\n\nPress enter to continue > ");
                getch();
                system("cls");
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    } while(choice > 0 && choice <= 4);
    getch();
    return 0;
} // [END OF PROGRAM]