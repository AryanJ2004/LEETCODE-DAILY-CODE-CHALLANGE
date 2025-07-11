class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cnt=0;
        int l=0; int r=0; int s1=g.size();int s2=s.size();
        while(l<s1 && r<s2){
            if(g[l]<=s[r]){
                cnt++;
                l++;
            }
            r++;

        }
        return cnt;
    }
};