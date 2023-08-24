#include "..\..\..\..\..\Tools\SortedListClass\sorted_list.h" 
using std::cout;

int main(){
    SortedList myList;
    myList.Insert(1);
    myList.Insert(2);
    myList.Insert(3);
    myList.Insert(4);
    myList.Insert(4);
    myList.Insert(4);
    myList.Insert(4);
    myList.Insert(4);
    myList.Insert(5);
    myList.Insert(6);
    myList.Insert(7);
    myList.Insert(8);
    myList.Insert(9);
    myList.Insert(11);
    myList.Insert(20);
    cout << myList;
    myList.DeleteAllOf(8);
    cout << myList;
    myList.DeleteAllOf(11);
    cout << myList;
    myList.DeleteAllOf(20);
    cout << myList;
    myList.DeleteAllOf(1);
    cout << myList;
    cout << myList;
    myList.DeleteAllOf(4);
    myList.DeleteAllOf(4);
    cout << myList;
    myList.DeleteAllOf(2);
    myList.DeleteAllOf(3);
    myList.DeleteAllOf(5);
    myList.DeleteAllOf(6);
    myList.DeleteAllOf(7);
    cout << myList;
    myList.DeleteAllOf(9);
    cout << myList;
}