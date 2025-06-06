class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        int t=0;
        while(true){
            for(int i=0;i<n;i++){
            if(tickets[i]>0){
                t++;
                tickets[i]-=1;
            }
            if(i==k && tickets[i]==0){
                return t;
            }
        }
        }
        
        return 0;
    }
};