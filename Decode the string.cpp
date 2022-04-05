#include <iostream>
#include <string>
#include <stack>
#include <sstream>

class Solution{
private:
    void stringProcessor(std::string& s, int num){
        std::string temp=s;
        if(num==0)
            s="";
        else{
            int size=s.size();
            s="";
            for(int i=0;i<num;i++){
                s+=temp;
            }
        }
    };
    
    void stringProcessor(std::string& s,char c){
        std::string temp(1,c);
        s=temp+s;
    };

    int characterToNumber(char c, int number){
        number=(number*10) + ((int)c - 48);
        return number;
    }
public:
    std::string decodedString(std::string s){
        // code here
        std::stack<std::string> Stack;
        std::string res="";
        std::string temp="";
        std::string number;
        int num;
        std::stringstream stringtonum;
        std::string symbol;
        std::string delimiter="[";
        for (int i = 0; i < s.size(); i++)
        {
            if(s.at(i)==']'){
                temp="";
                number="";
                while (delimiter.compare(Stack.top())!=0)
                {
                    temp=Stack.top()+temp;
                    Stack.pop();
                }
                Stack.pop();
                while(!Stack.empty()){
                    if(Stack.top().at(0)>=48 && Stack.top().at(0)<=57){
                        number=Stack.top()+number;
                    }else{
                        break;
                    }
                    Stack.pop();
                }
                std::stringstream stringtonum(number);
                stringtonum >> num;
                std::cout << num << "\n";
                res="";
                for (int i = 0; i < num; i++)
                    res=res+temp;
                
                Stack.push(res);
            }else{
                Stack.push(s.substr(i,1));
            }
        }
        res="";
        
        while (!Stack.empty())
        {
            temp=Stack.top();
            res=temp+res;
            Stack.pop();
        }
        return res;
    }
};

int main(){
    Solution solution;
    solution.decodedString("1[b]");

    // std::string s="";
    // s+='s';
    // std::cout << s;
}