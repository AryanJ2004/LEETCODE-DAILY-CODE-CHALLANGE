class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>stk;
        int c=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                stk.push('(');
            }else{
                if(stk.empty())
                c++;
                else
                stk.pop();
            }
        }
        return c+stk.size();
    }
};