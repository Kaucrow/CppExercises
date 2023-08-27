#include <iostream>
#include "linked_list.h"
using std::cout, std::cerr;

struct NodeType{
    ComponentType component;
    NodePtr link;
};

LinkedList::LinkedList() : head(nullptr){}

LinkedList::LinkedList(const LinkedList& otherList){
    NodePtr fromPtr;    // ptr to the list that is copied from
    NodePtr toPtr;      // ptr to the new list being constructed

    if(otherList.head == nullptr){ head = nullptr; return; }

    // copy the first node
    fromPtr = otherList.head;
    head = new NodeType;
    head->component = fromPtr->component;

    // copy the rest of the nodes
    toPtr = head;
    fromPtr = fromPtr->link;
    while(fromPtr != nullptr){
        toPtr->link = new NodeType;
        toPtr = toPtr->link;
        toPtr->component = fromPtr->component;
        fromPtr = fromPtr->link;
    }
    toPtr->link = nullptr;
}

LinkedList::~LinkedList(){
    while(!IsEmpty()) this->RemoveFirst();
}

bool LinkedList::IsEmpty() const{
    return (head == nullptr);
}

void LinkedList::Print() const{
    NodePtr currPtr = head;

    while(currPtr != nullptr){
        cout << currPtr->component << '\n';
        currPtr = currPtr->link;
    }
}

// IF LIST IS "SORTED" IN ASCENDING ORDER, item MUST BE
// SMALLER THAN THE COMPONENT OF THE FIRST NODE
void LinkedList::InsertAsFirst(ComponentType item){
    NodePtr newNodePtr = new NodeType;

    newNodePtr->component = item;
    newNodePtr->link = head;
    head = newNodePtr;
}

void LinkedList::Insert(ComponentType item){
    NodePtr currPtr;        // mobile ptr
    NodePtr prevPtr;        // ptr for the node before *currPtr
    NodePtr newNodePtr;     // ptr for the new node

    newNodePtr = new NodeType;
    newNodePtr->component = item;

    prevPtr = nullptr;
    currPtr = head;
    while(currPtr != nullptr && item > currPtr->component){
        prevPtr = currPtr;
        currPtr = currPtr->link;
    }

    newNodePtr->link = currPtr;
    if(prevPtr == nullptr) head = newNodePtr;   // executes if the newNode is the first node
    else prevPtr->link = newNodePtr;
}

void LinkedList::RemoveFirst(){
    if(this->IsEmpty()){ cerr << "ERR: LIST HAS NO NODES\n"; return; }
    NodePtr tempPtr = head;

    head = head->link;
    delete tempPtr;
}

// THE item MUST BE SOMEWHERE ON THE LIST AND COMPONENTS
// MUST BE IN ASCENDING ORDER
void LinkedList::Delete(ComponentType item){
    if(this->IsEmpty()){ cerr << "ERR: LIST HAS NO NODES\n"; return; }
    NodePtr delPtr;     // ptr for the node to be deleted
    NodePtr currPtr;    // cycle control ptr

    //check if the item is in the first node
    if(item == head->component){
        // delete the first node
        delPtr = head;
        head = head->link;
    }
    else{
        //search for the node in the rest of the list
        currPtr = head;
        while(currPtr->link->component != item) currPtr = currPtr->link;

        // delete *(currPtr->link)
        delPtr = currPtr->link;
        currPtr->link = currPtr->link->link;
    }
    delete delPtr;
}