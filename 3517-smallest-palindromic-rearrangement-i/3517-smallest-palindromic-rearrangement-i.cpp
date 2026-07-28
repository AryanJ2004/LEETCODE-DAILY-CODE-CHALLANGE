class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>cnt(26,0);

        for(auto x:s){
            cnt[x-'a']++;
        }

        string half="", mid="";

        for(int i=0;i<cnt.size();i++){
            half.append(cnt[i]/2,char('a'+i));

            if(cnt[i]%2){
                mid=char('a'+i);
            }
        }

        string rev=half;

        reverse(rev.begin(),rev.end());

        return half+mid+rev;

    }
};