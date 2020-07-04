#
# @lc app=leetcode id=11 lang=python3
#
# [11] Container With Most Water
#
from typing import List
# @lc code=start
class Solution:
    def maxArea(self, height: List[int]) -> int:
        i = 0
        j = len(height) - 1
        maxRes = 0
        while i < j:
            maxRes = max(maxRes, min(height[i], height[j]) * (j - i))
            if height[i] < height[j]:
                h0 = height[i]
                while True:
                    i += 1
                    if height[i] > h0 or i == j:
                        break
            else:
                h0 = height[j]
                while True:
                    j -= 1
                    if height[j] > h0 or i == j:
                        break
        
        return maxRes

# @lc code=end
sol = Solution()
print(sol.maxArea([1,8,6,2,5,4,8,3,7]))