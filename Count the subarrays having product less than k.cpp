#include <iostream>
#include <vector>

class Solution{
private:
public:
    int countSubArrayProductLessThanK(const std::vector<int>& arr, int n, long long k) {
        int count=0;
        int product=1;
        int start=0,end=0;
        for (int i = 0; i < n; i++)
        {
            product*=arr[i];
            end=i;
            while(product>k && start<end){
                product=product/arr[start];
                start++;
            }
            if(product<k){
                count+=end-start+1;
            }
        }
        
        std::cout << count << "\n";
        return count;
    };
};

int main(){
    std::vector<int> a={1,2,3,4,5,6};
    int k=16;
    Solution solution;
    solution.countSubArrayProductLessThanK(a, a.size(), k);
}