#
# @lc app=leetcode id=3 lang=python3
#
# [3] Longest Substring Without Repeating Characters
#

# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        chs = set()
        i = j = 0
        length = 0
        while True:
            if j == len(s):
                break
            if s[j] in chs:
                length = max(length, len(chs))
                chs.remove(s[i])
                i += 1
            else:
                chs.add(s[j])
                j += 1

        length = max(length, len(chs))
        return length
# @lc code=end

