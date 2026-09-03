class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0;
        int r=0;
        int maxlength=0;
        unordered_set<int> lett;
        while(r < n){
            while(lett.find(s[r]) != lett.end()){
                lett.erase(s[l]);
                l++;
            }
            lett.insert(s[r]);
            int length = lett.size();
            maxlength = max(maxlength,length);
            r++;
        }
    return maxlength;
    }
};
