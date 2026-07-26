class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int smallest=INT_MAX;
        for(int i=0;i<nums1.size();i++){


            for(int j=0;j<nums2.size();j++){
                int num1=nums2[j]*10+nums1[i];
                int num=nums1[i]*10+nums2[j];
                int smnum=num<num1?num:num1;
                if(nums1[i]==nums2[j]){
                    if(nums1[i]<smallest)
                        smallest=nums1[i];
                }
                else if(smnum<smallest){
                    smallest=smnum;
                }
            }
        }

        return smallest;
    }
};