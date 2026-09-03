class Solution {
public:
    bool CanEatAll(vector<int>& piles, int mid , int h){
        int actualhour=0;
        for(int &banana:piles){
            actualhour += banana/mid;
            if(banana%mid != 0){
                actualhour++;
            }
        }
        return actualhour <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());

        while(l<r){
            int mid = l + (r-l)/2;
            if(CanEatAll(piles,mid,h)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};
