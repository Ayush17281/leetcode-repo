class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int buy  = INT_MAX;
        int profit_today;
        int max_profit = 0 ;
        for(int i =0 ;i<prices.size();i++){
            buy = min( buy ,prices[i] );
            profit_today = prices[i] -  buy ;
            max_profit = max(max_profit, profit_today);
        }
 
return max_profit ;
 

}
};