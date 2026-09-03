class KthLargest {
public:
    priority_queue<int, vector<int> , greater<int>> pq;
    int n;


    // we maintain a min heap of size k 
    //ie. for given example size of 3 heap is maintained which is 
    // 1,2,3 then we add 3 so the heap became 1,2,3,3 which violate the constriant that the heap should be size of 3 so we pop the min element in the heap which will cause the keep the kth largest element in array to the top of the queue this is the best solution
    KthLargest(int k, vector<int>& nums) {
       n = k;
       for(int x : nums){
            pq.push(x);

            if(pq.size() > k){
                pq.pop();
            }
       }
    }
    
    int add(int val) {
        pq.push(val);

        if(pq.size() > n){
            pq.pop();
        }

        return pq.top();
    }
};
