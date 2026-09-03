class Solution {
public:
    string minWindow(string s, string t) {
        string result="";
        int n = s.size();
        int m = t.size();
        int have =0;
        int needCount;
        if(n < m) return "";
        unordered_map<char,int> need;
        unordered_map<char,int> window;

        for(int i=0;i<m;i++){
            need[t[i]]++;
        }

        needCount = need.size();
        int start = 0;
        int minlen = INT_MAX;
        int l=0;
        for(int r=0;r<n;r++){
            window[s[r]]++;
            if(window[s[r]] == need[s[r]]){
                have+=1;
            }

            while(have == needCount){
                window[s[l]]--;

                if (window[s[l]] < need[s[l]]) {
                    have--;
                    int length = r-l+1;
                    if(length < minlen){
                        start = l;
                        minlen = length;
                    }
                }
                l++;
            }
        }
        return (minlen == INT_MAX) ? "" : s.substr(start, minlen);
    }
};
