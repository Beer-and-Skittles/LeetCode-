// 15.3Sum
// https://leetcode.com/problems/3sum/
// begin:  2021/08/14
// solved: 2021/08/14

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> results;
        if(nums.size()<3)
            return results;

        sort(nums.begin(), nums.end());

        int ptr1 = 0;
        while(ptr1 < nums.size()){

            if(ptr1!=0 && nums[ptr1]==nums[ptr1-1]){
                ptr1++;
                continue;
            }

            int ptr2 = nums.size()-1;
            while(ptr2 > ptr1){

                if(ptr2!=nums.size()-1 && nums[ptr2]==nums[ptr2+1]){
                    ptr2--;
                    continue;
                }

                int ptr3 = ptr2-1;
                while(ptr3 > ptr1){

                    if(ptr3!=ptr2-1 && nums[ptr3]==nums[ptr3+1]){
                        ptr3--;
                        continue;
                    }

                    if(nums[ptr1]+nums[ptr2]+nums[ptr3] < 0){
                        break;
                    }else if(nums[ptr1]+nums[ptr2]+nums[ptr3] == 0){
                        vector<int> sol = {nums[ptr1], nums[ptr2], nums[ptr3]};
                        results.push_back(sol);
                        break;
                    }else{
                        ptr3--;
                    }
                }
                ptr2--;
            }
            ptr1++;
        }
        
        return results;
    }

    void printVec(vector<vector<int>> results){
        if(results.empty())
            printf("vector is empty");
        for(int i=0; i<results.size(); i++)
            printf("%d %d %d\n",results[i][0],results[i][1],results[i][2]);        
    }
};

int main(void){
    vector<int> my_nums = {-1,0,1,2,-1,-4};
    Solution sol;
    vector<vector<int>> results = sol.threeSum(my_nums);
    sol.printVec(results);
    return 0;
}