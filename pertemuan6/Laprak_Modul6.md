# <h1 align="center">Laporan Praktikum Modul 6 - Doubly Linked List (Bagian Pertama)</h1>
<p align="center">Raffy Dwi Anggara - 103112400252</p>

## Dasar Teori
C adalah bahasa pemrograman terstruktur yang membagi program dalam bentuk sejumlah blok. Tujuannya adalah untuk memudahkan dalam pembuatan dan pengembangan program. Program C++ biasa ditulis dengan nama ekstensi .CPP (dari kata C plus plus). Agar program ini dapat dijalankan (dieksekusi), program harus dikompilasi lebih dulu dengan menggunakan kompiler C++.[1]

### A. Materi pertemuan 6
Pada materi kali ini,kita akan membuat fungsi delete dan search dengan menggunakan fungsi pada doubly linked list
#### 1. Doubly linked list
Doubly Linked List (DLL) merupakan struktur data yang terdiri dari node-node yang terhubung secara berpasangan, di mana setiap node memiliki pointer ke node sebelumnya (prev) dan node berikutnya (next). DLL menawarkan beberapa keunggulan dibandingkan dengan Single Linked List (SLL),  terutama  dalam  hal  operasi  insertion  dan  deletion.[2]
#### 2. Delete
Pada Doubly linked list, ada beberapa cara fungsi delete, yaitu deleteFirts, deleteLast, dan deleteAfter. DeleteFirts adalah operasi untuk menghapus data pada posisi pertama, deleteLast merupakan menghapus data pada posisi terakhir, sedangkan deleteAfter adalah penghapusan data di tengah linked list.[3]
#### 3. Searching
Pencarian dilakukan dengan memeriksa data yang ada dalam linked list dengan data yang dicari. Pencarian dilakukan dari data pertama sampai data ditemukan atau pointer pencari (bantu) telah mencapai akhir dari list yang menandakan bahwa data yang dicari tidak ditemukan.[3]

## Guided 

### 1. Doubly Linked List pada list makanan

```C++
//listMakanan.h
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif

//listMakanan.cpp
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//main.cpp
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```
penjelasan singkat guided 1
Program ini berfungsi untuk menginputkan beberapa buah dengan fungsi insert dan mengubah urutannya dengan fungsi updatefirst, updatelast, dan update before
### 2. Doubly linked list dan mencari data dengan menggunakan fungsi search dan delete

