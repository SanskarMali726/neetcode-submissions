class Solution {
public:
    vector<string> ans;
    
    void generateValidParenthesis(int openN,int closeN,int n,string temp){
        if(openN == closeN && openN == n){
            ans.push_back(temp);
            return;
        }

        if(openN < n){
            temp += "(";
            generateValidParenthesis(openN + 1,closeN,n,temp);
            temp.pop_back();
        }

        if(closeN < openN){
            temp += ")";
            generateValidParenthesis(openN,closeN + 1,n,temp);
            temp.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        string temp = "";
        generateValidParenthesis(0,0,n,temp);
        return ans;
    }
};
