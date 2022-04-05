#include <iostream>
#include <string>

class Solution{
private:
    bool replica(int start, int end, std::string str){
        int length=end-start+1;
        if((str.size() % length) != 0)
            return false;
        int iter=str.size()/length;
        std::string initial=str.substr(start,length);
        for (int i = 0; i < iter; i++)
        {
            if(str.substr(start,length).compare(str.substr(start+(length*i),length)) != 0)
                return false;
        }
        return true;
    }
public:
    std::string lonestDivisorString(std::string str1, std::string str2){
        int minimaLen=std::min(str1.size(), str2.size());
        int divisorLen=0;
        for (int i = 0; i < minimaLen; i++)
        {
            if(str1[i]==str2[i]){
                if(replica(0,i,str1) && replica(0,i,str2))
                    divisorLen=i+1;
            }else{
                break;
            }
        }
        // std::cout << divisorLen << " ";
        if (divisorLen==-1)
            return "";
        else
            return str1.substr(0,divisorLen);
        
    }
};

int main(){
    Solution solution;
    std::cout << solution.lonestDivisorString("ABABAB","AB");
}