#include <iostream>
using std::cout;

typedef int ComponentType;

struct NodeType;
typedef NodeType* NodePtr;

struct NodeType{
    ComponentType component;
    NodePtr link;
};

void Insert(NodePtr& currPtr, ComponentType item, bool atLast = 1);
void CurrPtrToLast(NodePtr& currPtr);
void PutNextAtFirst(NodePtr& currPtr, NodePtr& head);
 
int main(){
    // EXERCISE 2
    NodePtr head;
    NodePtr currPtr;
    
    head = new NodeType;

    head->link = nullptr;
    head->component = 1;
    currPtr = head;

    Insert(currPtr, 2);
    Insert(currPtr, 3);
    Insert(currPtr, 4);

    currPtr = head;
    cout << currPtr->component << '\n';
    currPtr = currPtr->link;                // advance the currPtr to node 2
    cout << currPtr->component << '\n';
    cout << currPtr->link->component << '\n';
    cout << currPtr->link->link->component << '\n';

    // EXERCISE 3
    Insert(currPtr, 100);
    cout << head->component << '\n';

    // EXERCISE 4
    Insert(currPtr, 212);
    cout << currPtr->component << '\n';

    // EXECISE 5
    currPtr = head->link->link->link;
    cout << currPtr->component << '\n';
    Insert(currPtr, 32, 0);
    cout << currPtr->component << '\n';
    cout << currPtr->link->component << '\n';
    
    // EXERCISE 6
    PutNextAtFirst(currPtr, head);
    cout << head->component << '\n';
    cout << currPtr->link->component << '\n';
    
    // NOTE: MEMORY LEAKS ARE EXPECTED TO HAPPEN HERE
    // BUT ARE NOT TAKEN CARE OF FOR PRACTICAL PURPOSES
}

void Insert(NodePtr& currPtr, ComponentType item, bool atLast){
    if(atLast) CurrPtrToLast(currPtr);
    NodePtr tempPtr = currPtr->link;      // unused if the insertion is at last
    NodePtr newNodePtr;
    newNodePtr = new NodeType;

    currPtr->link = newNodePtr;
    currPtr = newNodePtr;

    newNodePtr->component = item;
    if(atLast) newNodePtr->link = nullptr;
    else newNodePtr->link = tempPtr;
}

void CurrPtrToLast(NodePtr& currPtr){
    while((currPtr->link) != nullptr){
        currPtr = currPtr->link;
    }
}

void PutNextAtFirst(NodePtr& currPtr, NodePtr& head){
    if(currPtr->link == nullptr) return;
    NodePtr tempPtr1 = head;
    NodePtr tempPtr2 = currPtr->link->link;
    
    head = currPtr->link;
    head->link = tempPtr1;

    currPtr->link = tempPtr2;
}