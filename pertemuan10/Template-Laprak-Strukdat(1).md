# <h1 align="center">Laporan Praktikum Modul 10 - TREE(BAGIANPERTAMA)</h1>
<p align="center">Raffy Dwi Anggara - 103112400252</p>

## Dasar Teori
Teori pohon/tree ini sebenarnya adalah suatu mekanisme penyelesaian suatu masalah dengan menganalogikan permasalahan tersebut kedalam struktur pohon untuk memudahkan pencarian solusi masalah tersebut.Binary Search Tree adalah sebuah pohon biner yang mempunyai properti tambahan.Properti ini adalah : 1. Semua elemen pada upapohon (subpohon) kiri nilainya lebih kecil atau sama dengan nilai akar. 2. Semua elemen pada upapohon kanan nilainya lebih besar dari nilai akar. 3. Upapohon kiri dan kanan merupakanBinary Search Tree.[1]

### A. Materi Modul 10
Pada pertemuan ke 10 ini, kita akan membahas fungsi fungsi pada struktur tree pada BST (Binary Search Tree)
#### 1. Insert
Penambahan ke pohon kosong tentunya cukup mudah, sedangkan untuk penambahan ke Binary Search Tree yang sudah terisi maka kita harus membandingkannya dengan kunci dari akar pohon yang bersangkutan. Jika kuncinya lebih kecil maka tambahkan simpul baru ke upapohon kiri, jika lebih besar maka tambahkan ke upapohon kanan, dan jika kunci nya sama atau simpul dengan kunci yang ingin ditambahkan sudah ada, maka tidak akan melakukan apa-apa.[1]
#### 2. Searh
Untuk melakukan operasi pencarian pada Binary Search Tree, pertama-tama kita bandingkan dahulu kunci data yang ingin kita cari dengan kunci dari data akar, jika tidak cocok maka cari pada upapohon kiri atau kanan sampai kunci data yang ingin dicari cocok.[1]
#### 3. Delete
Menghapus simpul adalah operasi lain yang diperlukan untuk memelihara pohon pencarian biner. Tingkat kompleksitas dalam melakukan operasi ini bergantung pada posisi simpul yang akan dihapus di dalam pohon.[2]
#### 4. Most Left
Fungsi mostLeft() mencari node paling kiri dengan mengikuti pointer left child secara rekursif hingga mencapai null.[3]
#### 5. Most Right
Fungsi mostRight() mencari node paling kanan dengan mengikuti pointer right child.[3]
#### 6. Pre-Order
Proses Traverse yang melakukan tahapan cetak node yang dikunjungi, kunjungi left node , kunjungi right node.[4]
#### 7. In-Order
Proses Traverse yang melakukan tahapan kunjungi left node, cetak node yang dikunjungi, kunjungi right node.[4]
#### 8. Post-Order
Proses Traverse yang melakukan tahapan kunjungi left node, kunjungi right node, cetak node yang dikunjungi[4]

## Guided 

### 1. BST (Binary Searh Tree) dengan beberapa fungsi

```C++
//bst.h
#ifndef BST_H
#define BST_H
#define Nil NULL

using namespace std;

typedef struct BST *node; //alias pointer = node

struct BST{ //nama struct BST
    int angka;
    node left;
    node right;
};

typedef node BinTree; //alias tree = BinTree (merujuk ke node root dari BST)

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);

#endif

//bst.cpp
#include "bst.h"
#include <iostream>

using namespace std;

//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){ //tengah - kiri - kanan atau root - child kiri - child kanan
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){ //kiri - tengah - kanan atau child kiri - root - child kanan
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){ //kiri - kanan - tengah atau child kiri - child kanan - root
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}

//main.cpp
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```
penjelasan singkat guided 1
Program ini berfungsi untuk membuat BST dengan menggunakan menu yang tersedia pada main.cpp. Menu pada program ini ada insert node sebagai memasukkan node ke dalam tree, delete node untuk menghapus node yang ada di tree, search tree sebagai mencari data/node yang ada di tree, dapat menampilkan tree secara preOrder,Inorder,dan PostOrder, size tree sebagai menghitung jumlah node, height tree sebagai mencari ketinggian tree, dapat menampilkan secara mostright dan mostleft, serta menu untuk menghapus seluruh tree.
## Unguided 

