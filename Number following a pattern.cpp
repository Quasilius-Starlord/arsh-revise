#include <iostream>
#include <string>

class Solution{
private:
    std::string numberToChar(int a){
        switch (a)
        {
        case 1:
            return "1";
        case 2:
            return "2";
        case 3:
            return "3";
        case 4:
            return "4";
        case 5:
            return "5";
        case 6:
            return "6";
        case 7:
            return "7";
        case 8:
            return "8";
        case 9:
            return "9";
        default:
            return "0";
        }
    }
public:
    std::string printMinNumberForPattern(std::string S){
        int top=0;
        int count=2;
        std::string str="1";
        for (int i = 0; i < S.size(); i++)
        {
            if(S.at(i)=='I'){
                // str.insert(this->numberToChar(count));
                str+=this->numberToChar(count);
                top=str.size()-1;
            }else{
                str.insert(top,this->numberToChar(count));
            }
            count++;
        }
        return str;
    }
};

int main(){
    Solution solution;
    std::cout << solution.printMinNumberForPattern("DDII");
}