#include <iostream>
#include <string>

class Solution {
private:
    bool isValid(std::string str){
        if(str.size()>2)
            return false;
        if(str.size()==1)
            return true;
        if(str.at(0)=='1')
            return true;
        if(str.at(0)=='2'){
            if(str.at(1)<='6')
                return true;
        }
        return false;
    }
    int M=1000000007;
    int* dp;
    // int strToNum(std::string str){
        
    // }
    int countways(int begin,std::string& str){
        if(begin>=str.size())
            return -1;
        if(dp[begin]!=-1)
            return dp[begin];
        if(str.at(begin)=='0')
            return 0;
        int count=0;
        for (int i = begin; i < str.size(); i++)
        {
            int validity=isValid(str.substr(begin,i-begin+1));
            int ways=this->countways(i+1,str);
            if(validity){
                if(ways==0)
                    continue;
                else if(ways==-1)
                    count=(count+validity)%M;
                else
                    count=(count+ways)%M;
            }else{
                dp[begin]=count;
                return count;
            }
        }
        dp[begin]=count;
        return count;
    }
public:
    int CountWays(std::string str){
        // Code here
        dp=new int[str.size()];
        for(int i=0;i<str.size();i++)
            dp[i]=-1;
        int some=this->countways(0,str);
        return some==-1?0:some;
    }
};

int main(){
    Solution solution;
    std::cout << solution.CountWays("9480");
}