### 1. ![Screenshot Output Unguided 1_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan10/soal1.png)

```C++
//bstree.h
#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL

using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node* left;
    Node* right;
};

typedef Node* address;

address alokasi(infotype X);
void insertNode(address &root, infotype X);
address findNode(infotype X, address &root);
void printInorder(address root);

#endif

//bstree.cpp
#include "bstree.h"
#include <iostream>
using namespace std;

address alokasi(infotype X){
    address nodeBaru = new Node;
    nodeBaru->info = X;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void insertNode(address &root, infotype X){
    if(root == Nil){
        root = alokasi(X);
    } else if (X < root->info){
        insertNode(root->left, X);
    } else if (X > root->info){
        insertNode(root->right, X);
    }
}

address findNode(infotype X, address &root){
    if(root == Nil){
        cout << "Tree kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(X < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if (X > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if (X == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu = true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data: " << nodeBantu->info << endl;
        }
    }
    return Nil;
}

void printInorder(address root){
    if(root != Nil){
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

//main.cpp
#include <iostream>
#include "bstree.h"
using namespace std;
int main()
{
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);
    printInorder(root);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_2](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan10/output/output1.png)

penjelasan unguided 1 
Program ini berfungsi untuk membuat tree secara BST dengan menggunakan alokasi dan insert sebagai penambahan data/node, dan meng-output kan inputan tadi secara inOrder(yaitu mengunjungi subtree kiri, lalu mencetak nilai dari node saat ini, dan mengunjungi subtree kanan).
### 2. ![Screenshot Output Unguided 2_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan10/soal2.png)

```C++
//bstree.h
#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL

using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node* left;
    Node* right;
};

typedef Node* address;

address alokasi(infotype X);
void insertNode(address &root, infotype X);
address findNode(infotype X, address &root);
void printInorder(address root);
int hitungJumlahNode(address root);
int hitungTotalInfo(address root, int start);
int hitungKedalaman(address root, int start);

#endif

//bstree.cpp
#include "bstree.h"
#include <iostream>
using namespace std;

address alokasi(infotype X){
    address nodeBaru = new Node;
    nodeBaru->info = X;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void insertNode(address &root, infotype X){
    if(root == Nil){
        root = alokasi(X);
    } else if (X < root->info){
        insertNode(root->left, X);
    } else if (X > root->info){
        insertNode(root->right, X);
    }
}

address findNode(infotype X, address &root){
    if(root == Nil){
        cout << "Tree kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(X < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if (X > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if (X == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu = true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data: " << nodeBantu->info << endl;
        }
    }
    return Nil;
}

void printInorder(address root){
    if(root != Nil){
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

int hitungJumlahNode(address root){ //mengembalikan jumlah semua node
    if(root == Nil){
        return 0;
    } else {
        return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
    }
    cout << endl;
}

int hitungTotalInfo(address root, int start){
    if (root == Nil){
        return 0;
    } else {
        int total = root->info;
        return total + hitungTotalInfo(root->left, start) + hitungTotalInfo(root->right, start);
    }
}

int hitungKedalaman(address root, int start){
    if (root == Nil){
        return start;
    } else {
        int h1 = hitungKedalaman(root->left, start + 1);
        int h2 = hitungKedalaman(root->right, start + 1);
        int maxHeight;
        if (h1 > h2){
            maxHeight = h1;
        } else {
            maxHeight = h2;
        }
        return maxHeight;
    }
}

//main.cpp
#include <iostream>
#include "bstree.h"
using namespace std;
int main()
{
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);
    printInorder(root);
    cout << "\n";
    cout << "Kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "Jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "Total : " << hitungTotalInfo(root, 0) << endl;
    return 0;
}
```
### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_2](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan10/output/output2.png)

penjelasan unguided 2
Program ini berfungsi untuk membuat BST (Binary Search Tree) dengan menggunakan alokasi dan insertNode untuk menambah data tree/node lalu memberi output secara InOrder dan dapat menghitung jumlah node dengan fungsi hitungJumlahNode, menghitung total node dengan fungsi hitungTotalInfo, serta dapat menghitung kedalaman tree. Perbedaan menghitung kedalaman dan ketinggian terletak pada jaraknya dimana jika kedalaman menghitung sebuah jarak antara node tersebut dari root, sedangkan ketinggian adalah menghitung jarak antara node dengan ke lead(daun) terjauh di bawahnya.

### 3. ![Screenshot Output Unguided 3_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan10/soal3.png)

```C++
//bstree.h
#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL

using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node* left;
    Node* right;
};

