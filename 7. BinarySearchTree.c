// Program to implement Binary Search Tree
// @Author: D. Kasi Pavan Kumar
// @Date: 18 September 2019

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Node {
    int data; // Data part
    struct Node *left; // Left child
    struct Node *right; // Right child
};

// Method to allocate memory for a new node
struct Node *CreateNode(int data) {
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return(node);
}

// Method to insert a new node in Binary Search Tree
struct Node *InsertNode(struct Node *root, int data) {
    if(root == NULL) {
        root = CreateNode(data);
    }
    else {
        if(data < root -> data) {
            root -> left = InsertNode(root -> left, data);
        }
        else if(data >= root -> data) {
            root -> right = InsertNode(root -> right, data);
        }
    }

    return(root);
}

// Method to perform Inorder traversal of the tree
void InorderTraversal(struct Node *root) {
    if(root != NULL) {
        InorderTraversal(root -> left);
        printf("%d ", root -> data);
        InorderTraversal(root -> right);
    }
}

// Method to perform Preorder traversal of the tree
void PreorderTraversal(struct Node *root) {
    if(root != NULL) {
        printf("%d ", root -> data);
        PreorderTraversal(root -> left);
        PreorderTraversal(root -> right);
    }
}

// Method to perform Postorder traversal of the tree
void PostorderTraversal(struct Node *root) {
    if(root != NULL) {
        PostorderTraversal(root -> left);
        PostorderTraversal(root -> right);
        printf("%d ", root -> data);
    }
}

// Method to display menu
int DisplayMenu() {
    system("cls");
    printf("BINARY SEARCH TREE\n");
    printf("\n1. Insert Node \n2. Inorder Traversal \n3. Preorder Traversal \n4. Postorder Traversal \n5. Exit");
    printf("\nEnter your choice: ");
    int choice; scanf("%d", &choice);
    return(choice);
}

// Method to take data as input
int GetData() {
    printf("\nEnter data to be inserted: ");
    int data; scanf("%d", &data);
    return(data);
}

int main() {
    struct Node *root = NULL;
    int choice = 0;
    int data = 0;

    do {
        choice = DisplayMenu();

        switch(choice) {
            case 1:
                data = GetData();
                if(root == NULL) {
                    root = InsertNode(root, data);
                }
                else {
                    InsertNode(root, data);
                }
                printf("\nPress enter to continue \n> ");
                getch();
                break;
                

            case 2:
                printf("\nInorder traversal = ");
                InorderTraversal(root);
                printf("\n");
                printf("\nPress enter to continue \n> ");
                getch();
                break;
            
            case 3:
                printf("\nPreorder traversal = ");
                PreorderTraversal(root);
                printf("\n");
                printf("\nPress enter to continue \n> ");
                getch();
                break;
            
            case 4:    
                printf("\nPostorder traversal = ");
                PostorderTraversal(root);
                printf("\n");
                printf("\nPress enter to continue \n> ");
                getch();
                break;

            case 5:
                exit(0);
        }
    } while(choice > 0 && choice <= 5);

    getch();
    return 0;
} // [END OF PROGRAM]