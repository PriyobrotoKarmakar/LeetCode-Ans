/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    queue<int> q; // Stores the flattened integers

    // Helper function to flatten the list recursively
    void flatten(const vector<NestedInteger>& nestedList) {
        for (auto& ni : nestedList) {
            if (ni.isInteger()) {
                // Base case: It's a number, push to queue
                q.push(ni.getInteger());
            } else {
                // Recursive case: It's a list, flatten it further
                flatten(ni.getList());
            }
        }
    }

public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        // Flatten the entire structure immediately upon creation
        flatten(nestedList);
    }

    int next() {
        // Return front and remove it
        int result = q.front();
        q.pop();
        return result;
    }

    bool hasNext() {
        // Simply check if queue has elements
        return !q.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */