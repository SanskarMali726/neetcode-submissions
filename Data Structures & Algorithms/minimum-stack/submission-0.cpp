class MinStack {
public:
    vector<int> ans;
    vector<int> minans;
    MinStack() {

    }
    
    void push(int val) {
        ans.push_back(val);
        if(minans.empty()){
            minans.push_back(val);
        }
        else if(minans.back() > val){
            minans.push_back(val);
        }
        else{
            minans.push_back(minans.back());
        }
    }
    
    void pop() {
        ans.pop_back();
        minans.pop_back();
    }
    
    int top() {
        return ans.back();
    }
    
    int getMin() {
        return minans.back();
    }
};
