# coding: utf8


"""
    题目链接: https://leetcode.com/problems/insert-interval/description.
    题目描述:

    Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

    You may assume that the intervals were initially sorted according to their start times.

    Example 1:
        Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

    Example 2:
        Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

        This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

"""


# Definition for an interval.
class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

    def __repr__(self):
        return '(start: {0}, end: {1})'.format(self.start, self.end)


class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        intervals.append(newInterval)

        result = []
        intervals.sort(key=lambda val: val.start)
        first_interval = intervals[0]
        start, end = first_interval.start, first_interval.end
        for interval in intervals:
            if interval.start <= end:
                end = max(end, interval.end)
            else:
                result.append(Interval(start, end))
                start = interval.start
                end = interval.end

        result.append(Interval(start, end))

        return result
