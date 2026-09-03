class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result;
       
        for(int i=0;i<temperatures.size();i++){
            int maxtemp=0;
            for(int j= i+1; j < temperatures.size();j++){
                if(temperatures[i] < temperatures[j]){
                    maxtemp = j-i;
                    break;
                }
                
            }
            result.push_back(maxtemp);
        }
        return result;
    }
};
