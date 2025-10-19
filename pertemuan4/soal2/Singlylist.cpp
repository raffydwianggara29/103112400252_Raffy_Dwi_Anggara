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