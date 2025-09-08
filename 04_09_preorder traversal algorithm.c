#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Stack {
    int top;
    int capacity;
    struct Node** array;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (struct Node**)malloc(stack->capacity * sizeof(struct Node*));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, struct Node* node) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = node;
}

struct Node* pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->array[stack->top--];
}

void preorderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Stack* stack = createStack(100); 
    push(stack, root);

    while (!isEmpty(stack)) {
        struct Node* node = pop(stack);
        printf("%d ", node->data);

        if (node->right)
            push(stack, node->right);
        if (node->left)
            push(stack, node->left);
    }

    free(stack->array);
    free(stack);
}

int main() {


    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    return 0;
}
