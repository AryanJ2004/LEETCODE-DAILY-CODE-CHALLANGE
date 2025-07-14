class Solution {
public:
    long long calhrs(vector<int>piles,long long mid){
        long long hrs=0;
        for(long long i=0;i<piles.size();i++){
            hrs+=ceil(double(piles[i])/double(mid));
        }
        return hrs;
    }
    int minEatingSpeed(vector<int>& piles, long long h) {
        long long low=1;
        long long high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            long long mid=(low+high)/2;

            long long tot_hrs=calhrs(piles,mid);

            if(tot_hrs<=h){
                high=mid-1;
            }else low=mid+1;
        }

        return int(low);
    }
};