class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = nums.size();
        int idx = max_element(nums.begin(), nums.end()) - nums.begin();
        int ans = 0, maxi = nums[idx];
        for (int i = idx; i < n; i++) {
            int temp = 0;
            while (i < n && nums[i] == maxi) {
                i++;
                temp++;
            }
            ans = max(temp, ans);
        }
        return ans;
    }
};