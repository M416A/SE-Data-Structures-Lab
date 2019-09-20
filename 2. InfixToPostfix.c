// Program to convert infix expresssion to postfix expression
// @Author: D. Kasi Pavan Kumar
// @Date: 08 September 2019

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define SIZE 64

char stack[SIZE];
int top = -1;

// Method to push element in stack
void push(char dataItem) {
    // Check if stack is full
    if(top >= SIZE - 1) {
        printf("\nStack overflow!");
    } 
    else {
        top += 1;
        stack[top] = dataItem;
    }
}

// Method to remove element from stack
char pop() {
    char dataItem;
    // Check if stack is empty
    if(top < 0) {
        printf("\nStack underflow");
        getchar(); exit(1);
    }
    else {
        dataItem = stack[top];
        top -= 1;
        return(dataItem);
    }
}

// Method to check if the symbol is operator or not
int isOperator(char symbol) {
    if(symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^') {
        return(1);
    }
    else {
        return(0);
    }
}

// Method to check the precedence of the operator
int precedence(char symbol) {
    if(symbol == '^') {
        return(3);
    }
    else if(symbol == '*' || symbol == '/') {
        return(2);
    }
    else if(symbol == '+' || symbol == '-') {
        return(1);
    }
    else {
        return(0);
    }
}

// Method to convert infix expression to postfix expression
void InfixToPostfix(char infix[], char postfix[]) {
    int i, j;
    char dataItem;
    char ifOperator;

    push('('); // Add opening bracket to infix expression
    strcat(infix, ")"); // Add closing bracker to infix expression

    i = j = 0;
    dataItem = infix[i];

    while(dataItem != '\0') {
        if(dataItem == '(') {
            push(dataItem);
        }
        else if(isdigit(dataItem) || isalpha(dataItem)) {
            postfix[j] = dataItem;
            ++j;
        }
        else if(isOperator(dataItem) == 1) {
            ifOperator = pop();
            while(isOperator(ifOperator) == 1 && (precedence(ifOperator) >= precedence(dataItem))) {
                postfix[j] = ifOperator;
                ++j;
                ifOperator = pop();
            }

            push(ifOperator);
            push(dataItem);
        }
        else if(dataItem == ')') {
            ifOperator = pop();
            while(ifOperator != '(') {
                postfix[j] = ifOperator;
                ++j;
                ifOperator = pop();
            }
        }
        else {
            printf("\nInvalid infix expression");
            getchar(); exit(1);
        }
        ++i;
        dataItem = infix[i];
    } // [WHILE LOOP ENDS HERE]

    if(top > 0) {
        printf("\nInvalid infix expression");
        getchar(); exit(1);
    }

    postfix[j] = '\0';
}

int main() {

    // Infix and Postfix arrays
    char infix[SIZE], postfix[SIZE];

    printf("INFIX TO POSTFIX CONVERSION");

    printf("\nEnter infix expression: ");
    gets(infix);

    InfixToPostfix(infix, postfix);

    printf("Postfix expression is: ");
    puts(postfix);

    getchar();
    return 0;
}