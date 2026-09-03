#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct Stack {
    int *data;
    int capacity;
    int top;
} Stack;

Stack createStack(int capacity) {
    Stack newStack;
    newStack.data = malloc(sizeof(int) * capacity);
    newStack.capacity = capacity;
    newStack.top = -1;
    return newStack;
}

bool isEmpty(Stack stack) { return stack.top == -1; }
bool isFull(Stack stack)  { return stack.top == stack.capacity; }

int size(Stack stack) { return stack.top + 1; }

bool push(Stack *stack, int value) {
    if (isFull(*stack)) return false;

    stack->top++;
    stack->data[stack->top] = value;
    return true;
}

int pop(Stack *stack) {
    int popped = stack->data[stack->top];
    stack->top--;   
    return popped;
}

void printStack(Stack stack) {
    for (int i = stack.top; i >= 0; i--) {
        printf("%d ", stack.data[i]);
    }
    printf("\n");
}

int main() {
    Stack myStack = createStack(32);

    push(&myStack, 10);
    push(&myStack, 46);
    push(&myStack, 23);
    push(&myStack, 2);
    push(&myStack, 60);

    printf("\n");

    printStack(myStack);
    printf("Tamanho do stack: %d\n", size(myStack));

    printf("\n");

    printf("Popping: %d\n", pop(&myStack));
    printf("Popping: %d\n", pop(&myStack));

    printf("\n");

    printStack(myStack);
    printf("Tamanho do stack: %d\n", size(myStack));

    printf("\n");

    return EXIT_SUCCESS;
}