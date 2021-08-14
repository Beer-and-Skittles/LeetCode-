#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        bool* rows = new bool[matrix.size()]{0};
        bool* cols = new bool[matrix[0].size()]{0};

        for(int r=0; r<matrix.size(); r++){
            for(int c=0; c<matrix[0].size(); c++){
                if(matrix[r][c] == 0){
                    rows[r] = true;
                    cols[c] = true;
                }
            }
        }

        for(int r=0; r<matrix.size();r++){
            for(int c=0; c<matrix[0].size(); c++){
                if(rows[r]==true or cols[c]==true)
                    matrix[r][c]=0;
            }
        }
    }

};

int main(void){
    vector<vector<int>> myvec = {{1,0,2},{3,4,0},{0,1,2}};
    Solution sol;
    sol.setZeroes(myvec);
    printf("finished");
    return 0;
}