class Solution {
public:
    bool possible(vector<int>& nums, int mid,int threshold){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil(nums[i]/float(mid));
        }

        if(sum<=threshold) return true;
        else return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int mx=*max_element(nums.begin(),nums.end());
        int low=1,high=mx;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;

            if(possible(nums,mid,threshold)){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};