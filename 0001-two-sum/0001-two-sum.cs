public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int,int> mpp=new Dictionary<int,int>();
        for(int i=0;i<nums.Length;i++){
            int a=nums[i];
            int more=target-nums[i];
            if(mpp.ContainsKey(more)){
                return new int[] {mpp[more],i};
            }
            mpp[a]=i;
        }
        return new int[] {0};
    }
}