# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Raffy Dwi Anggara - 103112400252</p>

## Dasar Teori
C adalah bahasa pemrograman terstruktur yang membagi program dalam bentuk sejumlah blok. Tujuannya adalah untuk memudahkan dalam pembuatan dan pengembangan program. Program C++ biasa ditulis dengan nama ekstensi .CPP (dari kata C plus plus). Agar program ini dapat dijalankan (dieksekusi), program harus dikompilasi lebih dulu dengan menggunakan kompiler C++.[1]

### A. Pada materi kali ini,kita akan membahas tentang single linked list dan fungsi update dan searching pada single linked list
...
#### 1. Single Linked List
Single Linked list adalah daftar terhubung yang setiap simpul pembentuknya mempunyai satu rantai(link) ke simpul lainnya.simpul yang saling terhubung satu sama lain dengan menggunakan pointer.[2]
#### 2. Update
Update merupakan sebuah fungsi yang berfungsi sebagai mengubah elemen yang ditunjuk dengan pointer dan diisi dari sesuatu.[3]
#### 3. Searching
Searching adalah tindakan mengambil data dari kumpulan data berdasarkan kunci (key) atau referensi data. Misalnya, jika ingin menghapus atau mengubah data tertentu pada suatu file, maka harus terlebih dahulu menentukan apakah data tersebut ada dalam file. Jika ada, maka data tersebut dapat diubah / dihapus.[4]

## Guided 

### 1. Single linked list (sudah termasuk update dan searching)

```C++
//listbuah.h
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
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

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (part 2 - searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif

//listbuah.cpp
#include "listBuah.h"
#include <iostream>
using namespace std;

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
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
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
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
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
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
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
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}


//main.cpp
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

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
penjelasan singkat guided 1
Program ini berfungsi untuk menambah data buah ke dalam list dengan fungsi creatlist serta alokasi, menghapus data buah tertentu , mengubah data buah dengan fungsi updateFirst untuk data buah pertama, lalu dengan fungsi updateLast untuk data buah terakhir, dan dengan fungsi updateAfter untuk data buah setelah pointer yang ditunjuk. selain itu,program ini juga berfungsi mencari data buah berdasarkan alamat, alamat node, dan rentang harga dengan fungsi FindNodeByData, FindNodeByAddress, dan FindNodeByRange dan menghapus seluruh list.


## Unguided 

### 1. ![Screenshot Output Unguided 1_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/Pertemuan5_Modul5/Soal1_Update.png)

```C++
//ListAngka.h
#ifndef LISTANGKA_H
#define LISTANGKA_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int dataAngka;

struct node;  
typedef node* address; 

struct node {
    dataAngka Angka;
    address next;
};

struct LinkedList {
    address first;
};


void CreateList(LinkedList &L); 
address alokasi(dataAngka x);
void dealokasi(address P);
void printList(LinkedList L);
void insertFirst(LinkedList &L, address nodeBaru);
void insertLast(LinkedList &L, address nodeBaru);
void insertAfter(LinkedList &L, address nodeBaru, address nodePrev);
int nbList(LinkedList L);
void delAfter(LinkedList &L, address nodeHapus, address nodePrev);

void updateFirst(LinkedList &L);
void updateLast(LinkedList &L);
void updateAfter(LinkedList &L, address Nodeprev);

#endif

//ListAngka.cpp
#include "ListAngka.h"
using namespace std;

void CreateList(LinkedList &L) {

    L.first = Nil;
}

address alokasi(dataAngka x) {
    address nodeBaru = new node;
    nodeBaru->Angka = x;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address P) {
    P->next = Nil;
    delete P;
}

void printInfo(LinkedList L) {
    address P = L.first;
    if (P == Nil) {
        cout << "List kosong" << endl;
    } else {
        while (P != Nil) {
            cout << P->Angka << " - ";
            P = P->next;
        }
        cout << endl;
    }
}

void insertFirst(LinkedList &L, address nodeBaru) {
    nodeBaru->next = L.first;
    L.first = nodeBaru;
}
void insertLast(LinkedList &L, address nodeBaru) {
    if (L.first == Nil) {
        L.first = nodeBaru;
    } else {
        address P = L.first;
        while (P->next != Nil) {
            P = P->next;
        }
        P->next = nodeBaru;
    }
}

