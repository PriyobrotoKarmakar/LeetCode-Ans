class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1; // The day itself counts as 1
        
        // Monotonic check: merge spans of smaller previous prices
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second; // Add the previous span to current
            st.pop();
        }
        
        // Push the calculated span for this price
        st.push({price, span});
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */