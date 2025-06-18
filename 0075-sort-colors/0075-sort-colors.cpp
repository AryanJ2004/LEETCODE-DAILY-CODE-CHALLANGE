class Solution {
public:
    void sortColors(vector<int>& nums) {
        int hash[3]={0};
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }

        int index = 0;
        for(int color = 0; color < 3; color++) {
            while(hash[color]--) {
                nums[index++] = color;
            }
        }
        for(auto n : nums) {
            cout << n << " ";
        }

    }
};