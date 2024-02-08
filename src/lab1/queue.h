#define MAX_SIZE 100

typedef struct {
    int* array;
    int front, rear, size, capacity;
} Queue;

Queue* createQueue(int capacity);

int isFull(Queue* queue);

int isEmpty(Queue* queue);

void enqueue(Queue* queue, int item);

int dequeue(Queue* queue);

int front(Queue* queue);

int rear(Queue* queue);