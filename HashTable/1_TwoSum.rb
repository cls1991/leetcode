# ================================================================================
#  LeetCode - Algorithms - 1. Two Sum
#  https://leetcode.com/problems/two-sum/description
# 
#  Language: Ruby
#  Author: ConradG
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
#   第一反应为双循环遍历，发现题目归类于 Hash Table 中后也尝试使Hash Table 进行处理。
# 在单线程场景下，使用Hash的方式有更优秀的时间复杂度，而双循环则更易拆分为多个线程。
#
# * Ruby中 []= 的优先级和 [] 一致，为除 () 外的最高优先级
# ================================================================================

# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}

def two_sum(nums, target)
    s = Hash.new
    num, i = nums.each_with_index.detect {|(num, i)| s[target - num] || !s[num] = i}
    [s[target - num], i]
end

#
# 19 / 19 test cases passed.
# Status: Accepted
# Runtime: 57 ms
# Your runtime beats 75.07 % of ruby submissions.
#
