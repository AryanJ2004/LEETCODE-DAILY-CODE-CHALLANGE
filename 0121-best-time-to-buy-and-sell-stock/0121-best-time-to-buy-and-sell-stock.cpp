class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int least=9999;
        int profit=0;
        int pist=0;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<least)
            least=prices[i];
        
        pist=prices[i]-least;
        // if(profit<pist)
        // profit=pist;
        profit=max(profit,pist);
        }
        return profit;
    }
};