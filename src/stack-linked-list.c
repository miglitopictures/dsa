// Pilha
// implementação com lista encadeada simples
// HEAD -> [F] -> [E] -> [D] --> [C] -> [B] -> [A] -> NULL

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// retorna true se pilha estiver vazia
bool isEmpty(Node *head) { return (head == NULL); }

// calcula o tamanho da pilha recursivamente.
// @return tamanho da pilha
int size(Node *head) {
    if (isEmpty(head)) return 0;
    return 1 + size(head->next);
}

// insere novo elemento na pilha
// retorna um bool referente ao sucesso da operação
bool push(Node **head, int data) {
    // cria novo elemento
    Node *newElement = malloc(sizeof(Node));
    if (!newElement) return false;

    // preenche novo elemento
    newElement->data = data;
    newElement->next = *head;

    // head aponta para novo elemento
    *head = newElement;

    return true;
}

// retorna ultimo elemento inserido (LIFO), removendo-o da pilha
// o caller é responsável pelo gerenciamento de memória
Node *pop(Node **head) {
    if (isEmpty(*head)) return NULL;
    Node *popped = *head;
    *head = (*head)->next;
    return popped;
}

// retorna o valor do ultimo elemento inserido, sem remove-lo da pilha
// o caller é responsável por garantir que a pilha não está vazia.
int peek(Node *head) { return head->data; }

// copia o ultimo valor inserido para "out", sem retirar o item da pilha.
// retorna um bool referente ao sucesso da operação
bool peekSafe(Node *head, int *out) {
    if (isEmpty(head)) return false;
    *out = head->data;
    return true;
}

// imprime uma lista encadeada recursivamente.
void printList(Node *head) {
    if (isEmpty(head)) return;
    printf("%d ", head->data);
    printList(head->next);
}

// libera a memoria alocada para toda a pilha.
void freeStack(Node *head) {
    if (isEmpty(head)) return;
    freeStack(head->next);
    free(head);
}

int main() {

    // inicializa pilha
    Node *myStack = NULL;
    
    // teste de inserção (0 a 15)
    for (int i = 0; i <= 15; i++) {
        if (push(&myStack, i) == false) {
            fprintf(stderr, "Error: Could not push %d in the stack\n", i);
            return(EXIT_FAILURE);
        }
    }
    
    // imprime estado atual da pilha
    printf("\n");
    printList(myStack);
    printf("\nTamalho da pilha: %d", size(myStack));
    printf("\n\n");
    
    if (!isEmpty(myStack))
        printf("Peek: %d \n", peek(myStack));
    
    printf("\n");

    {   // Pop the top
        Node *poppedElement = pop(&myStack);
        if (poppedElement) {
            printf("Popped: %d\n", poppedElement->data);
            free(poppedElement);
        } else {
            printf("Empty stack.\n");
        }  
    }

    printf("\n");

    {   // Give it a safe peek
        int peekedValue;
        if (peekSafe(myStack, &peekedValue)) {
            printf("Peek: %d \n", peekedValue);
        } else {
            printf("Peek operation failed, stack is empty");
        }
    }

    printf("\n");

    // tentamos pop() 
    for (int i = 0; i < 20; i++) {
        Node *poppedElement = pop(&myStack);
        if (poppedElement) {
            printf("Popped: %d\n", poppedElement->data);
            free(poppedElement);
        } else {
            printf("Empty stack.\n");
        }
    }

    printf("\n");
    printf("\nTamalho da pilha: %d", size(myStack));
    printf("\n\n");

    // teste de inserção (0 a 15)
    for (int i = 0; i <= 15; i++) {
        if (push(&myStack, i+15) == false) {
            fprintf(stderr, "Error: Could not push %d in the stack\n", i);
            return(EXIT_FAILURE);
        }
    }

    // imprime estado atual da pilha
    printf("\n");
    printList(myStack);
    printf("\nTamalho da pilha: %d", size(myStack));
    printf("\n\n");


    freeStack(myStack);
    myStack = NULL;

    return(EXIT_SUCCESS);
}
