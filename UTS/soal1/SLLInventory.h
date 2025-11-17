#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H
#define Nil NULL

#include<iostream>
using namespace std;

struct product {
    string nama;
    string SKU;
    int jumlah;
    float hargaSatuan;
    float DiskonPersen;
    node *address;
};

typedef struct node *address;

struct node {
    product info;
    address next;
};

struct list{
    address first;
};

bool isEmpty(list L);
void createList(list &L);
address allocate(product P);
void deallocate(address &adr);
void insertFirst(list &L, address P);
void insertLast(list &L, address P);
void insertAfter(list &L, address Q, address Prev);
void deleteFirst(list &L, address &P);
void deleteLast(list &L, address &P);
void deleteAfter(list &L, address Q, address &P);
void updateAtPosition(list &L, int posisi);
void viewList(list L);
void searchByFinalPriceRange(list &L, float minPrice, float maxPrice);

#endif

