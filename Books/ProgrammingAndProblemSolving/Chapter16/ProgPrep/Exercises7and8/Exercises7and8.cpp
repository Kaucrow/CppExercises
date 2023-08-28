#include <iostream>
using std::cout, std::cerr;

typedef int ComponentType;

struct NodeType;
typedef NodeType* NodePtr;

struct NodeType{
    ComponentType component;
    NodePtr link;
};

void Insert(NodePtr& currPtr, ComponentType item, bool atLast = 1);
void CurrPtrToLast(NodePtr& currPtr);
void SortList(NodePtr& currPtr, NodePtr& head);
void DeleteLast(NodePtr& currPtr);
void PutNextAtFirst(NodePtr& currPtr, NodePtr& head);
 
int main(){
    // EXERCISE 7
    NodePtr head = nullptr;
    NodePtr currPtr = nullptr;

    head = new NodeType;

    head->link = nullptr;
    head->component = 1;
    currPtr = head;
    
    Insert(currPtr, 2, 1); 
    Insert(currPtr, 3, 1); 
    Insert(currPtr, 4, 1); 
    Insert(currPtr, 5, 1); 
    Insert(currPtr, 6, 1);

    currPtr = head->link->link; 
    cout << currPtr->component << '\n';
    DeleteLast(currPtr);
    currPtr = currPtr->link->link;
    cout << currPtr << '\n';

    // EXERCISE 8: ADDITIONS TO EXERCISE 7 ON DeleteLast() METHOD


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

void DeleteLast(NodePtr& currPtr){
    if(currPtr == nullptr){ cerr << "ERR: LIST IS EMPTY\n"; return; }

    NodePtr tempPtr = nullptr;
    NodePtr auxPtr = currPtr;
    while(auxPtr->link != nullptr){
        tempPtr = auxPtr;
        auxPtr = auxPtr->link;
    }
    delete auxPtr;
    if(tempPtr != nullptr) tempPtr->link = nullptr;
}

void PutCurrAtFirst(NodePtr& currPtr, NodePtr& head){
    NodePtr tempPtr = head;

    if(currPtr->link == nullptr){
        NodePtr prevPtr = head;
        while(prevPtr->link != currPtr) prevPtr = prevPtr->link;
        prevPtr->link = nullptr;
    }

    head = currPtr;
    currPtr->link = tempPtr;
}
void PutNextAtFirst(NodePtr& currPtr, NodePtr& head){
    if(currPtr->link == nullptr) return;
    NodePtr tempPtr1 = head;
    NodePtr tempPtr2 = currPtr->link->link;
    
    head = currPtr->link;
    head->link = tempPtr1;

    currPtr->link = tempPtr2;
}