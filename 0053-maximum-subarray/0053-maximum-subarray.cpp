class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();

        int sum=0;
        int mxsum=INT_MIN;

        for(int i=0;i<nums.size();i++){
             if(sum<0){
                sum=0;
            }
            sum+=nums[i];
           

            
            mxsum=max(sum,mxsum);

            
        }
        return mxsum;
    }
};