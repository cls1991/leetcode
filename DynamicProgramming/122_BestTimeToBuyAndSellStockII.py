# coding: utf8


"""
    题目链接: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description.
    题目描述:

    Say you have an array for which the ith element is the price of a given stock on day i.

    Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and
    sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time
    (ie, you must sell the stock before you buy again).

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

    # 动态规划:
    # 搜索所有的上升子序列, 求和
    def dynamic_max_profit(self, prices):
        ans = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                ans += prices[i] - prices[i - 1]

        return ans
