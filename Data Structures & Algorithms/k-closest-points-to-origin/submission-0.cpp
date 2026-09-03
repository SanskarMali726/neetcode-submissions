class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;

        

        priority_queue< pair<int,vector<int>> , vector<pair<int,vector<int>>> , greater<pair<int,vector<int>>>> pq;

        for(vector<int> cor : points){
            int x1 = cor[0];
            int y1 = cor[1];
            int distance = (x1 * x1) + (y1 * y1);
            pair<int,vector<int>> temp(distance,cor);
            pq.push(temp);
        }

        while(k > 0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;

    }
};
