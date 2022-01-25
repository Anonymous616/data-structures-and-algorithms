#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<regex.h>
#include<stdbool.h>
#include<string.h>
#define MAX 10
#define STRING_SIZE 10

const char BRACKETS[][3] = {
    {'(', '[', '{'},
    {')', ']', '}'}
};

typedef struct {
    char data[MAX];
    int top;
} Stack;

/* Add element to the Stack */
void push(Stack* stack, char ele) {
    stack->data[++stack->top] = ele; /* Increment top and store value at new top */
}

/* Remove element from Stack */
char pop(Stack* stack) {
    return stack->data[(stack->top)--]; /* Return top value and decrement */
}

/* Check the topmost element's value */
char peek(Stack* stack){
    return stack->data[stack->top];
}

/* Returns number of elements in stack */
int size(Stack* stack){
    return stack->top + 1;
}

/* Display Stack */
void displayStack(Stack* stack){

    printf("\nNumber of elements: %d", size(stack));

    printf("\n%d -> %c <=== Top", stack->top, stack->data[stack->top]);
    for(int i = stack->top-1; i >= 0; i--) printf("\n%d -> %c", i, stack->data[i]);
}

/* Get Precedence of Operator */
int precedence(char op){
    switch(op) {
        case '^': return 3;

        case '*': return 2;
        case '/': return 2;

        case '+': return 1;
        case '-': return 1;

        default: return 0;
    }
}

/* Check if Operator */
bool is_operator(char op) {
    return precedence(op) != 0 ? true : false;
}

/* Get if character is opening or closing bracket */
int type_of_bracket(char b) {
    for (int i = 0; i < sizeof(BRACKETS[0])/sizeof(char); i++) {
        if (BRACKETS[0][i] == b) return 0;
        if (BRACKETS[1][i] == b) return 1;
    }

    return -1;
}

/* Check if Bracket */
bool is_bracket(char b) {
    int type = type_of_bracket(b);

    if (type == -1) return false;

    return true;
}

char corr_close_bracket(char b) {
    int index = -1;

    for (int i = 0; i < sizeof(BRACKETS[0])/sizeof(char); i++)
        if (BRACKETS[0][i] == b) index = i;

    return BRACKETS[1][index];
}

int main() {

    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = -1;

    int k = 0;
    char infix_exp[30], post_exp[30], ch, value;

    printf("Enter expression: ");
    scanf("%s", &infix_exp);

    printf("\nInfix Expresion = %s", infix_exp);

    strcat(infix_exp, ")"); // Appending ) to infix expression
    push(stack, '('); // Push ( to Stack

    for(int i=0; ch = infix_exp[i] != '\0'; i++) {
        ch = infix_exp[i];

        // For debugging purposes
        // printf("\nCHAR: %c, TOP: %c, PRECEDE: %d", ch, peek(stack), precedence(ch));

        if (ch == '(')
            push(stack, ch); // Push ( on stack
        else
            // Is alphanumeric i.e. Operand (A, B, C ...)
            if (isalnum(ch)) {
                post_exp[k++] = ch; // Add operand to expression
            }
            else {
                if (ch == ')') {
                    while (peek(stack) != '(')
                        post_exp[k++] = pop(stack); // Pop until ) encountered

                    pop(stack); // Popping (
                } else {

                    //  ^ push, + stack
                    // Check precedence, pop and add to postfix
                    while (precedence(peek(stack)) >= precedence(ch))
                        post_exp[k++] = pop(stack);

                    push(stack, ch); // Push operator to stack
                }
            }
    }

    post_exp[k] = '\0'; // Terminate Postfix String

    printf("\nPostfix Expression = %s", post_exp);

    free(stack);

    scanf(" %c", &ch);

    return 0;
}
