class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int prefixCount;
    
    TrieNode() {
        prefixCount = 0;
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
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->prefixCount++;
        }
    }
    
    int getPrefixScore(const string& word) {
        TrieNode* node = root;
        int score = 0;
        for (char c : word) {
            node = node->children[c];
            score += node->prefixCount;
        }
        return score;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        vector<int> result;
        
        // Insert all words into the trie
        for (const string& word : words) {
            trie.insert(word);
        }
        
        // Get the prefix score for each word
        for (const string& word : words) {
            result.push_back(trie.getPrefixScore(word));
        }
        
        return result;
    }
};