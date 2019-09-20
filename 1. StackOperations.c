/*
    This program performs following operations on array based stack:
        > PUSH
        > POP
        > PEEK
        > DISPLAY
    
    AUTHOR:
    Name: D. Kasi Pavan Kumar
    Roll No: C61
    ID: TUS3F181972 
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 16

// This method pushes (insert) data item into stack
int PUSH(int dataItem, int stack[], int *top) {
    if(*top == SIZE - 1) { printf("\n\nOverflow!"); return -1; }
    *top += 1;
    stack[*top] = dataItem;
    return dataItem;
}

// This method pops (delete) data item into stack
int POP(int stack[], int *top) {
    if(*top == -1) { printf("\n\nUnderflow!"); return -1; }
    int value = stack[*top];
    *top -= 1;
    return value;
}

// This method returns element at top of the stack
int PEEK(int stack[], int *top) {
    if(*top == -1) { printf("\n\nUnderflow!"); return -1; }
    return stack[*top];
}

// This method displays the stack's content
int DISPLAY(int stack[], int *top) {
    if(*top == -1) { printf("\n\nUnderflow!"); return -1; }
    printf("\nStack contains the following elements:\n");
    printf("%d < top \n", stack[*top]);
    for(int A = *top - 1; A >= 0; --A) { printf("%d\n", stack[A]); }
}

int main() {
    int stack[SIZE], dataItem, top, choice, pushChoice, popData, peekData;
    top = -1; 
    pushChoice = choice = popData = peekData = 0;

    MENU:   // MENU REDIRECT POINT

    system("cls");
    printf("\t\t\t\tSTACK OPERATIONS \n\n1. Push \n2. Pop \n3. Peek \n4. Display \n5. Exit \n\n> ");
    scanf("%d", &choice);

    switch(choice) {
        /* This case will get executed when user enters '1' as choice
            and will invoke PUSH() method to insert data in stack */
        case 1:
            system("cls");
            printf("\t\t\t\tPUSH OPERATION");
            do {
                printf("\nEnter data to be inserted > ");
                scanf("%d", &dataItem);
                PUSH(dataItem, stack, &top);
                printf("\n\n1. Add another data item \n2. Go back to menu \n\n> ");
                scanf("%d", &pushChoice);
            } while(pushChoice == 1);
            goto MENU;

        /* This case will get executed when user enters '2' as choice
            and will invoke POP() method to delete top most element from stack */
        case 2:
            system("cls");
            printf("\t\t\t\tPOP OPERATION");
            popData = POP(stack, &top);
            if(popData == -1) {
                printf("\n\nPress enter for menu \n\n> ");
                getch();
                goto MENU;
            }
            printf("\n%d popped from the stack", popData);
            printf("\nPress enter for menu \n\n> ");
            getch();
            goto MENU;

        /* This case will get executed when user enters '3' as choice
            and will invoke PEEK() method to get the top most element from the stack */
        case 3:
            system("cls");
            printf("\t\t\t\tPEEK OPERATION");
            peekData = PEEK(stack, &top);
            if(peekData == -1) {
                printf("\n\nPress enter for menu \n\n> ");
                getch();
                goto MENU;
            }
            printf("\nTop = %d", peekData);
            printf("\n\nPress enter for menu \n\n> ");
            getch();
            goto MENU;

        /* This case will get executed when user enters '4' as choice
            and will invoke DISPLAY() method to display stack content */
        case 4:
            system("cls");
            printf("\t\t\t\tDISPLAY OPERATION");
            DISPLAY(stack, &top);
            printf("\n\nPress enter for menu \n\n> ");
            getch();
            goto MENU;

        /* This case will get executed when user enters '5' as choice
            and will invoke exit() method to terminate the program */
        case 5:
            printf("\n\nClosing the program...");
            exit(1);
    }

    getch();
    return 0;
}
