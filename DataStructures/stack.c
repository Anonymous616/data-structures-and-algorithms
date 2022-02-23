#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAX 10
#define STRING_SIZE 10

/* Color Codes */
static const char red[] = "\033[0;31m";
static const char green[] = "\033[0;32m";
static const char yellow[] = "\033[0;33m";
static const char blue[] = "\033[0;34m";
static const char purple[] = "\033[0;35m";
static const char cyan[] = "\033[0;36m";
static const char white[] = "\033[0;37m";

typedef struct {
    char data[MAX][STRING_SIZE];
    int top;
} Stack;

/* Check if Stack is Full */
bool is_overflow(Stack* stack) {
    if (stack->top >= MAX-1) return true; /* Stack is Full */
    return false;
}

/* Check if Stack is Empty */
bool is_underflow(Stack* stack) {
   if (stack->top < 0) return true; /* Stack is Empty */
   return false;
}

/* Add element to the Stack */
bool push(Stack* stack, char* ele) {
    if (is_overflow(stack)) return false; /* Stack is Full */

    strcpy(stack->data[++stack->top], ele); /* Increment top and store value at new top */

    return true;
}

/* Remove element from Stack */
char* pop(Stack* stack) {
    if(is_underflow(stack)) return NULL; /* Stack is Empty */
    return stack->data[(stack->top)--]; /* Return top value and decrement */
}

/* Check the topmost element's value */
char* peek(Stack* stack){
    if (is_underflow(stack)) return NULL;
    return stack->data[stack->top];
}

/* Returns number of elements in stack */
int size(Stack* stack){
    return stack->top + 1;
}

/* Display Stack */
void displayStack(Stack* stack){

    printf("\nNumber of elements: %d", size(stack));

    if (is_underflow(stack)) {
        printf("\nStack is Empty.");
        return;
    }

    printf("\n%d -> %s <=== Top", stack->top, stack->data[stack->top]);
    for(int i = stack->top-1; i >= 0; i--) printf("\n%d -> %s", i, stack->data[i]);
}

/* Prints Options for Menu */
void printOptions() {
    printf("\n\n%s==>%s STACK MENU", red, white);
    printf("\n%s ->%s q Quit", green, white);
    printf("\n%s ->%s n PUSH", green, white);
    printf("\n%s ->%s d POP", green, white);
    printf("\n%s ->%s t PEEK", green, white);
    printf("\n%s ->%s a Display Stack", green, white);
    printf("\nEnter Choice (q/n/d/t/a): ");
}

/* Print Menu for Stack */
int menu(Stack* stack) {

    char choice;
    char* value = (char*) malloc(STRING_SIZE);

    /* printf("\n\n==> MENU\t\n -> q: Quit\n -> n: PUSH\n -> d: POP\n -> t: PEEK\n -> a: Display Stack\n Enter Choice (q/n/d/t/a): "); */

    printOptions();

    scanf(" %c", &choice);
    switch(choice) {
        case 'n':
            bool success;

            printf("\n=== PUSH Operation ===\n");
            printf("\nEnter value: ");
            scanf("%s", value); /* Accept value to push of stack */

            success = push(stack, value);

            if (!success) printf("\nStack is Full");

            break;

        case 'd':
            printf("\n=== POP Operation ===");

            value = pop(stack);

            if (value == NULL)
                printf("\nStack is Empty");
            else
                printf("\nValue popped: %s", value);

            break;

        case 't':
            printf("\n=== PEEK Operation ===");

            value = peek(stack);

            if (value == NULL)
                printf("\nStack is Empty");
            else
                printf("\nTop most Value: %s", value);

            break;

        case 'a':
            printf("\n=== Displaying Stack ===");
            displayStack(stack);
            break;

        case 'q':
            return 0;
            break;

        default:
            printf("\nInvalid Choice.");
            break;
    }

    return 1;
}

int main() {

    /* Initialize and Allocate memory for Stack */
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = -1;

    /* Check if memory was allocate, if not then exit */
    if (stack == NULL) return 1;

    /* Run loop for menu */
    int loop;
    do {
        loop = menu(stack);
    } while(loop);

    /* Release stack resources */
    free(stack);

    getchar();

    return 0;
}

/*

       OUTPUT

==> STACK MENU
 -> q Quit
 -> n PUSH
 -> d POP
 -> t PEEK
 -> a Display Stack
Enter Choice (q/n/d/t/a): n

=== PUSH Operation ===

Enter value: abc


==> STACK MENU
 -> q Quit
 -> n PUSH
 -> d POP
 -> t PEEK
 -> a Display Stack
Enter Choice (q/n/d/t/a): n

=== PUSH Operation ===

Enter value: def


==> STACK MENU
 -> q Quit
 -> n PUSH
 -> d POP
 -> t PEEK
 -> a Display Stack
Enter Choice (q/n/d/t/a): n

=== PUSH Operation ===

Enter value: hijk


==> STACK MENU
 -> q Quit
 -> n PUSH
 -> d POP
 -> t PEEK
 -> a Display Stack
Enter Choice (q/n/d/t/a): a

=== Displaying Stack ===
Number of elements: 3
2 -> hijk <=== Top
1 -> def
0 -> abc

==> STACK MENU
 -> q Quit
 -> n PUSH
 -> d POP
 -> t PEEK
 -> a Display Stack
Enter Choice (q/n/d/t/a): d

=== POP Operation ===
Value popped: hijk

==> STACK MENU
 -> q Quit
 -> n PUSH
 -> d POP
 -> t PEEK
 -> a Display Stack
Enter Choice (q/n/d/t/a): t

=== PEEK Operation ===
Top most Value: def

==> STACK MENU
 -> q Quit
 -> n PUSH
 -> d POP
 -> t PEEK
 -> a Display Stack
Enter Choice (q/n/d/t/a): d

=== POP Operation ===
Value popped: def

==> STACK MENU
 -> q Quit
 -> n PUSH
 -> d POP
 -> t PEEK
 -> a Display Stack
Enter Choice (q/n/d/t/a): d

=== POP Operation ===
Value popped: abc

==> STACK MENU
 -> q Quit
 -> n PUSH
 -> d POP
 -> t PEEK
 -> a Display Stack
Enter Choice (q/n/d/t/a): d

=== POP Operation ===
Stack is Empty

==> STACK MENU
 -> q Quit
 -> n PUSH
 -> d POP
 -> t PEEK
 -> a Display Stack
Enter Choice (q/n/d/t/a): q

   */
