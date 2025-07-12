class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();

        sort(pairs.begin(),pairs.end(),compare);
        int ans=1;
        int currEnd=pairs[0][1];

        for(int i=1;i<n;i++){
            if(pairs[i][0]>currEnd){
                ans++;
                currEnd=pairs[i][1];
            }
        }
        return ans;

    }
};