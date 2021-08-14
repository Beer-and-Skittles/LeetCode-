// 14.Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/
// begin:  2021/08/13
// solved: 2021/08/13

#include <iostream>
#include<string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string prefix = strs[0];
        for(int wordIndex=1; wordIndex<strs.size(); wordIndex++){

            string word = strs[wordIndex];
            for(int charIndex=0; charIndex<prefix.length(); charIndex++){

                // word is shorter than prefix
                if(charIndex==word.length()){
                    prefix=word;
                    break;
                }

                // word and prefix are different
                if(word[charIndex] != prefix[charIndex]){
                    prefix=prefix.substr(0,charIndex);
                    break;
                }
            }
        }
        return prefix;
    }
};

int main(void){
    Solution sol;
    vector<string> myVec = {"flower", "flow", "flight"};
    string prefix = sol.longestCommonPrefix(myVec);
    printf("prefix is : %s\n",prefix.c_str());
    return 0;
}