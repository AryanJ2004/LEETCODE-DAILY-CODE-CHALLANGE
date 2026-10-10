class Solution {
public:

    static bool compare(vector<int>p1,vector<int>p2){
        return p1[1]<p2[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),compare);
        int cnt=0;
        int lastEnd=INT_MIN;
        for(int i=0;i<pairs.size();i++){
            if(pairs[i][0]>lastEnd){
                cnt++;
                lastEnd=pairs[i][1];
            }
            
        }

        return cnt;
    }
};