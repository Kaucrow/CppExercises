#include <iostream>
#include <algorithm>

using std::cout, std::string, std::begin, std::end;

int main(){
    string str = "Hello world epic adventure here";
    int count = 0;
    for_each(str.begin(), str.end(), [&count](char i){ if(i == 'e') count++; });
    cout << "e count: " << count << '\n';
}