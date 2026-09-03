class Solution {
public:
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        int minvalue=INT_MAX;
        int maxprofit = INT_MIN;
        for(int i=0;i<n;i++){
            if(minvalue > prices[i]){
                minvalue = prices[i];
            }
            int profit = prices[i] - minvalue;
            maxprofit =  max(profit,maxprofit);
        }
        return maxprofit;
    }
};
