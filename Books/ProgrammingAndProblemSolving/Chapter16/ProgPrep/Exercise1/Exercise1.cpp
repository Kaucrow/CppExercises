#include <iostream>
using std::cout;

struct NodeType{
    int component;
    int link;
};

int main(){
    NodeType node[100];
    int head = 0;
    int currPtr = 0;
    for(int i = 0; i < 100; i++){
        node[i].component = i;
        node[i].link = i + 1;
    }
    node[99].link = head;

    cout << node[currPtr].component << '\n';
    currPtr++;
    cout << node[currPtr].component << '\n';
    cout << node[node[currPtr].link].component << '\n';
}