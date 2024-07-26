class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int maxSum = INT_MIN; 
        int n=nums.size();
        int cnt=0;
    for(int start=0; start<n; start++) {
        int sum = 0;
        for(int i=start; i<n; i++) {
            sum += nums[i];
            if(sum==k)
            cnt++;
            maxSum = max(sum, maxSum);
        }
    }
    return cnt;
    }
};