typedef Node* address;

address alokasi(infotype X);
void insertNode(address &root, infotype X);
address findNode(infotype X, address &root);
void printInorder(address root);
void preOrder(address root);
void postOrder(address root);

#endif

//bstree.cpp
#include "bstree.h"
#include <iostream>
using namespace std;

address alokasi(infotype X){
    address nodeBaru = new Node;
    nodeBaru->info = X;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void insertNode(address &root, infotype X){
    if(root == Nil){
        root = alokasi(X);
    } else if (X < root->info){
        insertNode(root->left, X);
    } else if (X > root->info){
        insertNode(root->right, X);
    }
}

address findNode(infotype X, address &root){
    if(root == Nil){
        cout << "Tree kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(X < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if (X > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if (X == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu = true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data: " << nodeBantu->info << endl;
        }
    }
    return Nil;
}

void printInorder(address root){
    if(root != Nil){
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

void preOrder(address root){
    if(root == Nil){
        return;
    }
    cout << root->info << " - ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(address root){
    if(root == Nil){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->info << " - ";
}

//main.cpp
#include <iostream>
#include "bstree.h"
using namespace std;
int main()
{
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root, 6);
    insertNode(root, 7);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 1);
    cout << "Tampilkan preOrder : " ;
             preOrder(root); 
             cout << endl;
    cout << "Tampilkan postOrder : "; 
             postOrder(root);
             cout << endl;
    return 0;
}
```
### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_2](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan10/output/output3.png)

penjelasan unguided 3
Program ini berfungsi untuk membuat tree (BST) lalu dapat menampilkan output dari tree tersebut secara preOrder(yaitu mengunjungi root dan mencetak/ menampilkan node terlebih dahulu , lalu mengunjungi subtree kiri, setelah itu baru mengunjungi subtree kanan), serta menampilkan output secara postOrder(yaitu mengunjungi subtree kiri terlebih dahulu, lalu mengunjungi subtre kanan, dan node/root di proses/dicetak dan ditampilkan di akhir).

## Kesimpulan
Pada materi tree kali ini, kita membahas beberapa fungsi yang ada pada tree seperti insert dengan menggunakan alokasi dan insertNode, lalu menghitung beberapa jumlah node dengan fungsi hitungJumlahNode,hitungTotalInfo, serta menghitung kedalaman tree dengan fungsi hitungKedalaman. walau memghitung kedalaman dan ketinggian sekilas terlihat sama dalam analogi, tetapi implementasinya berbeda dengan apa yang dianalogikan, sehingga menghitung kedalaman dan ketinggan pada suatu tree adalah 2 fungsi yang berbeda.

## Referensi
[1] Akbar, Khoirush Sholih Ridhwaana. "Penerapan Teori Pohon Dalam Kajian Struktur Data." Insitut Teknologi Bandung (2006). 
[2] Drozdek, Adam. Data Structures and algorithms in C++. Thomson Course Technology, 2005.
[3] https://www.geeksforgeeks.org/dsa/find-maximum-or-minimum-in-binary-tree/
[4] Memahami Konsep Tree dalam Struktur Data Lengkap dengan Source Code Programnya https://daismabali.medium.com/memahami-konsep-tree-dalam-struktur-data-lengkap-dengan-source-code-programnya-acbd0a8733d6
