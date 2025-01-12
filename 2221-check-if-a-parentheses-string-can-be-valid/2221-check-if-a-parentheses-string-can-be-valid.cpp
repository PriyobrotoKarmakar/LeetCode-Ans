class Solution {
public:
    bool canBeValid(string s, string locked) {
        if ((s.length() & 1) == 1)
            return false;
        stack<int> lock;
        stack<int> openClose;
        for (int i = 0; i < s.length(); i++) {
            if (locked[i] == '1') {
                if (s[i] == '(') {
                    lock.push(i);
                } else {
                    if (!lock.empty()) {
                        lock.pop();
                    } else {
                        if (!openClose.empty()) {
                            openClose.pop();
                        } else {
                            return false;
                        }
                    }
                }
            } else {
                openClose.push(i);
            }
        }
        while (!lock.empty() && !openClose.empty() &&
               lock.top() < openClose.top()){
                lock.pop();
                openClose.pop();
               }
        return lock.empty();
    }
};