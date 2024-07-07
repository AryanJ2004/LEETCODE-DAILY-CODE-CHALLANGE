class Solution {
public:
    int search(vector<int>& nums, int target) {
        int si=0;
        int ei=nums.size()-1;
        int ans=search(nums,si,ei,target);
        return ans;
    }

    int search(vector<int>vec,int si,int ei,int tar)
    {
        if(si>ei)
        return -1;
        
        int mid=si+(ei-si)/2;
        if(vec[mid]==tar)
        return mid;
        if(vec[si]<=vec[mid])
        {
            if(vec[si]<=tar && tar<=vec[mid])
            return search(vec,si,mid-1,tar);
            else
            return search(vec,mid+1,ei,tar);
        }
        else
        {
            if(vec[mid]<=tar&& tar<=vec[ei])
            return search(vec,mid+1,ei,tar);
            else
            return search(vec,si,mid-1,tar);
        }
    }
};