typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* createNode(int data);
void append(Node** head, int data);
void deleteNode(Node** head, int data);
void printList(Node* node);
