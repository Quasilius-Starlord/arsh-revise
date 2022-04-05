#include <iostream>

class Solution{
private:
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int index;
        int repeat,missing;
        for (int i = 0; i < n; i++)
        {
            index=std::abs(arr[i])-1;

            if(arr[index]>0)
                arr[index]*=-1;
            else if (arr[index]<0)
                repeat=std::abs(arr[i]);
        }

        for (int i = 0; i < n; i++)
        {
            index=abs(arr[i])-1;
            if(arr[i]>0){
                missing=i+1;
            }
        }
        int* res=new int[2];
        res[0]=repeat;
        res[1]=missing;
        // std::cout << repeat << " " << missing << "\n";
        return res;
    }
};

int main(){
    Solution solution;

    int arr[]={1,2,2};
    solution.findTwoElement(arr,3);
}