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
