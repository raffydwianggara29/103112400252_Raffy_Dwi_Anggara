#ifndef BST_H
#define BST_H
#include <string>
#define Nil NULL

using namespace std;

typedef struct BST *node;

struct BST{ //nama struct BST
    int idProduk;
    string namaProduk;
    int stok;
    node left;
    node right;
};

typedef node BinTree; //alias tree = BinTree (merujuk ke node root dari BST)

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByID(BinTree tree, int idProduk);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int idProduk);

void deleteTree(BinTree &tree);
node findMin(BinTree tree);
node findMax(BinTree tree);

#endif