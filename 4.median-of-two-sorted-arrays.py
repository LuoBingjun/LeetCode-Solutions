#
# @lc app=leetcode id=4 lang=python3
#
# [4] Median of Two Sorted Arrays
#

# @lc code=start
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m = len(nums1)
        n = len(nums2)
        l = list()
        i = j = last = 0
        while True:
            if i == m and j == n:
                break
            if i == m:
                l.append(nums2[j])
                j = j + 1
            elif j == n:
                l.append(nums1[i])
                i = i + 1
            else:
                if nums1[i] < nums2[j]:
                    l.append(nums1[i])
                    i = i + 1
                else:
                    l.append(nums2[j])
                    j = j + 1

        length = len(l)
        if length % 2 == 0:
            return (l[length // 2 - 1] + l[length // 2]) / 2
        else:
            return l[length // 2]

# @lc code=end

