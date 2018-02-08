# coding: utf8


"""
    题目链接: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description.
    题目描述:

    Say you have an array for which the ith element is the price of a given stock on day i.

    If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock),
    design an algorithm to find the maximum profit.

    Example 1:
    Input: [7, 1, 5, 3, 6, 4]
    Output: 5

    max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
    Example 2:
    Input: [7, 6, 4, 3, 1]
    Output: 0

    In this case, no transaction is done, i.e. max profit = 0.

"""


class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0

        return self.dynamic_max_profit(prices)

    # 动态规划
    # 搜索局部上升子序列, 保存当前最优解
    def dynamic_max_profit(self, prices):
        start = 0
        ans = 0
        for i in range(1, len(prices)):
            delta = prices[i] - prices[start]
            if delta > 0:
                ans = max(ans, delta)
            else:
                start = i

        return ans
