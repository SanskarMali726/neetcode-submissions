class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;

        for (char x : tasks) {
            freq[x]++;
        }

        priority_queue< pair<int,char> ,vector<pair<int,char>>> pq;
        
        for (auto &[task, count] : freq) {
            pq.push({count, task});
        }

        int curr_time = 0;
        vector<tuple<int,int,char>> v;

        while(!pq.empty() || !v.empty()){
            for (auto it = v.begin(); it != v.end();) {
                if (curr_time >= std::get<0>(*it)) {
                    pq.push({std::get<1>(*it), std::get<2>(*it)});
                    it = v.erase(it); 
                } 
                else{
                    it++;
                }
            }

            if(!pq.empty()){
                auto curr = pq.top();
                pq.pop();
                curr.first--;
                if (curr.first > 0) {
                    int available_time = curr_time + n + 1;
                    v.push_back({available_time, curr.first, curr.second});
                }
            }
            curr_time++;
        }

        return curr_time;
        
    }
};
