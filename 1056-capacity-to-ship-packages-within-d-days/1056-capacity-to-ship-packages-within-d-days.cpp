class Solution {
public:
    int dayreq(vector<int>& weights, int days,int mid){
        int load=0,day=1;

        for(int i=0;i<weights.size();i++){
            if((load+weights[i])>mid){
                day++;
                load=weights[i];
            }else{
                load+=weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int mx=*max_element(weights.begin(),weights.end());
        int sum=accumulate(weights.begin(),weights.end(),0);
        int ans=0;
        int low=mx,high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            if(dayreq(weights,days,mid)<=days){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};