struct node {
    int color;
    int type;
    int x;
    int y;
    struct node* next;
};

typedef struct node* nodeRef;

// Crea un nuevo nodo con valor 'value' y retorna la referencia.
nodeRef newNode(int x, int y, int color, int type);

// libera la memoria de todos los elementos de una lista exceptuando el primero (first)
void DestroyList(nodeRef first);

// Agrega un nodo 'newNode' a la lista
void addNode(nodeRef node, nodeRef newNode);

// Elimina el nodo 'nodeToRemove' de la lista, regresa 1 si se eliminó, 0 si no se eliminó.
int RemoveNode(nodeRef *node, int nodeValue);