/** Struct to define a stack; each entry can hold a pointer to anything.
 */
struct tnode {
  struct tnode *leftChild;
  int data;
  struct tnode *rightChild;
};

typedef struct tnode Tnode;

// Function prototypes

void add_tnode(struct tnode **src, int num);
void preorder(struct tnode *src);
void inorder(struct tnode *src);
void deletePre(struct tnode *src);
void deleteOrder(struct tnode *src);
void postorder(struct tnode *src);
void deletePost(struct tnode *src);
int rand_gen(void);
void populate_array(int* a, int arraySize);
