/*
问题描述：
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
*/

/*思路：
在目前最小的价格里，如果价格不是最小，那么就比较李屯，找出最大的
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;                       
        }
        
        int minPrice = prices[0];       //记录的最小的价格
        int maxProfit = 0;
        for (int i=0; i<prices.size(); i++) {
            if (prices[i] < minPrice) {    //先一直找到最小的价格，再在最小价格后的元素中找到最大的利润
                minPrice = prices[i];
            }
            else if (prices[i]-minPrice > maxProfit) {
                maxProfit = prices[i]-minPrice;
            }
        }
        return maxProfit;
    }
};
