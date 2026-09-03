class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea=0;
        int i=0;
        int j=heights.size()-1;
        while(i < j){
            int area=0;
            area = min(heights[i],heights[j]) * (j-i);
            maxArea = max(area,maxArea);
            if(heights[i] < heights[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxArea;
    }
};
