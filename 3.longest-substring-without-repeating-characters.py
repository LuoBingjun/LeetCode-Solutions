#
# @lc app=leetcode id=3 lang=python3
#
# [3] Longest Substring Without Repeating Characters
#

# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ch_ind = dict()
        i = j = 0
        length = 0

        for index, ch in enumerate(s):
            if ch in ch_ind and ch_ind[ch] >= i:
                i = ch_ind[ch] + 1
                j = index
                ch_ind[ch] = index
            else:
                ch_ind[ch] = index
                j = index
                length = max(length, j - i + 1)

        return length
# @lc code=end

