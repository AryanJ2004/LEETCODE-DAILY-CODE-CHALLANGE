class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int Sall=((n*(n+1))/2);
        auto first=nums.begin();
        auto end=nums.end();
        int sumarr=accumulate(first,end,0);
        return Sall-sumarr;
    }
};