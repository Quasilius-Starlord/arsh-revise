#include <iostream>
#include <vector>

class Solution{
private:
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        long long int sum=nums[0];
        int lengthOfSum=INT_MAX, resultSum=INT_MAX;
        int i=0,j=0;
        if(sum>=target){
            lengthOfSum=1;
            resultSum=sum;
        }
        while ((i<((int)nums.size())) && (j<((int)nums.size())))
        {
            if(nums[j]>target){
                j++;
                i=j;
                sum=nums[j];
                continue;
            }
            if(sum<target){
                j++;
                if(j>=nums.size())
                    continue;
                else
                    sum+=nums[j];
            }else{
                i++;
                if(i>=nums.size())
                    continue;
                sum-=nums[i-1];
            }
            if(sum>=target){
                if(sum<=resultSum){
                    resultSum=sum;
                    lengthOfSum=std::min(lengthOfSum,j-i+1);
                }
            }
        }
        return lengthOfSum > nums.size() ? 0 : lengthOfSum;
    }
};

int main(){
    std::vector<int>nums={2,3,1,2,4,3};
    Solution solution;
    std::cout << solution.minSubArrayLen(7,nums);
}