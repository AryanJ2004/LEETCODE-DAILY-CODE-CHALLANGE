class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0;
        int cnt2=0;
        int el1=INT_MIN;
        int el2=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(cnt1==0 && el2!=nums[i]){
                cnt1=1;
                el1=nums[i];
            } else if(cnt2==0 && el1!=nums[i]){
                cnt2=1;
                el2=nums[i];
            }else if(nums[i]==el1) cnt1++;
            else if(nums[i]==el2) cnt2++;
            else cnt1--,cnt2--;
        }
        int c1=0,c2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==el1) c1++;
            if(nums[i]==el2) c2++;
        }
        int mini=(nums.size()/3);
        vector<int>ans;
        if(c1>mini){
            ans.push_back(el1);
        }
        if(c2>mini){
            ans.push_back(el2);
        }
        return ans;
    }
};