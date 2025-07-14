class Solution {
public:
    bool possible(vector<int>bloomDay,int mid,int m,int k){

        int cnt=0,pb=0;

        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                cnt++;
            }else{
                pb+=cnt/k;
                cnt=0;
            }
        }
        pb+=cnt/k;

        if(pb>=m) return true;
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k>bloomDay.size()) return -1;
        int mn=*min_element(bloomDay.begin(),bloomDay.end());
        int mx=*max_element(bloomDay.begin(),bloomDay.end());

        int low=mn,high=mx;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;

            if(possible(bloomDay,mid,m,k)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
    
};