#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

class Solution{
private:
    std::unordered_map<char, int> stringMap;
    bool isCommon(std::string& base, std::string& top){
        this->stringMap.clear();
        if(base.size()!=top.size())
            return false;
        for (int i = 0; i < base.size(); i++)
        {
            if(stringMap.find(base.at(i))==stringMap.end()){
                stringMap[base.at(i)]=1;
            }else{
                stringMap[base.at(i)]++;
            }
        }
        for (int i = 0; i < top.size(); i++)
        {
            if(stringMap.find(top.at(i))==stringMap.end())
                return false;
            else{
                stringMap[top.at(i)]--;
                if(stringMap[top.at(i)]==0)
                    stringMap.erase(top.at(i));
            }
        }
        return true;
    };
public:
    std::vector<std::vector<std::string> > Anagrams(std::vector<std::string>& string_list) {
        //code here
        std::vector<std::vector<std::string>> anagramList;
        std::vector<std::string> common;
        int arr[string_list.size()];
        for (int i = 0; i < string_list.size(); i++)
            arr[i]=0;
        
        std::string base="";
        int commonflag;
        for (int i = 0; i < string_list.size(); i++)
        {
            if(arr[i]==1)
                continue;
            base=string_list[i];
            common.push_back(string_list[i]);
            for (int j = i+1; j < string_list.size(); j++)
            {
                if(arr[j]==1)
                    continue;
                commonflag=this->isCommon(base,string_list[j]);
                if(commonflag==true){
                    common.push_back(string_list[i]);
                    arr[j]=1;
                }else{
                    arr[j]=0;
                }
            }
            anagramList.push_back(common);
            common.clear();
        }
        return anagramList;
    }
};

int main(){
    std::vector<std::string> string_list={"act","god","cat","dog","tac"};
    Solution solution;
    solution.Anagrams(string_list);
}