```C++
//listMakanan.h
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

// Searching
void findByName(linkedlist List, string nama);
void findByJenis(linkedlist List, string jenis);
void findByMinRating(linkedlist List, float minRating);

// Delete
void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);
void deleteBefore(linkedlist &List, address nodeNext);

void deleteNode(linkedlist &List, address target);
void deleteByName(linkedlist &List, string nama);

#endif

//listMakanan.cpp
#include "listMakanan.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// SEARCHING
void findByName(linkedlist List, string nama){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.nama == nama){
            cout << "Ditemukan (berdasarkan nama):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan nama \"" << nama << "\" tidak ditemukan." << endl;
}

void findByJenis(linkedlist List, string jenis){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.jenis == jenis){
            cout << "Ditemukan (berdasarkan jenis):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan jenis \"" << jenis << "\" tidak ditemukan." << endl;
}

void findByMinRating(linkedlist List, float minRating){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.rating >= minRating){
            cout << "Ditemukan (rating >= " << minRating << "):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Tidak ada data dengan rating >= " << minRating << "." << endl;
}

// DELETE
void deleteFirst(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.first;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.first = pDel->next;
        List.first->prev = Nil;
        pDel->next = Nil;
    }
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi pertama." << endl;
    dealokasi(pDel);
}

void deleteLast(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.last;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.last = pDel->prev;
        List.last->next = Nil;
        pDel->prev = Nil;
    }
    pDel->next = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi terakhir." << endl;
    dealokasi(pDel);
}

void deleteAfter(linkedlist &List, address Prev){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(Prev == Nil || Prev->next == Nil){
        cout << "Node sebelumnya (Prev) tidak valid atau tidak ada node setelahnya!" << endl;
        return;
    }
    if(Prev->next == List.last){
        deleteLast(List);
        return;
    }
    address pDel = Prev->next;
    Prev->next = pDel->next;
    pDel->next->prev = Prev;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus setelah node " << Prev->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteBefore(linkedlist &List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(nodeNext == Nil || nodeNext->prev == Nil){
        cout << "Node setelahnya (nodeNext) tidak valid atau tidak ada node sebelumnya!" << endl;
        return;
    }
    if(nodeNext->prev == List.first){
        deleteFirst(List);
        return;
    }
    address pDel = nodeNext->prev;
    nodeNext->prev = pDel->prev;
    pDel->prev->next = nodeNext;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus sebelum node " << nodeNext->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteNode(linkedlist &List, address target){
    if(isEmpty(List) == true || target == Nil){
        cout << "Target tidak valid atau list kosong!" << endl;
        return;
    }
    if(target == List.first){
        deleteFirst(List);
    } else if(target == List.last){
        deleteLast(List);
    } else {
        address L = target->prev;
        address R = target->next;
        L->next = R;
        R->prev = L;
        target->next = Nil;
        target->prev = Nil;
        cout << "Node " << target->isidata.nama << " berhasil dihapus dari tengah list." << endl;
        dealokasi(target);
    }
}

void deleteByName(linkedlist &List, string nama){
    if(isEmpty(List)){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }

    address target = List.first;
    while(target != Nil && target->isidata.nama != nama){
        target = target->next;
    }
    if(target == Nil){
        cout << "Node dengan nama \"" << nama << "\" tidak ditemukan." << endl;
        return;
    }

    deleteNode(List, target);
    cout << "Node dengan nama \"" << nama << "\" telah dihapus dan didealokasi." << endl;
}

//main.cpp
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeA);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    cout << endl;

    findByName(List, "Nasgor");

    deleteByName(List, "Nasgor");
    deleteFirst(List);
    deleteBefore(List, nodeE);

    cout << endl << "--- Isi List Setelah Delete ---" << endl;
    printList(List);

    return 0;
}
```
penjelasan singkat guided 2
Program ini berfungsi untuk menampilkan hasil update, setelah itu mencari data dengan fungsi searchbyname dan menghapus data dengan data, menghapus data berdasarkan data yang pertama dan menghapus dataBefore.

## Unguided 

### 1. ![Screenshot Output Unguided 1_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan6/Soal1.png)

```C++
//Doublylist.h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct kendaraan{
    string nopol;
    string warna; 
    int thnBuat; 
};

typedef kendaraan infotype;

typedef struct node *address;

struct node{
    infotype info;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nopol, string warna, int thnBuat);
void dealokasi(address &P);
void printInfo(linkedlist List);
void insertLast(linkedlist &List, address P);

#endif

//Doublylist.cpp
#include "Doublylist.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(linkedlist List) {
    return (List.first == Nil);
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

address alokasi(string nopol, string warna, int thnBuat) {
    address nodeBaru = new node;
    nodeBaru->info.nopol = nopol;
    nodeBaru->info.warna = warna;
    nodeBaru->info.thnBuat = thnBuat;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &P) {
    P->next = Nil;
    P->prev = Nil;
    delete P;
    P = Nil;
}

void printInfo(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else {
        address bantu = List.last;
        cout << "DATA LIST 1" << endl;
        cout << endl;
        while (bantu != Nil) {
            cout << "no polisi : " << bantu->info.nopol << endl;
            cout << "warna     : " << bantu->info.warna << endl;
            cout << "tahun     : " << bantu->info.thnBuat << endl;
            bantu = bantu->prev;
        }
    }
}

void insertLast(linkedlist &List, address P) {
    bool duplikat = false;
    address bantu = List.first;
    while (bantu != Nil) {
        if (bantu->info.nopol == P->info.nopol) {
            duplikat = true;
            break;
        }
        bantu = bantu->next;
    }

    cout << "masukkan nomor polisi: " << P->info.nopol << endl;
    cout << "masukkan warna kendaraan: " << P->info.warna << endl;
    cout << "masukkan tahun kendaraan: " << P->info.thnBuat << endl;

    if (duplikat) {
        cout << "nomor polisi sudah terdaftar" << endl;
        cout << endl;
        dealokasi(P);
        return;
    }

    cout << endl;

    if (isEmpty(List)) {
        List.first = P;
        List.last = P;
    } else {
        P->prev = List.last;
        List.last->next = P;
        List.last = P;
    }
}

//main.cpp
#include "Doublylist.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD = Nil;
    createList(List);

    infotype dtPlat;

    nodeA = alokasi("D001", "hitam", 90);
    nodeB = alokasi("D003", "putih", 70);
    nodeC = alokasi("D001", "merah", 80);
    nodeD = alokasi("D004", "kuning", 90);

    insertLast(List, nodeA);
    insertLast(List, nodeB);
    insertLast(List, nodeC);
    insertLast(List, nodeD);
    cout << endl;

    cout << "--- Data List 1 ---" << endl;
    printInfo(List);
    cout << endl;

    return 0;
}
```
### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_2](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan6/output/output1.png)

