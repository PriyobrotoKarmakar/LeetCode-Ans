class trieNode {
public:
    int child[26];
    bool isEnd;
    trieNode() {
        for (int i = 0; i < 26; i++) {
            child[i] = -1;
        }
        isEnd = false;
    }
};

class Trie {
public:
    vector<trieNode> trie;
    Trie() { trie.emplace_back(); }

    void insert(string& word) {
        int v = 0;
        for (char ch : word) {
            int i = ch - 'a';
            if (trie[v].child[i] == -1) {
                trie[v].child[i] = trie.size();
                trie.emplace_back();
            }
            v = trie[v].child[i];
        }
        trie[v].isEnd = true;
    }
};

class Solution {
public:
    vector<string> ans;
    vector<vector<bool>> vis;

    void solve(Trie& trieDS, vector<vector<char>>& board, int i, int j, int n,
               int m, int v, string temp) {
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j])
            return;

        char ch = board[i][j];
        int idx = ch - 'a';

        if (trieDS.trie[v].child[idx] == -1)
            return;

        v = trieDS.trie[v].child[idx];
        temp += ch;

        if (trieDS.trie[v].isEnd) {
            ans.push_back(temp);
            trieDS.trie[v].isEnd = false;
        }

        vis[i][j] = true;

        solve(trieDS, board, i + 1, j, n, m, v, temp);
        solve(trieDS, board, i - 1, j, n, m, v, temp);
        solve(trieDS, board, i, j + 1, n, m, v, temp);
        solve(trieDS, board, i, j - 1, n, m, v, temp);

        temp.pop_back();
        vis[i][j] = false;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        Trie trieDS;
        for (auto& word : words) {
            trieDS.insert(word);
        }

        int n = board.size();
        int m = board[0].size();
        vis.assign(n, vector<bool>(m, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                solve(trieDS, board, i, j, n, m, 0, "");
            }
        }

        return ans;
    }
};
