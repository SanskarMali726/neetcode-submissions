class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(); 
        unordered_map<char,int> m;
        int maxfrq=0;
        int res=0;
        int l=0;
        for(int r=0;r<n;r++){
            m[s[r]]++;
            maxfrq = max(maxfrq,m[s[r]]);
            if(r-l+1 - maxfrq > k){
                m[s[l]]--;
                l++;
            }
            res = max(res,r-l+1);
        }
        return res;
    }
};
