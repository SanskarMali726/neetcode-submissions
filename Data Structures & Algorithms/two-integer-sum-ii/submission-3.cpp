class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> result;
        int index1 =0;
        int index2 =numbers.size()-1;
        while(index1 < index2 ){
            if(numbers[index1] + numbers[index2] == target){
                result.push_back(index1+1);
                result.push_back(index2+1);
                break;
            }
            else if(numbers[index1] + numbers[index2] < target){
                index1++;
                continue;
            }
            else if(numbers[index1] + numbers[index2] > target){
                index2--;
                continue;
                index1++;
                index2--;
            }
        }
        return result;
    }  
};
