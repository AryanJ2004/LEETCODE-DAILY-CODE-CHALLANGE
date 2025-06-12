class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int tot_sum=0;
        for(auto i:nums){
            tot_sum+=i;
        }

        int cur_sum=0;
        for(int i=0;i<nums.size();i++){
            cur_sum+=nums[i];

            int l_sum=cur_sum-nums[i];
            int r_sum=tot_sum-cur_sum;

            if(l_sum==r_sum){
                return i;
            }
        }
        return -1;
    }
};