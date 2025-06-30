#include <stack>
#include <cassert>
#include <algorithm>
#include <iostream>

class MinStack {
private:
    std::stack<int> arr;
    std::stack<int> mini;

public:
    MinStack() = default;

    void push(int val) {
        arr.push(val);
        if (mini.empty()) {
            mini.push(val);
        } else {
            mini.push(std::min(val, mini.top()));
        }
    }

    void pop() {
        assert(!arr.empty());
        arr.pop();
        mini.pop();
    }

    [[nodiscard]] int top() const {
        assert(!arr.empty());
        return arr.top();
    }

    [[nodiscard]] int getMin() const {
        assert(!mini.empty());
        return mini.top();
    }
};

auto init = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
