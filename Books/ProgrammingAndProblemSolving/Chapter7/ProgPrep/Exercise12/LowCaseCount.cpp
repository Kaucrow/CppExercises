#include <iostream>

using std::cout, std::string;

void LowerCount(string& str, int& count);

int main(){
    int count = 0;
    string str = "Hello World";
    LowerCount(str, count);
    cout << "Number of lowercase letters: " << count << '\n';
}

void LowerCount(string& str, int& count){
    for(int i = 0; i < str.length(); i++){
        if(islower(str[i])) count++;
    }
}