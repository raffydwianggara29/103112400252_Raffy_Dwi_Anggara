#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main(){
    Graph G;
    CreateGraph(G);
    infoGraph min, max;

    InsertNode(G, 'Jakarta');
    InsertNode(G, 'Bogor');
    InsertNode(G, 'Depok');
    InsertNode(G, 'Tangerang');
    InsertNode(G, 'Bekasi');
    
    //hubungkan antar node
    ConnectNode(G, "Jakarta", "Tangerang", 24);
    ConnectNode(G, "Jakarta", "Depok", 21);
    ConnectNode(G, "Jakarta", "Bekasi", 16);
    ConnectNode(G, "Jakarta", "Bogor", 42);
    ConnectNode(G, "Bogor", "Bekasi", 60);
    ConnectNode(G, "Bogor", "Depok", 22);
    ConnectNode(G, "Bogor", "Jakarta", 42);
    ConnectNode(G, "Depok", "Bekasi", 25);
    ConnectNode(G, "Depok", "Tangerang", 30);
    ConnectNode(G, "Depok", "Bogor", 22);
    ConnectNode(G, "Depok", "Jakarta", 21);
    ConnectNode(G, "Tangerang", "Depok", 30);
    ConnectNode(G, "Tangerang", "Bekasi", 25);
    ConnectNode(G, "Tangerang", "Jakarta", 24);
    ConnectNode(G, "Bekasi", "Depok", 25);
    ConnectNode(G, "Bekasi", "Tangerang", 45);
    ConnectNode(G, "Bekasi", "Bogor", 60);
    ConnectNode(G, "Bekasi", "Jakarta", 16);
    

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if(FindNode(G, 'E') == NULL) {
        cout << "node E berhasil dihapus" << endl;
    } else {
        cout << "Node E tidak berhasil dihapus" << endl;
    }
    cout << endl;

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A');  //BFS
    PrintDFS(G, 'A');  //DFS
  
    return 0;
}