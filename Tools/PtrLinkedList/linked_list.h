// named "hybrid.h" in book
#pragma once

typedef int ComponentType;
struct NodeType;
typedef NodeType* NodePtr;

class LinkedList{
    public:
        LinkedList();
        LinkedList(const LinkedList& otherList);   // copy constructor
        ~LinkedList();
        bool IsEmpty() const;
        void Print() const;
        void InsertAsFirst(ComponentType item);
        void Insert(ComponentType item);
        void RemoveFirst();
        void Delete(ComponentType item);
    private:
        NodePtr head;
};