penjelasan unguided 1 
Program ini berfungsi untuk menambahkan nomor polisi dengan warna dan tahun kendaraan. Jika terdapat nomor polisi yang sama,output akan mencetak "nomor polisi sudah terdaftar" pada akhiran inputan nomor polisi yang akan diperiksa di fungsi if duplikat di dalam fungsi insertlast. Setelah itu, nomor polisi yang sama tadi tidak ditampilkan di data list sehingga hanya mencetak 3 inputan dari 4 inputan.

### 2. ![Screenshot Output Unguided 2_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan6/soal2.png)

```C++
//Doublylist.h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct kendaraan{
    string nopol;
    string warna; 
    int thnBuat; 
};

typedef kendaraan infotype;

typedef struct node *address;

struct node{
    infotype info;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nopol, string warna, int thnBuat);
void dealokasi(address &P);
void printInfo(linkedlist List);
void insertLast(linkedlist &List, address P);

void findElm(linkedlist List, string nopol);

#endif

//Doublylist.cpp
#include "Doublylist.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(linkedlist List) {
    return (List.first == Nil);
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

address alokasi(string nopol, string warna, int thnBuat) {
    address nodeBaru = new node;
    nodeBaru->info.nopol = nopol;
    nodeBaru->info.warna = warna;
    nodeBaru->info.thnBuat = thnBuat;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &P) {
    P->next = Nil;
    P->prev = Nil;
    delete P;
    P = Nil;
}

void printInfo(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else {
        address bantu = List.last;
        cout << "DATA LIST 1" << endl;
        cout << endl;
        while (bantu != Nil) {
            cout << "no polisi : " << bantu->info.nopol << endl;
            cout << "warna     : " << bantu->info.warna << endl;
            cout << "tahun     : " << bantu->info.thnBuat << endl;
            bantu = bantu->prev;
        }
    }
}

void insertLast(linkedlist &List, address P) {
    bool duplikat = false;
    address bantu = List.first;
    while (bantu != Nil) {
        if (bantu->info.nopol == P->info.nopol) {
            duplikat = true;
            break;
        }
        bantu = bantu->next;
    }

    cout << "masukkan nomor polisi: " << P->info.nopol << endl;
    cout << "masukkan warna kendaraan: " << P->info.warna << endl;
    cout << "masukkan tahun kendaraan: " << P->info.thnBuat << endl;

    if (duplikat) {
        cout << "nomor polisi sudah terdaftar" << endl;
        cout << endl;
        dealokasi(P);
        return;
    }

    cout << endl;

    if (isEmpty(List)) {
        List.first = P;
        List.last = P;
    } else {
        P->prev = List.last;
        List.last->next = P;
        List.last = P;
    }
}

void findElm(linkedlist List, string nopol){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address P = List.first;
    while(P != Nil){
        if(P->info.nopol == nopol){
            cout << "Masukkan nomor polisi yang dicari : " << P->info.nopol << endl;
            cout << "Nomor Polisi : " << P->info.nopol << endl;
            cout << "Warna        : " << P->info.warna << endl;
            cout << "Tahun        : " << P->info.thnBuat << endl;
            return;
        }
        P = P->next;
    }
}

//main.cpp
#include "Doublylist.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD = Nil;
    createList(List);

    infotype dtPlat;

    nodeA = alokasi("D001", "hitam", 90);
    nodeB = alokasi("D003", "putih", 70);
    nodeC = alokasi("D001", "merah", 80);
    nodeD = alokasi("D004", "kuning", 90);

    insertLast(List, nodeA);
    insertLast(List, nodeB);
    insertLast(List, nodeC);
    insertLast(List, nodeD);
    cout << endl;

    cout << "--- Data List 1 ---" << endl;
    printInfo(List);
    cout << endl;

    findElm(List, "D001");
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_2](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan6/output/Output2.png)

penjelasan unguided 2
Program ini berfungsi untuk mencari plat nomer D001 lalu menampilkan nomor polisi nya dengan warna dan tahun pembuatannya dengan menggunakan searching dengan nama fungsi findElm.

### 3. ![Screenshot Output Unguided 3_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan6/soal3.png)


```C++
//Doublylist.h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct kendaraan{
    string nopol;
    string warna; 
    int thnBuat; 
};

