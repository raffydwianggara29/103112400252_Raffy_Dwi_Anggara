#include <iostream>
#include "bst.h"
using namespace std;
int main()
{
    cout << "Hello World" << endl;
    int IDProduk, stok;
    string NamaProduk;
    insertNode(50, 'Monitor LED', 10);
    insertNode(30, 'Keyboard RGB', 20);
    insertNode(70, 'Mouse Gaming', 15);
    insertNode(20, 'Kabel HDMI', 50);
    insertNode(40, 'Headset 7.1', 12);
    insertNode(60, 'Webcam HD', 8);
    insertNode(80, 'Speaker BT', 5);
    cout << "Tampilkan preOrder : " ;
             preOrder(root); 
             cout << endl;
    cout << "Tampilkan postOrder : "; 
             postOrder(root);
             cout << endl;
    return 0;
}