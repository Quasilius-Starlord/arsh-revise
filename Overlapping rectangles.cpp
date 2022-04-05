#include <iostream>

class Solution{
private:
    //only 0 index X
    int isLeftOverlap(int L1[], int R1[], int L2[], int R2[]){
        if((R1[0]<L2[0]) || (R2[0]<L1[0])){
            return -1;
        }
        return 1;
        if(R1[0]<=R2[0] && R1[0]>L2[0]){
        }
        return 0;
    };
    //only 1 index Y
    int isTopOverlap(int L1[], int R1[], int L2[], int R2[]){
        if((R1[1]>=L2[1]) || (R2[1]>=L1[1])){
            return -1;
        }
        return 1;
    };
public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        // code here
        int left=this->isLeftOverlap(L1,R1,L2,R2);
        int top=this->isTopOverlap(L1,R1,L2,R2);
        if(left==-1 || top==-1)
            return 0;
        return 1;
        
    }
};

using namespace std;
int main(){
    Solution solution;
    int L1[]={0,10};
    int R1[]={10,0};
    int L2[]={5,5};
    int R2[]={15,0};
    solution.doOverlap(L1,R1,L2,R2);
}