class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre=1,suff=1;
        int n=nums.size();
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            if(pre==0) pre=1;
            if(suff==0) suff=1;

            pre*=nums[i];
            suff*=nums[n-i-1];
            mx=max(mx,max(pre,suff));
        }

        return mx;
    }
};