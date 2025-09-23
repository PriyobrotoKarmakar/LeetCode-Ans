class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> lastOcc;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            lastOcc[s[i]] = i;
        }

        stack<char> stack;
        unordered_set<char> visited;

        for (int i = 0; i < n; i++) {
            if (visited.find(s[i]) != visited.end()) {
                continue;
            }

            while (!stack.empty() && s[i] < stack.top() &&
                   i < lastOcc[stack.top()]) {
                visited.erase(stack.top());
                stack.pop();
            }

            visited.insert(s[i]);
            stack.push(s[i]);
        }

        string result;
        while (!stack.empty()) {
            result = stack.top() + result;
            stack.pop();
        }
        return result;
    }
};