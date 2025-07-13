class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int mxidx=0;
        for(int i=0;i<n;i++){
            if(i>mxidx) return false;
            if(mxidx>n-1) break;
            mxidx=max(mxidx,nums[i]+i);
        }
        return true;
    }
};