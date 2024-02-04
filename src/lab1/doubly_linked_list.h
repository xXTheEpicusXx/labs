typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

struct Node* createNode(int data);
void append(Node** head, int data);
void deleteNode(Node** head, int data);
void printListForward(Node* node);
void printListBackward(Node* node);