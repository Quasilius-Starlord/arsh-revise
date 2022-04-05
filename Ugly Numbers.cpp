#include <iostream>

class Solution
{
    private:
        int getSmallest( int a, int b, int c){
            return std::min(a,std::min(b,c));
        }
    public:
        int NthUglyNumber(int n){
            int ugly[n];
            ugly[0]=1;
            int factor2=0;
            int factor3=0;
            int factor5=0;
            int minima;
            for (int i = 1; i < n; i++)
            {
                minima=this->getSmallest(2*ugly[factor2],3*ugly[factor3],5*ugly[factor5]);
                if(minima==2*ugly[factor2])
                    factor2++;
                if(minima==3*ugly[factor3])
                    factor3++;
                if(minima==5*ugly[factor5])
                    factor5++;
                ugly[i]=minima;
            }
            return ugly[n-1];
        };
};

int main()
{
    Solution solution;
    std::cout<<solution.NthUglyNumber(7);
}