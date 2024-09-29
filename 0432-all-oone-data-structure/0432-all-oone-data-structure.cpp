class AllOne {
public:
    unordered_map<string, int> keyCount;
    map<int, unordered_set<string>> countKeys;

    AllOne() {}

    void inc(string key) {
        int count = keyCount[key];
        keyCount[key]++;
        if (count > 0) {
            countKeys[count].erase(key);
            if (countKeys[count].empty())
                countKeys.erase(count);
        }
        countKeys[count + 1].insert(key);
    }

    void dec(string key) {
        int count = keyCount[key];
        if (count == 1) {
            keyCount.erase(key);
            countKeys[count].erase(key);
            if (countKeys[count].empty())
                countKeys.erase(count);
        } else {
            keyCount[key]--;
            countKeys[count].erase(key);
            if (countKeys[count].empty())
                countKeys.erase(count);
            countKeys[count - 1].insert(key);
        }
    }

    string getMaxKey() {
        if (countKeys.empty())
            return "";
        return *(countKeys.rbegin()->second.begin());
    }

    string getMinKey() {
        if (countKeys.empty())
            return "";
        return *(countKeys.begin()->second.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */