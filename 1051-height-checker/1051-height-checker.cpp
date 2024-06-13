class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>vec;
        vec=heights;
        sort(vec.begin(),vec.end());
        int cnt=0;
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]!=heights[i])
            cnt++;
        }
        return cnt;
    }
};