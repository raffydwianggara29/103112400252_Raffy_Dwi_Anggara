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