class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mymap;
        vector<vector<string>> result;

        for(int i=0;i<strs.size();i++){
            string temp;
            temp= strs[i];
            sort(strs[i].begin(),strs[i].end());
            mymap[strs[i]].push_back(temp);
        }

        for( auto it=mymap.begin();it!=mymap.end();it++){
            result.push_back({it->second});
        }

        return result;
    }
};
