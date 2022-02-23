#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define STRING_SIZE 10

/* Color Codes */
static const char red[] = "\033[0;31m";
static const char green[] = "\033[0;32m";
static const char yellow[] = "\033[0;33m";
static const char blue[] = "\033[0;34m";
static const char purple[] = "\033[0;35m";
static const char cyan[] = "\033[0;36m";
static const char white[] = "\033[0;37m";

struct Node {
    char* data;
    struct Node* next;
};

struct Node* createNode(char*);

void printNodeData(struct Node*);
void printAllNodes(struct Node*);

struct Node* getLastNode(struct Node*);
struct Node* getNodeAtPos(struct Node*, int i);

int sizeOfList(struct Node*);
int search (struct Node*, char*);
struct Node* reverse(struct Node*);

void releaseNodes(struct Node*);

/* ================================= */
/*             Insert                */
/* ================================= */
struct Node* insertBeg(struct Node*, char*);
struct Node* insertEnd(struct Node*, char*);
struct Node* insertPos(struct Node*, char*, int pos);

/* ================================= */
/*             Delete                */
/* ================================= */
struct Node* deleteBeg(struct Node*);
void deleteEnd(struct Node*);
struct Node* deleteAtPos(struct Node*, int pos);

/* Prints Options for Menu */
void printOptions() {
    printf("\n\n%s==>%s LINKED LIST MENU", red, white);
    printf("\n%s ->%s q Quit", green, white);
    printf("\n%s ->%s n INSERT", green, white);
    printf("\n%s ->%s d DELETE", green, white);
    printf("\n%s ->%s s SEARCH", green, white);
    printf("\n%s ->%s r REVERSE", green, white);
    printf("\n%s ->%s a DISPLAY", green, white);
    printf("\nEnter Choice (q/n/d/a): ");
}

void printInsertOptions() {
    printf("\n%s=>%s INSERT AT", red, white);
    printf("\n%s ->%s b Beginning", green, white);
    printf("\n%s ->%s e End", green, white);
    printf("\n%s ->%s p Position", green, white);
    printf("\nEnter Choice (b/e/p): ");
}

void printDeleteOptions() {
    printf("\n%s=>%s DELETE AT", red, white);
    printf("\n%s ->%s b Beginning", green, white);
    printf("\n%s ->%s e End", green, white);
    printf("\n%s ->%s p Position", green, white);
    printf("\nEnter Choice (b/e/p): ");
}

struct Node* insertMenu(struct Node* start) {
    char* value = (char*) malloc(STRING_SIZE);
    char choice;
    int pos;

    printf("\nEnter value: ");
    scanf(" %s", value);

    do {
        printInsertOptions();
        scanf(" %c", &choice);

        switch(choice) {
            case 'b':
                start = insertBeg(start, value);
                break;
            case 'e':
                start = insertEnd(start, value);
                break;
            case 'p':
                printf("Enter position : ");
                scanf("%d", &pos);
                start = insertPos(start, value, pos);
                break;
            default:
                choice = 'i';
                printf("Invalid Choice.");
                break;
        }
    } while(choice == 'i');
    return start;
}

struct Node* deleteMenu(struct Node* start) {
    char choice;

    do {
        printDeleteOptions();

        scanf(" %c", &choice);
        switch(choice) {
            case 'b':
                start = deleteBeg(start);
                break;
            case 'e':
                deleteEnd(start);
                break;
            case 'p':
                int pos;
                printf("Enter position : ");
                scanf("%d", &pos);
                start = deleteAtPos(start, pos);
                break;
            default:
                choice = 'i';
                printf("Invalid Choice.");
                break;
        }
    } while(choice == 'i');

    return start;
}

/* Menu */
struct Node* menu(struct Node* start) {

    char choice;
    char* value = (char*) malloc(STRING_SIZE);

