#include <stdio.h>
#include <stdlib.h>

// Each stack element only contains an integer val.
typedef struct s_stack_elem {
    int val;
    struct s_stack_elem *next;
} STACK_ELEM;

typedef STACK_ELEM *STACK;

// Returns 1 if the stack is empty, 0 otherwise.
int stack_is_empty(STACK s) {
    return s == NULL;
}

// Pushes a new element with 'val' onto the stack.
// Returns the new stack top.
STACK stack_push(STACK s, int val) {
    STACK_ELEM* new_elem = (STACK_ELEM*)malloc(sizeof(STACK_ELEM));
    if (!new_elem) {
        perror("Failed to allocate memory for stack element");
        exit(EXIT_FAILURE);
    }
    new_elem->val = val;
    new_elem->next = s;
    return new_elem;
}

// Pops the top element from the stack and returns its value.
// Note: This function modifies the stack pointer.
int stack_pop(STACK *s) {
    if (stack_is_empty(*s)) {
        fprintf(stderr, "Error: stack underflow\n");
        exit(EXIT_FAILURE);
    }
    int popped_val = (*s)->val;
    STACK_ELEM *temp = *s;
    *s = (*s)->next;
    free(temp);
    return popped_val;
}

// Returns the value of the top element without removing it.
int stack_peek(STACK s) {
    if (stack_is_empty(s)) {
        fprintf(stderr, "Error: stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return s->val;
}

// Frees all elements in the stack.
void stack_free(STACK s) {
    STACK_ELEM* current = s;
    while (current != NULL) {
        STACK_ELEM* next = current->next;
        free(current);
        current = next;
    }
}

// Example usage of the stack
int main() {
    STACK my_stack = NULL;

    printf("Is stack empty? %s\n", stack_is_empty(my_stack) ? "Yes" : "No");

    printf("Pushing 10, 20, 30...\n");
    my_stack = stack_push(my_stack, 10);
    my_stack = stack_push(my_stack, 20);
    my_stack = stack_push(my_stack, 30);

    printf("Is stack empty? %s\n", stack_is_empty(my_stack) ? "Yes" : "No");
    printf("Peek: %d\n", stack_peek(my_stack));

    printf("Popping: %d\n", stack_pop(&my_stack));
    printf("Peek: %d\n", stack_peek(my_stack));
    printf("Popping: %d\n", stack_pop(&my_stack));
    printf("Peek: %d\n", stack_peek(my_stack));
    printf("Popping: %d\n", stack_pop(&my_stack));

    printf("Is stack empty? %s\n", stack_is_empty(my_stack) ? "Yes" : "No");

    // The stack is now empty, popping again would cause an underflow error.
    // printf("Popping from empty stack (will error):\n");
    // stack_pop(&my_stack);

    // Freeing an empty stack is safe.
    stack_free(my_stack);

    return 0;
}