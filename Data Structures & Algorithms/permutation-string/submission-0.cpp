class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        int n = s1.size();
        int m = s2.size();
        if( n > m) return false;
        for(int i=0;i<n;i++){
            m1[s1[i]]++;
        }
        int l =0;
        for(int r=0;r<m;r++){
            m2[s2[r]]++;
            if(r-l+1 > n){
                m2[s2[l]]--;
                if(m2[s2[l]] == 0) m2.erase(s2[l]);
                l++;
            }
            if(r-l+1 == n && m1 == m2) return true;
        }
        return false;
    }
};
