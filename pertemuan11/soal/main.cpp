#include "MultiLL.h"
#include <iostream>
using namespace std;

int main() {
    listParent L;
    createListParent(L);

    NodeParent K1 = allocateNodeParent("G001", "Aves");
    insertFirstParent(L, K1);

    NodeParent K2 = allocateNodeParent("G002", "Mamalia");
    insertLastParent(L, K2);

    NodeParent K3 = allocateNodeParent("G003", "Pisces");
    insertLastParent(L, K3);

    NodeParent K4 = allocateNodeParent("G004", "Amfibi");
    insertLastParent(L, K4);

    NodeParent K5 = allocateNodeParent("G005", "Reptil");
    insertLastParent(L, K5);

    cout << endl;

    NodeChild AV1 = allocateNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertFirstChild(K1->L_Child, AV1);
    NodeChild AV2 = allocateNodeChild("AV002", "Bebek", "Air", true, 2);
    insertlastChild(K1->L_Child, AV2);

    NodeChild MML1 = allocateNodeChild("M01", "Harimau", "Hutan", true, 200);
    insertFirstChild(K2->L_Child, MML1);
    NodeChild MML2 = allocateNodeChild("M02", "Gorila", "Hutan", false, 160);
    insertlastChild(K2->L_Child, MML2);
    NodeChild MML3 = allocateNodeChild("M03", "Kucing", "Darat", true, 4);
    insertlastChild(K2->L_Child, MML3);

    NodeChild AMF1 = allocateNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertlastChild(K4->L_Child, AMF1);

    printMLLStructure(L);
    cout << endl;

    return 0;
}