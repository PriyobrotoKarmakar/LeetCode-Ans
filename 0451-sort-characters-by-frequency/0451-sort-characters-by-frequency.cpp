class Solution {
public:
    typedef pair<char, int> P;
    struct comparetor {
        bool operator()(P& p1, P& p2) { return p1.second < p2.second; }
    };
    string frequencySort(string s) {
        priority_queue<P, vector<P>, comparetor> pq;
        unordered_map<char, int> freq;
        for (auto& ch : s) {
            freq[ch]++;
        }

        for (auto& Pair : freq) {
            pq.push(Pair);
        }

        string ans = "";
        while (!pq.empty()) {
            P element = pq.top();
            int times = element.second;
            char ch = element.first;

            while (times--) {
                ans += ch;
            }

            pq.pop();
        }

        return ans;
    }
};