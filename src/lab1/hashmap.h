#define SIZE 100

// Структура для хранения элемента в хэш таблице
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

// Структура для хэш таблицы
typedef struct {
    struct Node* array[SIZE];
} HashTable;

struct Node* createNode(int key, int value);
void initHashTable( HashTable* ht);
int hash(int key);
void insert( HashTable* ht, int key, int value);
int search( HashTable* ht, int key);
void delete( HashTable* ht, int key);