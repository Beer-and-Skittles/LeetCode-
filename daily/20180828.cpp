#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {

        if(preorder == "#")
            return true;

        preorder += ',';
        vector<string> left_stack;
        vector<string> right_stack;
        string num = "";
        bool first = true;

        for(int i=0; i<preorder.length(); i++){

            if(!first && left_stack.empty() && right_stack.empty())
                return false;

            if(int(preorder[i])>=int('0') && int(preorder[i])<=int('9')){
                num += preorder[i];
            }
            else if(preorder[i] == ','){

                if(num == "")
                    continue;

                if(left_stack.empty() && right_stack.empty()){
                    // do nothinig
                }else if(left_stack.empty() || left_stack.back()!=right_stack.back()){
                    // pop right_stack
                    if(right_stack.empty())
                        return false;
                    right_stack.pop_back();
                }else{
                    // pop left_stack
                    left_stack.pop_back();
                }

                left_stack.push_back(num);
                right_stack.push_back(num);
                num = "";
                
                
            }
            else if(preorder[i] == '#'){

                if(left_stack.empty() && right_stack.empty()){
                    // invalid
                    return false;
                }else if(left_stack.empty() || left_stack.back()!=right_stack.back()){
                    // pop right_stack
                    right_stack.pop_back();
                }else{
                    // pop left_stack
                    left_stack.pop_back();
                }
            }
            else
                return false;
            first = false;
        }

        // printStack(left_stack);
        // printStack(right_stack);

        if(right_stack.empty() && left_stack.empty())
            return true;
        return false;
    }

    void printStack(vector<string> stack){
        for(int i=0; i<stack.size(); i++)
            printf("%d:%s ",i,stack[i].c_str());
    }
};

int main(void){
    string my_tree = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    Solution sol;
    bool ans = sol.isValidSerialization(my_tree);
    
    if(ans)
        printf("True\n");
    else
        printf("False\n");

    return 0;
}