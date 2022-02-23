#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAX 3
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
    if (queue->front == (queue->rear + 1) % MAX) return true; /* Queue is Full */

    return false;
}

/* Check if Queue is Empty */
bool is_underflow(Queue* queue) {
   if (queue->front == -1 && queue->rear == -1) return true; /* Queue is Empty */

   return false;
}

/* Add element to the Queue */
bool enqueue(Queue* queue, char* ele) {
    if (is_overflow(queue)) return false; /* Queue is Full */

    if (queue->front == -1) queue->front = queue->rear = 0; /* Initialize front and rear to index 0 */

    strcpy(queue->data[((++queue->rear) % MAX)], ele); // Increment rear and store value

    return true;
}

/* Remove element from Queue */
char* dequeue(Queue* queue) {
    if(is_underflow(queue)) return NULL; /* Queue is Empty */

    if(queue->front == queue->rear) queue->front = queue->rear = -1;

    return queue->data[(++queue->front) % MAX]; /* Return front value and decrement */
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
