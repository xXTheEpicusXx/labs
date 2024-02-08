#define MAX_SIZE 100

typedef struct {
    int* array;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity);

int isFull(Stack* stack);

int isEmpty(Stack* stack);

void push(Stack* stack, int item);

int pop(Stack* stack);

int peek(Stack* stack);
