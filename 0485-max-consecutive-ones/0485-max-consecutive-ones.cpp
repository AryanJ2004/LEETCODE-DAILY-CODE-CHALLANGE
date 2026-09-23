class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;
        int mxcnt=0;
        for(auto n:nums){
            if(n==1){
                cnt++;
                mxcnt=max(mxcnt,cnt);
            }else{
                cnt=0;
            }
        }
        return mxcnt;
    }
};