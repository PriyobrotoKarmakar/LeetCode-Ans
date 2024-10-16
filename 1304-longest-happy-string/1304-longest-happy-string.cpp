#include <queue>
#include <string>
using namespace std;

#define p pair<int,char>

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<p, vector<p>> heap;
        if (a > 0) heap.push({a, 'a'});
        if (b > 0) heap.push({b, 'b'});
        if (c > 0) heap.push({c, 'c'});
        
        string ans = "";
        
        while (!heap.empty()) {
            auto [count1, char1] = heap.top();
            heap.pop();
            
            if (ans.size() >= 2 && ans[ans.size() - 1] == char1 && ans[ans.size() - 2] == char1) {
                if (heap.empty()) {
                    break;
                }
                
                auto [count2, char2] = heap.top();
                heap.pop();
                
                ans += char2;
                count2--;
                
                if (count2 > 0) heap.push({count2, char2});
                
                heap.push({count1, char1});
            } else {
                ans += char1;
                count1--;
                
                if (count1 > 0) heap.push({count1, char1});
            }
        }
        
        return ans;
    }
};
