class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mostProfit = 0;
       int bestBuy = prices[0];
        int n = prices.size();

        for (int i=1; i<n; i++){
            if(prices[i] > bestBuy){
            mostProfit = max(mostProfit , prices[i]-bestBuy);
        }
        bestBuy = min(bestBuy , prices[i]);
        }
         return mostProfit;
    }
       
};