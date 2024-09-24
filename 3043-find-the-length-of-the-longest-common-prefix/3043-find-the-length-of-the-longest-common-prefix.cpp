class TrieNode {
public:
    TrieNode* next[10];

    TrieNode(){
        for(int i=0; i<10; i++)
            next[i] = NULL;
    }
};

class Solution {
    TrieNode* root;

    void clear(TrieNode* curr){
        for(int i=0; i<10; i++){
            if(curr->next[i])
                clear(curr->next[i]);
        }

        delete curr;
    }

    void addString(string str){
        TrieNode* curr = root;

        for(char& ch:str){
            if(!curr->next[ch-'0'])
                curr->next[ch-'0'] = new TrieNode();
            
            curr = curr->next[ch-'0'];
        }
    }

    int searchLongestPrefix(string str){
        int len = 0;
        TrieNode* curr = root;

        for(char& ch:str){
            if(curr->next[ch-'0']){
                curr = curr->next[ch-'0'];
                len++;
            }
            else
                break;
        }

        return len;
    }

public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        root = new TrieNode();

        for(int& a:arr1)
            addString(to_string(a));    
        
        int res = 0;
        for(int& a:arr2)
            res = max(res, searchLongestPrefix(to_string(a)));
                
        clear(root);

        return res;
    }
};