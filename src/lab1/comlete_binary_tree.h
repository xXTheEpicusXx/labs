typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data);

void insert(Node** root, int data);

void inorderTraversal(Node* root);
