class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,zeors=0,maxl=0;

        while(r<nums.size()){
            if(nums[r]==0) zeors++;

            if(zeors>k){
               if(nums[l]==0) zeors--;
               l++;
            }else{
                int len=r-l+1;
                maxl=max(len,maxl);
            }
            r++;
        }
        return maxl;
    }
};