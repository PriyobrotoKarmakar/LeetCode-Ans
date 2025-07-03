#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int &count, int &n) {
        return count == n - 1;
    }

    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<>> pq;
        set<long long> st;

        pq.push(1);
        st.insert(1);

        long long ugly = 1; // To store the current ugly number
        int count = 0;

        while (true) {
            ugly = pq.top();
            pq.pop();

            if (check(count, n)) {
                return ugly;
            }

            count++;

            
            if (st.insert(ugly * 2).second) {
                pq.push(ugly * 2);
            }
            if (st.insert(ugly * 3).second) {
                pq.push(ugly * 3);
            }
            if (st.insert(ugly * 5).second) {
                pq.push(ugly * 5);
            }
        }
    }
};