typedef kendaraan infotype;

typedef struct node *address;

struct node{
    infotype info;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nopol, string warna, int thnBuat);
void dealokasi(address &P);
void printInfo(linkedlist List);
void insertLast(linkedlist &List, address P);

void findElm(linkedlist List, string nopol);

void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);

#endif

//Doublylist.cpp
#include "Doublylist.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(linkedlist List) {
    return (List.first == Nil);
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

address alokasi(string nopol, string warna, int thnBuat) {
    address nodeBaru = new node;
    nodeBaru->info.nopol = nopol;
    nodeBaru->info.warna = warna;
    nodeBaru->info.thnBuat = thnBuat;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &P) {
    P->next = Nil;
    P->prev = Nil;
    delete P;
    P = Nil;
}

void printInfo(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else {
        address bantu = List.last;
        cout << "DATA LIST 1" << endl;
        cout << endl;
        while (bantu != Nil) {
            cout << "no polisi : " << bantu->info.nopol << endl;
            cout << "warna     : " << bantu->info.warna << endl;
            cout << "tahun     : " << bantu->info.thnBuat << endl;
            bantu = bantu->prev;
        }
    }
}

void insertLast(linkedlist &List, address P) {
    bool duplikat = false;
    address bantu = List.first;
    while (bantu != Nil) {
        if (bantu->info.nopol == P->info.nopol) {
            duplikat = true;
            break;
        }
        bantu = bantu->next;
    }

    cout << "masukkan nomor polisi: " << P->info.nopol << endl;
    cout << "masukkan warna kendaraan: " << P->info.warna << endl;
    cout << "masukkan tahun kendaraan: " << P->info.thnBuat << endl;

    if (duplikat) {
        cout << "nomor polisi sudah terdaftar" << endl;
        cout << endl;
        dealokasi(P);
        return;
    }

    cout << endl;

    if (isEmpty(List)) {
        List.first = P;
        List.last = P;
    } else {
        P->prev = List.last;
        List.last->next = P;
        List.last = P;
    }
}

void findElm(linkedlist List, string nopol){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address P = List.first;
    while(P != Nil){
        if(P->info.nopol == nopol){
            cout << "Masukkan nomor polisi yang dicari : " << P->info.nopol << endl;
            cout << "Nomor Polisi : " << P->info.nopol << endl;
            cout << "Warna        : " << P->info.warna << endl;
            cout << "Tahun        : " << P->info.thnBuat << endl;
            return;
        }
        P = P->next;
    }
}

void deleteFirst(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.first;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.first = pDel->next;
        List.first->prev = Nil;
        pDel->next = Nil;
    }
    pDel->prev = Nil;
    dealokasi(pDel);
}

