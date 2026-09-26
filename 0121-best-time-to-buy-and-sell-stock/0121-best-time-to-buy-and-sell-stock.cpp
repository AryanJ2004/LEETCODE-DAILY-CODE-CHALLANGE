class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=prices[0];
        int maxprofit=0;



        for(int i=1;i<prices.size();i++){
            int currprofit=prices[i]-minprice;
            maxprofit=max(maxprofit,currprofit);
            minprice = min(minprice, prices[i]);
        }

        return maxprofit;
    }
};