void insertAfter(LinkedList &L, address nodeBaru, address nodePrev) {
    if (nodePrev != Nil) {
        nodeBaru->next = nodePrev->next;
        nodePrev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}



void delAfter(LinkedList &L, address nodeHapus, address nodePrev){
    if(L.first == Nil){
        cout << "List kosong!" << endl;
    } else { 
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya tidak valid!" << endl;
        }
    }
}

void printList(LinkedList L) {
    if (L.first == Nil) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = L.first;
        while (nodeBantu != Nil) { 
            cout << nodeBantu->Angka;
            if (nodeBantu->next != Nil) cout << " - ";
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(LinkedList L) {
    int count = 0;
    address P = L.first;
    if (P == Nil) {
        cout << "LIst kosong";
    } else {
        while (P != Nil) {
            cout << P->Angka << " - ";
            count++;
            P = P->next;
        }
        cout << endl;
    }
    return count;
}

void updateFirst(LinkedList &L){
    if(L.first == Nil){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Masukkan angka : ";
        int NewValue;
        cin >> NewValue;
        L.first->Angka = NewValue;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(LinkedList &L){
    if (L.first == Nil) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Masukkan angka : ";
        int NewValue;
        cin >> NewValue;
        nodeBantu->Angka = NewValue;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(LinkedList &L, address nodePrev){
    if(L.first == Nil){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "Masukkan update data node setelah node " << nodePrev->Angka << " : " << endl;
            cout << "Masukkan angka : ";
            int NewValue;
            cin >> NewValue;
            nodeBantu->Angka = NewValue;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//main.cpp
#include "ListAngka.h"
using namespace std;

int main() {
    LinkedList L;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF = Nil;
    CreateList(L);

    dataAngka dtAngka;

    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(L, nodeB);
    insertLast(L, nodeA);
    insertAfter(L, nodeD, nodeB);
    insertFirst(L, nodeC);
    insertLast(L, nodeE);
    insertFirst(L, nodeF);
    delAfter(L, nodeB, nodeC);

    printList(L);
    cout << endl;

    updateFirst(L);
    updateAfter(L, nodeD);
    updateLast(L);
    
    address P = L.first;
    while (P != Nil) {
        if (P->Angka == 18) {
            cout << "Masukkan update data node setelah node 50 : " << endl;
        cout << "Masukkan angka : " ;
        int newVal;
        cin >> newVal;
        P->Angka = newVal;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
        break;
        }
        P = P->next;
    }

    printList(L);
    cout << endl;
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_2](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/Pertemuan5_Modul5/output/Output_Soal1_Update.png)

penjelasan unguided 1
Program ini berfungsi untuk mengisi list dataAngka dan menampilkan isi list setelah di alokasikan dengan fungsi alokasi lalu mengupdate nya dengan dataAngka yang baru yang semula 40-18-25-8-33 menjadi 50-20-25-29-45 dengan mengganti nilai 40 menjadi 50 menggunakan fungsi UpdateFirst,lalu mengubah nilai 18 menjadi 20 dengan menggunakan fungsi while di main, mengubah nilai 15 menjadi 29 dengan fungsi UpdateAfter, dan mengubah niali 33 menjadi 45 dengan fungsi UpdateLast. 

### 2. ![Screenshot Output Unguided 2_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/Pertemuan5_Modul5/Soal2_Searching.png)
```C++
//ListAngka.h
#ifndef LISTANGKA_H
#define LISTANGKA_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int dataAngka;

struct node;  
typedef node* address; 

struct node {
    dataAngka Angka;
    address next;
};

struct LinkedList {
    address first;
};


void CreateList(LinkedList &L); 
address alokasi(dataAngka x);
void dealokasi(address P);
void printList(LinkedList L);
void insertFirst(LinkedList &L, address nodeBaru);
void insertLast(LinkedList &L, address nodeBaru);
void insertAfter(LinkedList &L, address nodeBaru, address nodePrev);
int nbList(LinkedList L);
void delAfter(LinkedList &L, address nodeHapus, address nodePrev);

void updateFirst(LinkedList &L);
void updateLast(LinkedList &L);
void updateAfter(LinkedList &L, address Nodeprev);

void SearchByData(LinkedList L, int data);
void SearchByAddress(LinkedList L, address node);
void SearchByRange(LinkedList L, int NilaiMin);

#endif


//ListAngka.cpp
#include "ListAngka.h"
using namespace std;

void CreateList(LinkedList &L) {

    L.first = Nil;
}

address alokasi(dataAngka x) {
    address nodeBaru = new node;
    nodeBaru->Angka = x;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address P) {
    P->next = Nil;
    delete P;
}

void printInfo(LinkedList L) {
    address P = L.first;
    if (P == Nil) {
        cout << "List kosong" << endl;
    } else {
        while (P != Nil) {
            cout << P->Angka << " - ";
            P = P->next;
        }
        cout << endl;
    }
}

void insertFirst(LinkedList &L, address nodeBaru) {
    nodeBaru->next = L.first;
    L.first = nodeBaru;
}
void insertLast(LinkedList &L, address nodeBaru) {
    if (L.first == Nil) {
        L.first = nodeBaru;
    } else {
        address P = L.first;
        while (P->next != Nil) {
            P = P->next;
        }
        P->next = nodeBaru;
    }
}

void insertAfter(LinkedList &L, address nodeBaru, address nodePrev) {
    if (nodePrev != Nil) {
        nodeBaru->next = nodePrev->next;
        nodePrev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}



void delAfter(LinkedList &L, address nodeHapus, address nodePrev){
    if(L.first == Nil){
        cout << "List kosong!" << endl;
    } else { 
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya tidak valid!" << endl;
        }
    }
}

void printList(LinkedList L) {
    if (L.first == Nil) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = L.first;
        while (nodeBantu != Nil) { 
            cout << nodeBantu->Angka;
            if (nodeBantu->next != Nil) cout << " - ";
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(LinkedList L) {
    int count = 0;
    address P = L.first;
    if (P == Nil) {
        cout << "LIst kosong";
    } else {
        while (P != Nil) {
            cout << P->Angka << " - ";
            count++;
            P = P->next;
        }
        cout << endl;
    }
    return count;
}

void updateFirst(LinkedList &L){
    if(L.first == Nil){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Masukkan angka : ";
        int NewValue;
        cin >> NewValue;
        L.first->Angka = NewValue;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(LinkedList &L){
    if (L.first == Nil) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Masukkan angka : ";
        int NewValue;
        cin >> NewValue;
        nodeBantu->Angka = NewValue;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(LinkedList &L, address nodePrev){
    if(L.first == Nil){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "Masukkan update data node setelah node " << nodePrev->Angka << " : " << endl;
            cout << "Masukkan angka : ";
            int NewValue;
            cin >> NewValue;
            nodeBantu->Angka = NewValue;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya tidak valid!" << endl;
        }
    }
}

void SearchByData(LinkedList L, int data){
    if(L.first == Nil){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu =L.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->Angka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

void SearchByAddress(LinkedList L, address node) {
    if(L.first == Nil) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void SearchByRange(LinkedList L, int NilaiMin) {
    if(L.first == Nil) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Data dengan minimal " << NilaiMin << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu->Angka >= NilaiMin) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nilai Angka : " << nodeBantu->Angka << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data dengan nilai minimal 40!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}

//main.cpp
#include "ListAngka.h"
using namespace std;

int main() {
    LinkedList L;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF = Nil;
    CreateList(L);

    dataAngka dtAngka;

    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(L, nodeB);
    insertLast(L, nodeA);
    insertAfter(L, nodeD, nodeB);
    insertFirst(L, nodeC);
    insertLast(L, nodeE);
    insertFirst(L, nodeF);
    delAfter(L, nodeB, nodeC);

    printList(L);
    cout << endl;

    updateFirst(L);
    updateAfter(L, nodeD);
    updateLast(L);
    
    address P = L.first;
    while (P != Nil) {
        if (P->Angka == 18) {
            cout << "Masukkan update data node setelah node 50 : " << endl;
        cout << "Masukkan angka : " ;
        int newVal;
        cin >> newVal;
        P->Angka = newVal;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
        break;
        }
        P = P->next;
    }

    printList(L);
    cout << endl;

    SearchByData(L, 20);
    SearchByData(L, 55);
    SearchByAddress(L, nodeB);
    SearchByAddress(L, nodeA);
    SearchByRange(L, 40);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_2](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/Pertemuan5_Modul5/output/Output2_Soal_Searching.png)

penjelasan unguided 2
Program ini berfungsi untuk mencari data dengan nilai 20 dan 55 dengan menggunakan fungsi SearchByData, lalu mencari data dengan alamat nodeB dan nodeA dengan menggunakan fungsi SearchByAddress, serta mencari data dengan nilai yang diatas 40 dengan menggunakan fungsi SearchByRange.

### 3. ![Screenshot Output Unguided 3_1](https://github.com/raffydwianggara29/103112400252_Raffy_Dwi_Anggara/blob/main/Pertemuan5_Modul5/Soal3_Pertambahan_Pengurangan_Perkalian.png)

```C++
//ListAngka.h
#ifndef LISTANGKA_H
#define LISTANGKA_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int dataAngka;

struct node;  
typedef node* address; 

struct node {
    dataAngka Angka;
    address next;
};

struct LinkedList {
    address first;
};


void CreateList(LinkedList &L); 
address alokasi(dataAngka x);
void dealokasi(address P);
void printList(LinkedList L);
void insertFirst(LinkedList &L, address nodeBaru);
void insertLast(LinkedList &L, address nodeBaru);
void insertAfter(LinkedList &L, address nodeBaru, address nodePrev);
int nbList(LinkedList L);
void delAfter(LinkedList &L, address nodeHapus, address nodePrev);


void updateFirst(LinkedList &L);
void updateLast(LinkedList &L);
void updateAfter(LinkedList &L, address Nodeprev);

void SearchByData(LinkedList L, int data);
void SearchByAddress(LinkedList L, address node);
void SearchByRange(LinkedList L, int NilaiMin);

int Penjumlahan(LinkedList L);
int Pengurangan(LinkedList L);
int Perkalian(LinkedList L);


#endif

//ListAngka.cpp
#include "ListAngka.h"
using namespace std;

void CreateList(LinkedList &L) {

    L.first = Nil;
}

address alokasi(dataAngka x) {
    address nodeBaru = new node;
    nodeBaru->Angka = x;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address P) {
    P->next = Nil;
    delete P;
}

void printInfo(LinkedList L) {
    address P = L.first;
    if (P == Nil) {
        cout << "List kosong" << endl;
    } else {
        while (P != Nil) {
            cout << P->Angka << " - ";
            P = P->next;
        }
        cout << endl;
    }
}

void insertFirst(LinkedList &L, address nodeBaru) {
    nodeBaru->next = L.first;
    L.first = nodeBaru;
}
void insertLast(LinkedList &L, address nodeBaru) {
    if (L.first == Nil) {
        L.first = nodeBaru;
    } else {
        address P = L.first;
        while (P->next != Nil) {
            P = P->next;
        }
        P->next = nodeBaru;
    }
}

void insertAfter(LinkedList &L, address nodeBaru, address nodePrev) {
    if (nodePrev != Nil) {
        nodeBaru->next = nodePrev->next;
        nodePrev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}



void delAfter(LinkedList &L, address nodeHapus, address nodePrev){
    if(L.first == Nil){
        cout << "List kosong!" << endl;
    } else { 
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya tidak valid!" << endl;
        }
    }
}

void printList(LinkedList L) {
    if (L.first == Nil) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = L.first;
        while (nodeBantu != Nil) { 
            cout << nodeBantu->Angka;
            if (nodeBantu->next != Nil) cout << " - ";
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(LinkedList L) {
    int count = 0;
    address P = L.first;
    if (P == Nil) {
        cout << "LIst kosong";
    } else {
        while (P != Nil) {
            cout << P->Angka << " - ";
            count++;
            P = P->next;
        }
        cout << endl;
    }
    return count;
}

void updateFirst(LinkedList &L){
    if(L.first == Nil){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Masukkan angka : ";
        int NewValue;
        cin >> NewValue;
        L.first->Angka = NewValue;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(LinkedList &L){
    if (L.first == Nil) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Masukkan angka : ";
        int NewValue;
        cin >> NewValue;
        nodeBantu->Angka = NewValue;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(LinkedList &L, address nodePrev){
    if(L.first == Nil){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "Masukkan update data node setelah node " << nodePrev->Angka << " : " << endl;
            cout << "Masukkan angka : ";
            int NewValue;
            cin >> NewValue;
            nodeBantu->Angka = NewValue;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya tidak valid!" << endl;
        }
    }
}

void SearchByData(LinkedList L, int data){
    if(L.first == Nil){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu =L.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->Angka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

void SearchByAddress(LinkedList L, address node) {
    if(L.first == Nil) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void SearchByRange(LinkedList L, int NilaiMin) {
    if(L.first == Nil) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Data dengan minimal " << NilaiMin << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu->Angka >= NilaiMin) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nilai Angka : " << nodeBantu->Angka << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data dengan nilai minimal 40!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}

int Penjumlahan(LinkedList L) {
    int total = 0;
    address P = L.first;
    while (P != Nil) {
        total += P->Angka;
        P = P->next;
    }
    cout << "Total penjumlahan : " << total << endl;
    return total;
}

int Pengurangan(LinkedList L) {
    if (L.first == Nil) {
        cout << "List kosong!" << endl;
        return 0;
    }
    int total = L.first->Angka;
    address P = L.first;
    while (P != Nil) {
        total -= P->Angka;
        P = P->next;
    }
    cout << "Total pengurangan : " << total << endl;
    return total;
}

int Perkalian(LinkedList L) {
    int total = 1;
    address P = L.first;
    while (P != Nil) {
        total *= P->Angka;
        P = P->next;
    }
    cout << "Total perkalian : " << total << endl;
    return total;
}

//main.cpp
#include "ListAngka.h"
using namespace std;

int main() {
    LinkedList L;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF = Nil;
    CreateList(L);

    dataAngka dtAngka;

    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(L, nodeB);
    insertLast(L, nodeA);
    insertAfter(L, nodeD, nodeB);
    insertFirst(L, nodeC);
    insertLast(L, nodeE);
    insertFirst(L, nodeF);
    delAfter(L, nodeB, nodeC);

    printList(L);
    cout << endl;

    updateFirst(L);
    updateAfter(L, nodeD);
    updateLast(L);
    
    address P = L.first;
    while (P != Nil) {
        if (P->Angka == 18) {
            cout << "Masukkan update data node setelah node 50 : " << endl;
        cout << "Masukkan angka : " ;
        int newVal;
        cin >> newVal;
        P->Angka = newVal;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
        break;
        }
        P = P->next;
    }

    printList(L);
    cout << endl;

    SearchByData(L, 20);
    SearchByData(L, 55);
    SearchByAddress(L, nodeB);
    SearchByAddress(L, nodeA);
    SearchByRange(L, 40);

    Penjumlahan(L);
    Pengurangan(L);
    Perkalian(L);

    return 0;

}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_2](https://github.com/raffydwianggara/103112400252_Raffy_Dwi_Anggara/blob/main/Pertemuan5_Modul5/output/Output3png)

penjelasan unguided 3
Program ini berfungsi untuk menghitung hasil penjumlahan, pengurangan, dan perkalian ke seluruh list dengan menggunakan fungsi Penjumlahan dengan nilai awal yaitu 0, lalu menggunakan fungsi Pengurangan dengan nilai awal yaitu nilai node pertama yaitu 50, serta menggunakan fungsi Perkalian dengan nilai awal yaitu 1.
## Kesimpulan
Pada pembelajaran kali ini, kita diajarkan tentang ADT tetapi tidak semuanya ADT. Masih ada inputan yang harus diisi yaitu pada bagian update setelah itu tidak ada lagi inputan dari user. Dan kita bisa mengetahui Single linked List dan mengupdate nilai pada array serta mencari alamat, data, dan nilai yang lebih atau se- range dengan cara fungsi search, dan kita dapat menjumlahkan,mengurangkan, dan perkalian pada seluruh isi list tersebut.

## Referensi
[1] Konsep Dasar Algoritma dan Pemograman Menggunakan C++ Chapter#1. Diakses pada 28 September 2025 melalui https://repository.unpkediri.ac.id/2466/1/55201_0701107802.pdf.
[2] MODUL PRAKTIKUM "STRUKTUR DATA". Diakses pada 26 Oktober 2025 melalui https://www.ocw.upj.ac.id/files/Handout-TIF104-Modul-Praltikum-Struktur-Data.pdf?
[3] Setiyawan, Risky Dwi, et al. "PENGGUNAAN STRUKTUR DATA STACK DALAM PEMROGRAMAN C++ DENGAN PENDEKATAN ARRAY DAN LINKED LIST." JUTECH: Journal Education and Technology 5.2 (2024): 484-498. Diakses pada 26 Oktober 2025 melalui http://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263.