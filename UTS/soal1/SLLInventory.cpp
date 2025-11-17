#include "SLLInventory.h"
#include <iostream>
using namespace std;

bool isEmpty(list L)
{
    if (L.first == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createList(list &L)
{
    L.first = Nil;
}

address allocate(product P)
{
    string nama, SKU;
    int jumlah;
    float hargaSatuan, DiskonPersen;

    address product = new node;
    product->info.nama = nama;
    product->info.SKU = SKU;
    product->info.jumlah = jumlah;
    product->info.hargaSatuan = hargaSatuan;
    product->info.DiskonPersen = DiskonPersen;
    product->next = Nil;
    return product;
}

void deallocate(address &adr)
{
    adr->next = Nil;
    delete adr;
}

void insertFirst(list &L, address P)
{
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    P->next = L.first;
    L.first = P;
}

void insertAfter(list &L, address Q, address Prev)
{
    if (Prev != Nil)
    {
        Q->next = Prev->next;
        Prev->next = Q;
    }
    else
    {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(list &L, address P)
{
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(L) == true)
    {
        L.first = P;
    }
    else
    {
        address nodeBantu = L.first;
        while (nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = P;
    }
}

void deleteFirst(list &L, address &P)
{
    address nodeHapus;
    if (L.first != Nil)
    {
        nodeHapus = L.first;
        L.first = L.first->next;
        nodeHapus->next = Nil;
        deallocate(nodeHapus);
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

void deleteLast(list &L, address &P)
{
    address nodeHapus, nodePrev;
    if (L.first != Nil)
    {
        nodeHapus = L.first;
        if (nodeHapus->next == Nil)
        {
            L.first = Nil;
            deallocate(nodeHapus);
        }
        else
        {
            while (nodeHapus->next != Nil)
            {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            deallocate(nodeHapus);
        }
    }
    else
    {
        cout << "list kosong" << endl;
    }
}

void deleteAfter(list &L, address Q, address &P)
{
    if (L.first == Nil)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        if (P != Nil && P->next != Nil)
        {
            Q = P->next;
            P->next = Q->next;
            Q->next = Nil;
            deallocate(Q);
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void updateAtPosition(list L, int posisi)
{
    if (isEmpty(L) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = L.first;
        bool found = false;
        while (nodeBantu != Nil)
        {
            posisi++ if (nodeBantu == posisi)
            {
                cout << "Masukkan update data node pertama : " << endl;
                cout << "Nama buah : ";
                cin >> L.first->.nama;
                cout << "Jumlah : ";
                cin >> List.first->isidata.jumlah;
                cout << "Harga : ";
                cin >> List.first->isidata.harga;
                cout << "Data Berhasil Diupdate!" << endl;
                found true;
                cout << endl;
            }
            nodeBantu = 
        }
    }
}