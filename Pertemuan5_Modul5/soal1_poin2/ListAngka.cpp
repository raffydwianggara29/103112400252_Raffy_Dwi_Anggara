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