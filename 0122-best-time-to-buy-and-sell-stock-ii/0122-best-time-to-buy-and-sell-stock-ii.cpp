class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int mostProfit = 0;
        // int bestBuy = prices[0];
        // int n = prices.size();

        // for (int i=0; i<n; i++){
        //     if(prices[i] > bestBuy){
        //        mostProfit = max(mostProfit , prices[i]-bestBuy);
        //     }
        //     if(prices[i] > bestBuy && != mostProfit.prices[i]){
        //         int secondMostProfit = mostProfit + 0;
        //         secondMostProfit = max(secondMostProfit , prices[i] - bestBuy);
        //     }
        //     bestBuy= min(bestBuy , prices[i]);

        // }
        // return secondMostProfit;


        int profit = 0;
        for (int i=1; i<prices.size(); i++){
            if(prices[i] > prices[i-1]){
                profit += prices[i] - prices[i-1];
            }
        }
        return profit;
        
        
    }
};