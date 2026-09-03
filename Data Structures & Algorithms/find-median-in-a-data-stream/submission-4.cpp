class MedianFinder {
public:

    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int> > minheap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxheap.push(num);
        int t;
        if(!maxheap.empty() && !minheap.empty() && maxheap.top() > minheap.top()){
            t = maxheap.top();
            maxheap.pop();
            minheap.push(t);
        }
        if(maxheap.size() > minheap.size() + 1){
            t = maxheap.top();
            maxheap.pop();
            minheap.push(t);
        }
        if(maxheap.size() + 1 < minheap.size()){
            t = minheap.top();
            minheap.pop();
            maxheap.push(t);
        }
        
        
    }
    
    double findMedian() {
        if(minheap.size() == maxheap.size()){
            return (double)(minheap.top() + maxheap.top()) / 2;
        }else{
            if(maxheap.size() > minheap.size()){
                return maxheap.top();
            }else{
                return minheap.top();
            }
        }
    }
};
