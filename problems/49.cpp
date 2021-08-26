#include <iostream>
#include<string>
#include <vector>
#include <algorithm>
using namespace std;

bool sortChar(char a, char b){
    return (int(a) < int(b));
}

bool sortWord(string a, string b){
    if(a.substr(1,a.length()-2)==b.substr(1,b.length()-2))
        return true;
    int i=1;
    while(i<a.length() && i<b.length()){
        if(int(a[i])<int(b[i]))
            return true;
        else if(int(a[i])>int(b[i]))
            return false;
        i++;
    }
    if(a.length()>b.length())
        return true;
    return false;
}

class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams;
        vector<string> sorted_strs = strs;
        for(int i=0; i<sorted_strs.size(); i++){
            sort(sorted_strs[i].begin(),sorted_strs[i].end(), sortChar);
            sorted_strs[i] = to_string(i) + sorted_strs[i]; 
        }
        sort(sorted_strs.begin(),sorted_strs.end(),sortWord);
        for(int i=0; i<sorted_strs.size(); i++){
            vector<string> groups;
            groups.push_back(strs[int(sorted_strs[i][0])-int]);
        }
        return anagrams;
    }
};

int main(void){
    vector<string> testcase = {"eat","tea","tan","ate","nat","bat"};
    Solution sol;
    sol.groupAnagrams(testcase);
    return 0;
}