    do {
        printOptions();
        scanf(" %c", &choice);

        switch(choice) {
            case 'n':
                printf("\n=== INSERT Operation ===\n");
                start = insertMenu(start);
                break;

            case 'd':
                printf("\n=== DELETE Operation ===");
                start = deleteMenu(start);
                break;

            case 's':
                printf("\n=== SEARCH Element ===");
                printf("\nEnter element to search : ");
                scanf(" %s", value);
                int index = search(start, value);
                if (index == -1)
                    printf("\n%s not found", value);
                else
                    printf("\n%s found at %d", value, index);
                break;

            case 'r':
                printf("\n=== REVERSE List ===");
                start = reverse(start);
                printAllNodes(start);
                break;

            case 'a':
                printf("\n=== DISPLAYING List ===");
                printf("\nSize of List : %d", sizeOfList(start));
                printAllNodes(start);
                break;

            case 'q':
                break;

            default:
                printf("\nInvalid Choice.");
                break;
        }
    } while(choice != 'q');

    return start;
}

int main() {

    /* Initialize and Allocate memory for Linked List */
    struct Node* start;
    start = insertBeg(start, "deon");
    insertEnd(start, "berton");
    insertEnd(start, "gracias");

    start = menu(start);

    getchar();

    return 0;
}

/* Create new Node */
struct Node* createNode(char* data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Print Node Data */
void printNodeData(struct Node* node) {
    printf("\n%s", node->data);
}

/* Print All Nodes */
void printAllNodes(struct Node* start) {
    if (start == NULL) {
        printf("\nEmpty List");
        return;
    }

    struct Node* p = start;
    printf("\n");
    while (p->next != NULL) {
        printf("%s -> ", p->data);
        p = p->next;
    }
    printf("%s", p->data);
}

/* Get Last Node */
struct Node* getLastNode(struct Node* node) {
    if (node == NULL || node->next == NULL) return node;
    return getLastNode(node->next);
}

/* Get Node at Position */
struct Node* getNodeAtPos(struct Node* node, int pos) {
    struct Node* temp = node;
    for(int i = 0; i < pos; i++) {
        temp = temp->next;
        if (temp == NULL) return NULL; // Couldn't find
    }
    return temp; // Return node at position
}

/* Size of Linked List */
int sizeOfList(struct Node* node) {
    if (node == NULL) return 0; // No more nodes to traverse
    return 1 + (node->next == NULL ? 0 : sizeOfList(node->next)); // Return 1 if no next node else 1 + index)
}

/* Release all Nodes */
void releaseNodes(struct Node* start) {
    struct Node* p;

    // Traversing all nodes
    while(start != NULL) {
        p = start;
        start = start->next;
        free(p);
    }
}

/* ================================= */
/*             Insert                */
/* ================================= */

/* Insert at Beginning */
struct Node* insertBeg(struct Node* start, char* data) {
    struct Node* newNode = createNode(data);

    newNode->next = start; // New node points to the first node
    start = newNode; // New node will be the first node in the list

    return newNode;
}

/* Insert at End */
struct Node* insertEnd(struct Node* start, char* data) {
    struct Node* newNode = createNode(data);

    if (start == NULL) {
        start = insertBeg(start, data);
    } else {
        struct Node* p = getLastNode(start); // Get last node
        p->next = newNode; // Append new node the last node
    }

    return start;
}

/* Insert at Position */
struct Node* insertPos(struct Node* start, char* data, int pos) {
    if (pos == 1) return insertBeg(start, data); // Insert beginning

    struct Node* newNode = createNode(data);
    struct Node* p = getNodeAtPos(start, pos - 2); // Get Node before the node to be deleted

    if (p->next == NULL) {
        insertEnd(start, data); // Insert at the end, since index doesn't exist
    } else {
        newNode->next = p->next; // New node next will be the node at the next index
        p->next = newNode; // Original node at the index will point to new node
    }

    return start;
}

/* ================================= */
/*             Delete                */
/* ================================= */

/* Delete at Beginning */
struct Node* deleteBeg(struct Node* start) {
    struct Node* p = start;

    start = start->next; // Get node after the first node

    p->next = NULL; free(p); // Delete Node

    return start; // Return the node that was previously after the first node
}

/* Delete at End */
void deleteEnd(struct Node* start) {
    struct Node* p = getNodeAtPos(start, sizeOfList(start) - 2); // Get last Node

    if (p == NULL) return; // Node not found

    free(p->next); // Free Last Node

    p->next = NULL;
}

/* Delete at Position */
struct Node* deleteAtPos(struct Node* start, int pos) {
    if (pos == 1) return deleteBeg(start);

    struct Node* p = getNodeAtPos(start, pos - 2); // Get the node before the node to be deleted

    if (p == NULL) return start; // Node not found

    struct Node* q = p->next; // Node to be deleted

    p->next = q->next; // Node after the deleted node

    free(q); // Delete Node

    return start;
}

/* ================================= */
/*             Searching             */
/* ================================= */

int search(struct Node* start, char* value) {
    struct Node* temp = start;
    for(int i = 1; i <= sizeOfList(start)+1; i++, temp = temp->next)
        if (strcmp(temp->data, value) == 0) // Strings match
            return i; // Returning position
    return -1; // Element not found
}

/* ================================= */
/*             Reversing             */
/* ================================= */

struct Node* reverse(struct Node* start) {
    struct Node* prevNode = NULL;
    struct Node* currNode = start;
    struct Node* nextNode = start->next;

    while (currNode != NULL) {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }

    return prevNode;
}

/*

       OUTPUT

==> LINKED LIST MENU
 -> q Quit
 -> n INSERT
 -> d DELETE
 -> s SEARCH
 -> r REVERSE
 -> a DISPLAY
Enter Choice (q/n/d/a): n

=== INSERT Operation ===

Enter value: deon

=> INSERT AT
 -> b Beginning
 -> e End
 -> p Position
Enter Choice (b/e/p): b


==> LINKED LIST MENU
 -> q Quit
 -> n INSERT
 -> d DELETE
 -> s SEARCH
 -> r REVERSE
 -> a DISPLAY
Enter Choice (q/n/d/a): n

=== INSERT Operation ===

Enter value: gracias

=> INSERT AT
 -> b Beginning
 -> e End
 -> p Position
Enter Choice (b/e/p): e


==> LINKED LIST MENU
 -> q Quit
 -> n INSERT
 -> d DELETE
 -> s SEARCH
 -> r REVERSE
 -> a DISPLAY
Enter Choice (q/n/d/a): n

=== INSERT Operation ===

Enter value: berton

=> INSERT AT
 -> b Beginning
 -> e End
 -> p Position
Enter Choice (b/e/p): p
Enter position : 2


==> LINKED LIST MENU
 -> q Quit
 -> n INSERT
 -> d DELETE
 -> s SEARCH
 -> r REVERSE
 -> a DISPLAY
Enter Choice (q/n/d/a): s

=== SEARCH Element ===
Enter element to search : berton

berton found at 2

==> LINKED LIST MENU
 -> q Quit
 -> n INSERT
 -> d DELETE
 -> s SEARCH
 -> r REVERSE
 -> a DISPLAY
Enter Choice (q/n/d/a): a

=== DISPLAYING List ===
Size of List : 3
deon -> berton -> gracias

==> LINKED LIST MENU
 -> q Quit
 -> n INSERT
 -> d DELETE
 -> s SEARCH
 -> r REVERSE
 -> a DISPLAY
Enter Choice (q/n/d/a): r

=== REVERSE List ===
gracias -> berton -> deon

==> LINKED LIST MENU
 -> q Quit
 -> n INSERT
 -> d DELETE
 -> s SEARCH
 -> r REVERSE
 -> a DISPLAY
Enter Choice (q/n/d/a): d

=== DELETE Operation ===
=> DELETE AT
 -> b Beginning
 -> e End
 -> p Position
Enter Choice (b/e/p): p
Enter position : 2


==> LINKED LIST MENU
 -> q Quit
 -> n INSERT
 -> d DELETE
 -> s SEARCH
 -> r REVERSE
 -> a DISPLAY
Enter Choice (q/n/d/a): d

=== DELETE Operation ===
=> DELETE AT
 -> b Beginning
 -> e End
 -> p Position
Enter Choice (b/e/p): b


==> LINKED LIST MENU
 -> q Quit
 -> n INSERT
 -> d DELETE
 -> s SEARCH
 -> r REVERSE
 -> a DISPLAY
Enter Choice (q/n/d/a): a

=== DISPLAYING List ===
Size of List : 1
deon

==> LINKED LIST MENU
 -> q Quit
 -> n INSERT
 -> d DELETE
 -> s SEARCH
 -> r REVERSE
 -> a DISPLAY
Enter Choice (q/n/d/a): q

   */
