#include <iostream>
#include <vector>
using std::cout, std::vector;

class Solution{
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
            if(m == 0){ nums1 = nums2; return; }

            for(int nums2IT = 0; nums2IT < n; nums2IT++){
                // insert the nums2 element at the first position of nums1 if it's lower than
                // all of the elements of nums1
                if(nums2.at(nums2IT) < nums1.at(0)){
                    nums1.insert(nums1.begin(), nums2.at(nums2IT));
                    nums1.pop_back(); continue;
                }

                for(int nums1IT = (m + nums2IT - 1); nums1IT >= 0; nums1IT--){
                    if(nums2.at(nums2IT) >= nums1.at(nums1IT)){
                        nums1.insert(nums1.begin() + (nums1IT + 1), nums2.at(nums2IT)); 
                        nums1.pop_back(); break; 
                    }
                }
            }
        }
};

int main(){
    Solution mySol;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    for(auto i : nums1) cout << i << ' ';
    //nums1.at(2) = 4;
    for(auto i : nums1) cout << i << ' ' << '\n';
    mySol.merge(nums1, nums1.size() - nums2.size(), nums2, nums2.size());
}