void deleteLast(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.last;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.last = pDel->prev;
        List.last->next = Nil;
        pDel->prev = Nil;
    }
    pDel->prev = Nil;
    dealokasi(pDel);
}

void deleteAfter(linkedlist &List, address Prev){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(Prev == Nil || Prev->next == Nil){
        cout << "Node sebelumnya (Prev) tidak valid atau tidak ada node setelahnya!" << endl;
        return;
    }
    if(Prev->next == List.last){
        deleteLast(List);
        return;
    }
    address pDel = Prev->next;
    Prev->next = pDel->next;
    pDel->next->prev = Prev;
    pDel->next = Nil;
    pDel->prev = Nil;
    dealokasi(pDel);
}

//main.cpp
#include "Doublylist.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD = Nil;
    createList(List);

    infotype dtPlat;

    nodeA = alokasi("D001", "hitam", 90);
    nodeB = alokasi("D003", "putih", 70);
    nodeC = alokasi("D001", "merah", 80);
    nodeD = alokasi("D004", "kuning", 90);

    insertLast(List, nodeA);
    insertLast(List, nodeB);
    insertLast(List, nodeC);
    insertLast(List, nodeD);
    cout << endl;

    cout << "--- Data List 1 ---" << endl;
    printInfo(List);
    cout << endl;

    findElm(List, "D001");  

 string hapusNopol = "D003";
    cout << "Masukkan Nomor Polisi yang akan dihapus : " << hapusNopol << endl;

    address P = List.first;
    address prev = Nil;

    while (P != Nil && P->info.nopol != hapusNopol) {
        prev = P;
        P = P->next;
    }

    if (P == Nil) {
        cout << "Data dengan nomor polisi " << hapusNopol << " tidak ditemukan." << endl;
    } else {
        if (P == List.first) {
            deleteFirst(List);
        } else if (P == List.last) {
            deleteLast(List);
        } else {
            deleteAfter(List, prev);
        }
        cout << "Data dengan nomor polisi " << hapusNopol << " berhasil dihapus." << endl;
    }

    cout << endl;
    printInfo(List);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_2](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan6/output/output3.png)

penjelasan unguided 3
Program ini berfungsi unutuk menghapus nomor polisi D003 dengan menggunakan deleteFirts, deleteLast, dan deleteAfter. nomor polisi ini akan dicocokkan dengan beberapa fungsi delete dan proses pencocokan ini di dalam main. Di program ini,ternyata D003 masuk ke dalam fungsi deleteAfter karena letaknya yang bukan di inputan pertama dan bukan di inputan terakhir. Setelah itu output yang ditampilkan hanya 2 yaitu D004 dan D001.

## Kesimpulan
Pada pembelajaran kali ini, kita akan dihadapkan dengan beberapa fungsi pada double linked list yang hampir sama dengan single linked list. Perbedaannya adalah di double linked list ini kita akan menggunakan first dan last pada pembuatannya. Dan kita dapat mencari dengan fungsi searching dan dapat melakukan penghapusan pada data dengan 3 fungsi yang berbeda yaitu deleteFirst, deleteLast, dan deleteAfter.

## Referensi
[1] Konsep Dasar Algoritma dan Pemograman Menggunakan C++ Chapter#1. Diakses pada 28 September 2025 melalui https://repository.unpkediri.ac.id/2466/1/55201_0701107802.pdf.
[2]Penggunaan Algoritma Doubly Linked List Untuk Insertion Dan Deletion Agung Wijoyo, Ahmad Farhan, Lalu AkbarPrayudi, Muhamad Fiqih,Rendi Dwi Santoso, Ricky Tri Setiawan Putra, Teguh Arifin. Diakses pada 1 November 2025 melalui https://jurnalmahasiswa.com/index.php/jriin/article/view/1282/762.
[3]Mukharil Bachtiar, Adam. "Bab Vi-Double Linked List." (2010). Diakses pada 1 November 2025 melalui https://repository.unikom.ac.id/32396/1/Bab%20VI%20-%20Double%20Linked%20List.pdf.
