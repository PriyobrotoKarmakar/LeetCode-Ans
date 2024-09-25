class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        int prefixCount;
        TrieNode() {
            prefixCount = 0;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    
    class Trie {
    public:
        TrieNode* root;
        
        Trie() {
            root = new TrieNode();
        }
        
        void insert(const string& word) {
            TrieNode* node = root;
            for (char ch : word) {
                int idx = ch - 'a';
                if (!node->children[idx]) {
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
                node->prefixCount++;  // Increment prefix count for each node
            }
        }
        
        int getPrefixScore(const string& word) {
            TrieNode* node = root;
            int score = 0;
            for (char ch : word) {
                int idx = ch - 'a';
                node = node->children[idx];
                score += node->prefixCount;  // Add the prefix count to the score
            }
            return score;
        }
    };
    
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for (const string& word : words) {
            trie.insert(word);  // Insert each word into the trie
        }
        
        vector<int> result;
        for (const string& word : words) {
            result.push_back(trie.getPrefixScore(word));  
        }
        
        return result;
    }
};
