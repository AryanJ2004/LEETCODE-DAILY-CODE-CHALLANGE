class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxBit = 0;
        for (int num: nums) {
            maxBit |= num;

        }

        int res = 0;
        iteration(res, nums, maxBit, 0, 0);
        return res;
    }
    void iteration (int& res, vector<int>& nums, int& maxBit, int i, int bit_or) {

        if (i >= nums.size()) {
            if (bit_or == maxBit) {
                res++;
            }
            return;
        }
        iteration(res, nums, maxBit, i+1, bit_or);
        iteration(res, nums, maxBit, i+1, bit_or | nums[i]);
    };
};