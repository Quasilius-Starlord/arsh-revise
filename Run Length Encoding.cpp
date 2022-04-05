#include <iostream>
#include <string>
#include<sstream>

class Solution{
private:
public:
    std::string encode(std::string str)
    {
        int count=0;
        char current=str.at(0);
        std::string condenced="";
        for (int i = 0; i < str.size(); i++)
        {
            if(current==str.at(i)){
                count++;
            }else{
                std::stringstream ss;
                std::string add(1,current);
                std::string number;
                ss << count;
                ss >> number;
                condenced=condenced+add+number;
                current=str.at(i);
                count=1;
            }
        }
        std::stringstream ss;
        std::string add(1,current);
        std::string number;
        ss << count;
        ss >> number;
        condenced=condenced+add+number;
        return condenced;
    }
};

int main(){
    Solution solution;
    solution.encode("aaaabssscd");
}