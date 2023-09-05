#include <iostream>
#include <vector>
using std::cout, std::vector;

class ArraySolution {
public:
    int removeElement(vector<int>& nums, int val) {
        int currSize = nums.size();

        static auto Erase = [](vector<int>& nums, int& currSize, int pos){
            for(int j = pos; j < currSize - 1; j++){
                nums[j] = nums[j + 1];
            }
            currSize--;
        };

        for(int i = 0; i < currSize; i++){
            if(nums[i] == val){ Erase(nums, currSize, i); i--; }
        }

        for(auto i : nums) cout << i << ' ';

        return currSize;
    }
};

class VectorSolution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int i = 0; i < nums.size(); i++){
            if(nums.at(i) == val){ nums.erase(nums.begin() + i); i--; }
        }
        return nums.size();
    }
};

int main(){
    ArraySolution mySol;
    vector<int> nums = {1, 4, 9, 4, 0};
    cout << nums.size() << '\n';
    mySol.removeElement(nums, 4); 
}