#include "mll.h"
#include <iostream>
using namespace std;

int main() {
    listInduk L;
    listAnak P;
    createListParent(L);

    NodeParent K1 = alokasiNodeParent("G004", "Romance");
    insertFirstParent(L, K1);

    NodeParent K2 = alokasiNodeParent("G003", "Horror");
    insertFirstParent(L, K2);

    NodeParent K3 = alokasiNodeParent("G002", "Comedy");
    insertFirstParent(L, K3);

    NodeParent K4 = alokasiNodeParent("G001", "Action");
    insertFirstParent(L, K4);

    cout << endl;
    NodeChild AC1 = alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6);
    insertLastChild(K4->L_Anak, AC1);

    NodeChild FL1 = alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0);
    insertLastChild(K3->L_Anak, FL1);
    NodeChild FL2 = alokasiNodeChild("FC002", "My Stupid Bos", 108, 2016, 6.8);
    insertLastChild(K3->L_Anak, FL2);

    NodeChild HR1 = alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4);
    insertLastChild(K2->L_Anak, HR1);

    NodeChild RM1 = alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6);
    insertLastChild(K1->L_Anak, RM1);
    NodeChild RM2 = alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6);
    insertLastChild(K1->L_Anak, RM2);
    
    printStrukturMLL(L);
    searchFilmByRatingRange(P, 8.0 <= 8.5);
    deleteAfterParent(L, K3);
    printStrukturMLL(L);
    cout << endl;

    return 0;
}