#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct Song{
    string tittle;
    string Artist; 
    int Duration;
    int Playcount;
    float rating; 
};

typedef struct node *address;
typedef Song infotype;

struct node{
    Song info;
    address next;
    address prev;
};


struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string tittle, string Artist, int Duration, int Playcount, float rating);
void dealokasi(address &P);

void insertFirst(linkedlist &List, Song S);
void insertLast(linkedlist &List, Song S);
void insertAfter(linkedlist &List, address Q, Song S);
void insertBefore(linkedlist &List, address Q, Song S);
void deleteFirst(linkedlist &List, Song S);
void deleteLast(linkedlist &List, Song S);
void deleteAfter(linkedlist &List, address Q, Song S);
void deleteBefore(linkedlist &List, address Q, Song S);
void updateAtPosition(linkedlist List, int posisi);
void updateBefore(linkedlist List, address Q);
void viewList(linkedlist List);
void FindNodeByData(linkedlist list, float minScore, float maxScore);

#endif