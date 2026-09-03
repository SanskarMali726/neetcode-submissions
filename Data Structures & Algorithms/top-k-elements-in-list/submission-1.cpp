class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freqCounter;
        vector<int> result;

        for(int i=0;i<nums.size();i++){
            freqCounter[nums[i]]++;
        }
        vector<pair<int,int>> p;
        for(auto i=freqCounter.begin();i!=freqCounter.end();i++){
            p.push_back({i->second,i->first});
        }

        sort(p.rbegin(),p.rend());

        for(int i=0;i<k;i++){
            result.push_back(p[i].second);
        }

        return result;
    }
};
