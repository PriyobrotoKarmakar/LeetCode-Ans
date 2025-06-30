class MinStack {
public:
    vector<int>arr;
    vector<int>mini;
    MinStack() {
        
    }
    
    void push(int val) {
        arr.push_back(val);
        if(!mini.empty()){
            mini.push_back(min(mini.back(),arr.back()));
        }else{
            mini.push_back(val);
        }
    }
    
    void pop() {
        if(!arr.empty()){
            arr.pop_back();
            mini.pop_back();
        }
    }
    
    int top() {
        return arr.back();
    }
    
    int getMin() {
        return mini.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();