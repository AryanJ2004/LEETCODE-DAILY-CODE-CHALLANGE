class Solution {
public:
    int firstUniqChar(string s) {
        queue <char>q;
        int freq[26]={0};

        for(int i=0;i<s.size();i++){
            char ch=s[i];
            freq[ch-'a']++;

            q.push(ch);

            while(!q.empty() && freq[q.front()-'a']>1){
                q.pop();
            }
        }
        if(!q.empty()){
            int idx=s.find(q.front());
            return idx;
        }else{
            return -1;
        }
    }
};