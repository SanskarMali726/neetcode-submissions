class KthLargest {
public:
    priority_queue<int> temp;
    priority_queue<int> main;

    int n;

    KthLargest(int k, vector<int>& nums) {
        for(int i = 0; i< nums.size(); i++){
            main.push(nums[i]);
        }
        n = k;
    }
    
    int add(int val) {
        temp = main;
        main.push(val);
        temp.push(val);
        
        for(int i = 0; i < n -1; i++){
            temp.pop();
        }

        return temp.top();
    }
};
