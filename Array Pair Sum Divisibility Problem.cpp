#include <iostream>
#include <unordered_map>
#include <vector>

class Solution{
private:
public:
    bool canPair(std::vector<int> nums, int k) {
        // Code here.
        std::unordered_map<int, int> map;
        int modulus, pair=0;
        for (int i = 0; i < nums.size(); i++)
        {
            modulus=nums[i] % k;
            // std::cout << "modules " << modulus << " for " << nums[i] << "\n";
            if(modulus==0){
                if(map.find(modulus)!=map.end()){
                    map.erase(modulus);
                    // std::cout << "found for " << nums[i] << "\n";
                    pair++;
                }else{
                    // std::cout << "not found for " << nums[i] << "\n";
                    map[modulus]=1;
                }
            }else{
                // std::cout << "searching " << k-modulus << " for " << nums[i] << "\n";
                if(map.find(k-modulus)!=map.end()){
                    map[k-modulus]--;
                    pair++;
                    map[k-modulus]==0 ? map.erase(k-modulus) : map[k-modulus];
                    
                    // std::cout << k-modulus << " popping found for " << nums[i] << "\n";
                }else{
                    map[modulus]=(map.find(modulus)!=map.end() ? map[modulus]+1 : 1);
                    // std::cout << modulus << " pushing not found for " << nums[i] << "\n";
                }
            }
        }
        // std::cout << pair;
        return pair*2 == nums.size() ? true : false;
    }
};

// 4 

int main(){
    Solution solution;
    std::vector<int> nums={11,8,4,3,14,1,5,11,7,8,12,10,14,13,13,6};
    std::cout << solution.canPair(nums, 4);
}

// 49 = 40+9

// 40%7=5
// 9%7=2

// 7-(40%7)=present{

// }

// not-present{
//     push into map
// }