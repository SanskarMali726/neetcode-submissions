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

    // i = current digit index in `digits`
    // j = current letter index within letters[digits[i]]
    // t = string built so far
    void createCombination(string digits, int i, int j, string t) {

        // base case: used up all digits -> t is one full combination
        if (i == digits.size()) {
            ans.push_back(t);
            return;
        }

        // letters available for the current digit, e.g. "abc" for '2'
        string temp = letters[digits[i] - '0'];

        // tried every letter of this digit -> dead end, backtrack
        if (j == temp.size()) {
            return;
        }

        // CHOICE 1: use letter j of current digit, move to NEXT digit
        // reset letter index to 0 since the new digit starts fresh
        t += temp[j];
        createCombination(digits, i + 1, 0, t);

        // undo choice (backtrack) before trying the next option
        t.pop_back();

        // CHOICE 2: skip letter j, stay on SAME digit, try letter j+1
        // this simulates looping over all letters of digits[i]
        createCombination(digits, i, j + 1, t);
    }

    vector<string> letterCombinations(string digits) {
        string t = "";
        if (digits.size() == 0) return ans;   // edge case: empty input -> empty answer

        // start at digit 0, letter 0, empty string
        createCombination(digits, 0, 0, t);
        return ans;
    }
};