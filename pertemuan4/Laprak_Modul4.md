# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List(Bagian Pertama)</h1>
<p align="center">Raffy Dwi Anggara - 103112400252</p>

## Dasar Teori
C adalah bahasa pemrograman terstruktur yang membagi program dalam bentuk sejumlah blok. Tujuannya adalah untuk memudahkan dalam pembuatan dan pengembangan program. Program C++ biasa ditulis dengan nama ekstensi .CPP (dari kata C plus plus). Agar program ini dapat dijalankan (dieksekusi), program harus dikompilasi lebih dulu dengan menggunakan kompiler C++.[1]

### A. Materi pertemuan keempat 
Pada pertemuan keempat ini,mahasiswa diperkenalkan dengan ADT dan juga linked list dan diajarkan dalam pembuatan linked list ini dengan menggunakan ADT
#### 1. ADT
ADT merupakan sebuah konsep yang memisahkan antara bagian yang terlihat (interface) dengan yang tidak terlihat (implementasi). Interface sendiri merupakan bagian yang berisi nama nama atau fungsi operasi yang digunakan oleh pemogram. Sedangkan implementasi merupakan bagaimana operasi operasi tersebut dijalankan di dalam program.[2]
#### 2. Linked List
Linked list adalah salah satu bentuk struktur data yang berisi kumpulan data (node) yang tersusun secara sekuensial, saling sambung menyambung, dinamis, dan tidak terbatas.[3]


## Guided 

### 1. ADT Linked List (insert)

```C++
//list.h
//header guar digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ //node untuk isi dari linked listnya,isi setiap node adalah data & pointer new
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif

//list.cpp
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
} 

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//main.cpp
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
penjelasan singkat guided 1
Program ini berfungsi untuk membuat Linked List dengan fungsi insert dengan menambahkan node dan menampilkan hasil insert.

### 2. ADT Linked List (insert, delete, count, clear)

```C++
//list.h
//header guar digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ //node untuk isi dari linked listnya,isi setiap node adalah data & pointer new
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif

//list.cpp
#include "list.h"

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}

//main.cpp
#include "list.h"

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
penjelasan singkat guided 2
Program ini berfungsi sebagaai membuat ADT Linked List dengan beberapa fungsi tambahan dari sebelumnya yaitu fungsi untuk menghapus node, alokasi, manipulasi, dealokasi pada data dan menampilkan jumlah node setelah penghapusan.


## Unguided 

### 1. ![Screenshot Output Unguided 1_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan4/Modul4_Soal1.png)
![Screenshot Output Unguided 1_2](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan4/Modul4_Soal1(1).png)
```C++
//Singlylist.h
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;

struct Elmlist;  
typedef Elmlist* address; 

struct Elmlist {
    infotype data;
    address next;
};

struct List {
    address first;
};


void CreateList(List &L); 
address alokasi(infotype x);
void dealokasi(address P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif

//Singlylist.cpp
#include "Singlylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {

    L.first = Nil;
}

address alokasi(infotype x) { 
    address NewNode = new Elmlist ; 
    NewNode->data = x;
    NewNode->next = Nil;
    return NewNode;
}

void dealokasi(address p) {
    delete p;
}

void printInfo(List L) {
    address P = L.first;
    if (P == Nil) {
        cout << "List kosong" << endl;
    } else {
        cout << "Isi List: ";
        while (P != Nil) {
            cout << P->data << " ";
            P = P->next;
        }
        cout << endl;
    }
}

void insertFirst(List &L, address p) {
    p->next = L.first;
    L.first = p;
}

//main.cpp
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan4/output/Modul4_Output1.png)

penjelasan unguided 1
Program ini berfungsi untuk membuat ADT Single Linked List dengan fungsi insert dan menampilkan isi list yang sudah diisi oleh data. 

### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList(). Output yang diharapkan:
![Screenshot Output Unguided 2_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan4/Modul4_Soal2.png)
```C++
//Singlylist.h
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;

struct Elmlist;  
typedef Elmlist* address; 

struct Elmlist {
    infotype data;
    address next;
};

struct List {
    address first;
};


void CreateList(List &L); 
address alokasi(infotype x);
void dealokasi(address P);
void printInfo(List L);
void insertFirst(List &L, address P);

void delFirst(List &L);
void delLast(List &L);
void delAfter(List &L, address nodeHapus, address nodePrev);
int nbList(List L);
void deleteList(List &L);

#endif


//Singlylist.cpp
#include "Singlylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {

    L.first = Nil;
}

address alokasi(infotype x) { 
    address NewNode = new Elmlist ; 
    NewNode->data = x;
    NewNode->next = Nil;
    return NewNode;
}

void dealokasi(address p) {
    delete p;
}

void printInfo(List L) {
    address P = L.first;
    int jumlah = 0;
    if (P == Nil) {
        cout << "List kosong" << endl;
    } else {
        cout << " ";
        while (P != Nil) {
            cout << P->data << " ";
            jumlah++;
            P = P->next;
        }
        cout << endl;
        cout << "Jumlah node : " << jumlah << endl;
    }
}

void insertFirst(List &L, address p) {
    p->next = L.first;
    L.first = p;
}

void delFirst(List &L){
    address nodeHapus;
    if (L.first != Nil) {
        nodeHapus = L.first;
        L.first = L.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(List &L){
    address nodeHapus, nodePrev;
    if(L.first != Nil){
        nodeHapus = L.first;
        if(nodeHapus->next == Nil){
            L.first = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(List &L, address nodeHapus, address nodePrev){
    if(L.first == Nil){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

int nbList(List L) {
    int count = 0;
    address nodeBantu = L.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

void deleteList(List &L){
    address nodeBantu, nodeHapus;
    nodeBantu = L.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    L.first = Nil; 
    cout << endl << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : 0" << endl;
}

//main.cpp
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    delFirst(L);
    delLast(L);
    delAfter(L, NULL, L.first);

    printInfo(L);

    deleteList(L);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/pertemuan4/output/Modul4_Output2.png)


penjelasan unguided 2
Program ini berfungsi untuk menghapus angka 9, 2 dan 8 dengan fungsi deletefirst(), deleteLast(), dan deleteAfter() lalu menampilkan jumlah node yang tersimpan dan menghapus seluruh list dan menampilkan hasil nodenya.

## Kesimpulan
Pada pembelajaran kali ini, kita belajar tentang beberapa fungsi yaitu deletefirst, deleteafter dan sebagainya dalam menghapus node yang telah dibuat. Dan kita menggunakan ADT dalam programnya.

## Referensi
[1] Konsep Dasar Algoritma dan Pemograman Menggunakan C++ Chapter#1. Diakses pada 28 September 2025 melalui https://repository.unpkediri.ac.id/2466/1/55201_0701107802.pdf.
[2] Adding performance information to ADT interfaces. Diakses pada 12 Oktober 2025 melalui https://dl.acm.org/doi/abs/10.1145/185087.185108.
[3]ALGORITMA & PEMROGRAMAN. Diakses pada 19 Oktober 2025 melalui https://repository.unikom.ac.id/35520/1/Linked%20List.pdf.
