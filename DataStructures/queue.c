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
    int front, rear;
} Queue;

/* Check if Queue is Full */
bool is_overflow(Queue* queue) {
    if (queue->rear == MAX - 1) return true; /* Queue is Full */

    return false;
}

/* Check if Queue is Empty */
bool is_underflow(Queue* queue) {
   if (queue->front > queue->rear || queue->rear == -1 ) return true; /* Queue is Empty */

   return false;
}

/* Add element to the Queue */
bool enqueue(Queue* queue, char* ele) {
    if (is_overflow(queue)) return false; /* Queue is Full */

    if (queue->front == -1) queue->front = 0; /* If queue was empty  */

    strcpy(queue->data[++queue->rear], ele); /* Increment rear and store value at new rear */

    return true;
}

/* Remove element from Queue */
char* dequeue(Queue* queue) {
    if(is_underflow(queue)) return NULL; /* Queue is Empty */

    return queue->data[(queue->front)++]; /* Return front value and decrement */
}

/* Check the topmost element's value */
char* peek(Queue* queue){
    if (is_underflow(queue)) return NULL;
    return queue->data[queue->front];
}

/* Returns number of elements in queue */
int size(Queue* queue){
    return queue->rear + 1;
}

/* Display Queue */
void displayQueue(Queue* queue){

    printf("\nNumber of elements: %d", size(queue));

    /* Empty */
    if (is_underflow(queue)) {
        printf("\nQueue is Empty.");
        return;
    }

    /* For 1 element */
    if (queue->rear == queue->front) {
        printf("\n%d -> %s <=== FRONT & REAR", queue->rear, queue->data[queue->rear]);
        return;
    }

    /* For more than 1 element */
    printf("\n%d -> %s <=== FRONT", queue->front, queue->data[queue->front]);

    /* printf("\n%d front , %d rear\n", queue->front, queue->rear); */
    if (queue->rear > 2)
        for(int i = queue->front+1; i < queue->rear; i++)
            printf("\n%d -> %s", i, queue->data[i]);

    printf("\n%d -> %s <=== REAR", queue->rear, queue->data[queue->rear]);
}

/* Prints Options for Menu */
void printOptions() {
    printf("\n\n%s==>%s QUEUE MENU", red, white);
    printf("\n%s ->%s q Quit", green, white);
    printf("\n%s ->%s n ENQUEUE", green, white);
    printf("\n%s ->%s d DEQUEUE", green, white);
    printf("\n%s ->%s t PEEK", green, white);
    printf("\n%s ->%s a Display Queue", green, white);
    printf("\nEnter Choice (q/n/d/t/a): ");
}

/* Print Menu for Queue */
int menu(Queue* queue) {

    char choice;
    char* value = (char*) malloc(STRING_SIZE);

    /* printf("\n\n==> MENU\t\n -> q: Quit\n -> n: ENQUEUE\n -> d: DEQUEUE\n -> t: PEEK\n -> a: Display Queue\n Enter Choice (q/n/d/t/a): "); */

    printOptions();

    scanf(" %c", &choice);
    switch(choice) {
        case 'n':
            bool success;

            printf("\n=== ENQUEUE Operation ===\n");
            printf("\nEnter value: ");
            scanf("%s", value); /* Accept value to enqueue of queue */

            success = enqueue(queue, value);

            if (!success) printf("\nQueue is Full");

            break;

        case 'd':
            printf("\n=== DEQUEUE Operation ===");

            value = dequeue(queue);

            if (value == NULL)
                printf("\nQueue is Empty");
            else
                printf("\nValue Dequeued: %s", value);

            break;

        case 't':
            printf("\n=== PEEK Operation ===");

            value = peek(queue);

            if (value == NULL)
                printf("\nQueue is Empty");
            else
                printf("\nFront Value: %s", value);

            break;

        case 'a':
            printf("\n=== Displaying Queue ===");
            displayQueue(queue);
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

    /* Initialize and Allocate memory for Queue */
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = queue->rear = -1;

    /* Check if memory was allocate, if not then exit */
    if (queue == NULL) return 1;

    /* Run loop for menu */
    int loop;
    do {
        loop = menu(queue);
    } while(loop);

    /* Release queue resources */
    free(queue);

    getchar();

    return 0;
}

/*

        OUTPUT

==> QUEUE MENU
 -> q Quit
 -> n ENQUEUE
 -> d DEQUEUE
 -> t PEEK
 -> a Display Queue
Enter Choice (q/n/d/t/a): n

=== ENQUEUE Operation ===

Enter value: abc


==> QUEUE MENU
 -> q Quit
 -> n ENQUEUE
 -> d DEQUEUE
 -> t PEEK
 -> a Display Queue
Enter Choice (q/n/d/t/a): n

=== ENQUEUE Operation ===

Enter value: def


==> QUEUE MENU
 -> q Quit
 -> n ENQUEUE
 -> d DEQUEUE
 -> t PEEK
 -> a Display Queue
Enter Choice (q/n/d/t/a): n

=== ENQUEUE Operation ===

Enter value: hij


==> QUEUE MENU
 -> q Quit
 -> n ENQUEUE
 -> d DEQUEUE
 -> t PEEK
 -> a Display Queue
Enter Choice (q/n/d/t/a): n

=== ENQUEUE Operation ===

Enter value: klm


==> QUEUE MENU
 -> q Quit
 -> n ENQUEUE
 -> d DEQUEUE
 -> t PEEK
 -> a Display Queue
Enter Choice (q/n/d/t/a): t

=== PEEK Operation ===
Front Value: abc

==> QUEUE MENU
 -> q Quit
 -> n ENQUEUE
 -> d DEQUEUE
 -> t PEEK
 -> a Display Queue
Enter Choice (q/n/d/t/a): a

=== Displaying Queue ===
Number of elements: 4
0 -> abc <=== FRONT
1 -> def
2 -> hij
3 -> klm <=== REAR

==> QUEUE MENU
 -> q Quit
 -> n ENQUEUE
 -> d DEQUEUE
 -> t PEEK
 -> a Display Queue
Enter Choice (q/n/d/t/a): d

=== DEQUEUE Operation ===
Value Dequeued: abc

==> QUEUE MENU
 -> q Quit
 -> n ENQUEUE
 -> d DEQUEUE
 -> t PEEK
 -> a Display Queue
Enter Choice (q/n/d/t/a): t

=== PEEK Operation ===
Front Value: def

==> QUEUE MENU
 -> q Quit
 -> n ENQUEUE
 -> d DEQUEUE
 -> t PEEK
 -> a Display Queue
Enter Choice (q/n/d/t/a): a

=== Displaying Queue ===
Number of elements: 4
1 -> def <=== FRONT
2 -> hij
3 -> klm <=== REAR

==> QUEUE MENU
 -> q Quit
 -> n ENQUEUE
 -> d DEQUEUE
 -> t PEEK
 -> a Display Queue
Enter Choice (q/n/d/t/a): q

   */
