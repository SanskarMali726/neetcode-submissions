class Solution {
public:
    vector<string> ans;
    vector<string> letters = {
        "",      // 0
        "",      // 1
        "abc",   // 2
        "def",   // 3
        "ghi",   // 4
        "jkl",   // 5
        "mno",   // 6
        "pqrs",  // 7
        "tuv",   // 8
        "wxyz"   // 9
        };

    void createCombination(string digits,int i,int j,string t){
        //base case
        if(i == digits.size()){
            ans.push_back(t);
            return;
        }

        //first digit start
        string temp = letters[digits[i] - '0'];
        if(j == temp.size()){
            return;
        }

        t += temp[j];
        createCombination(digits,i+1,0,t);

        t.pop_back();
        createCombination(digits,i,j+1,t);


    }

    vector<string> letterCombinations(string digits) {
        string t = "";
        if(digits.size() == 0) return ans;
        createCombination(digits,0,0,t);
        return ans;

    }
};
