#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_STR 21

typedef struct Stack Stack;
typedef struct Node Node;

struct Stack {
    Node * head;
};

struct Node {
    int money;
    char * name;
    Node * next;
};

// Linked List Prototypes
Node * createNode(int money, char * name);
Node * addToHead(Node * player, int money, char * name);
Node * removeHead(Node * head);

// Stack Prototypes
Stack * createStack();
void push(Stack * stack, int money, char * name);
void pop(Stack * stack);
void popMVP(Stack * stack, Stack * stackMVP);
char * top(Stack * stack);
int topValue(Stack * stack);
void destroyStack(Stack * stack);

int main() {
    // Stack of people in arcade
    Stack * stack = createStack();
    // Stack of MVP in arcade
    Stack * stackMVP = createStack();
    int t, money, terminate = 0;
    char * name = malloc(sizeof(char) * MAX_STR);
    
    // While loop until user terminates the program
    while (terminate == 0) {
        // Read in the value of t
        scanf("%d", &t);
        
        // If user inputs 0 for t, the program will terminate
        if (t == 0) {
            terminate = 1;
        }
        
        // If user inputs 1 for t, the person's money and name will be added to the linked list
        else if (t == 1) {
            scanf("%d %s", &money, name);
            
            // If stack is empty, add player to MVP stack
            if (stackMVP->head == NULL) {
                push(stackMVP, money, name);
            }
            
            // If the new player's money is greater than the already existing MVP, add player to MVP stack
            else if (money >= topValue(stackMVP)) {
                push(stackMVP, money, name);
            }
            // Add player to the stack of people in the arcade
            push(stack, money, name);
        }
        
        // If user inputs 2 for t, the program will process a person leaving
        else if (t == 2) {
            // If the person leaving is in the MVP stack, they will be removed from the top of the MVP stack
            popMVP(stack, stackMVP);
            // Remove the person from the top of the stack (people in the arcade)
            pop(stack);
        }
        
        // If user inputs 3 for t, the program will output the most valuable player
        else if (t == 3) {
            if (top(stackMVP) != NULL) {
                printf("%s\n", top(stackMVP));
            }
        }
    }
    
    printf("\n");
    destroyStack(stackMVP);
    destroyStack(stack);
    
    return 0;
}

// Function to create memory for the node
Node * createNode(int money, char * name) {
    Node * ret = calloc(1, sizeof(Node));
    ret->money = money;
    ret->name = strdup(name);
    ret->next = NULL;
    return ret;
}

// Function to add to head and returns the resulting head of the list
Node * addToHead(Node * player, int money, char * name) {
    Node * newPlayer = createNode(money, name);
    newPlayer->next = player;
    return newPlayer;
}

// Function to remove the head and return the head of the list
Node * removeHead(Node * head) {
    if (head == NULL) {
        return NULL;
    }
    Node * newHead = head->next;
    return newHead;
}

// Function to create a section of memory for the stack
Stack * createStack() {
    Stack * ret = calloc(1, sizeof(Stack));
    ret->head = NULL;
    return ret;
}

// Add the player to the top of the stack
void push(Stack * stack, int money, char * name) {
    Node * oldHead = stack->head;
    // Add data to the top of the stack
    Node * newHead = addToHead(oldHead, money, name);
    // Head points to next player
    stack->head = newHead;
}

// Remove the top of the stack
void pop(Stack * stack) {
    // If stack is empty, return
    if (stack->head == NULL) {
        return;
    }
    Node * oldHead = stack->head;
    stack->head = removeHead(oldHead);
}

// Function to find out if the player leaving is also in the MVP stack
void popMVP(Stack * stack, Stack * stackMVP) {
    char * name1, * name2;
    int money1, money2;
    
    // Find the name and money of the player at the top of the stack
    name1 = top(stack);
    money1 = topValue(stack);
    // Find the name of the player at the top of the MVP stack
    name2 = top(stackMVP);
    money2 = topValue(stackMVP);
    
    // If the person leaving is also in the MVP stack, then remove the top of the MVP stack
    if (strcmp(name1, name2) == 0 && money1 == money2) {
        pop(stackMVP);
    }
}

// Determines the name on the top of the stack
char * top(Stack * stack) {
    Node * head = stack->head;
    if (head == NULL) {
        return NULL;
    }
    return head->name;
}

// Determines the money of the player on the top of the stack
int topValue(Stack * stack) {
    Node * head = stack->head;
    if(head == NULL) {
        return 0;
    }
    return head->money;
}
 
// Function to destroy all the memory left over from the stack
void destroyStack(Stack * stack) {
    if (stack->head == NULL) {
        return;
    }
    // Empty the stack
    while(stack->head != NULL) {
        pop(stack);
    }
    
    // Remove the stack memory
    free(stack);
}
