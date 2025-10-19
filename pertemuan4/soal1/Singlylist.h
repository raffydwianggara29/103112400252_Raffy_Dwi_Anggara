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
