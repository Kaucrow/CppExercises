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
    cout << myList;
    myList.DeleteAllOf(8);
    myList.DeleteAllOf(4);
    myList.DeleteAllOf(1);
    myList.DeleteAllOf(2);
    myList.DeleteAllOf(3);
    cout << myList;
    myList.DeleteAllOf(7);
    myList.DeleteAllOf(9);
    cout << myList;
    myList.DeleteAllOf(5);
    cout << myList;
    cout << myList;
    cout << myList;
}