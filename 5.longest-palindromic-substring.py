#
# @lc app=leetcode id=5 lang=python3
#
# [5] Longest Palindromic Substring
#

# @lc code=start
class Solution:
    def longestPalindrome(self, s: str) -> str:
        l = len(s)
        mem = [[-1 for i in range(l)] for i in range(l)]
        def eval_mem(i, j):
            if mem[i][j] != -1:
                return mem[i][j]
            # eval
            if i == j:
                mem[i][j] = 1
                return 1
            else:
                if s[i] == s[j]:
                    if j - i == 1:
                        mem[i][j] = 1
                        return 1
                    else:
                        res = eval_mem(i + 1, j - 1)
                        mem[i][j] = res
                        return res
                else:
                    mem[i][j] = 0
                    return 0
        
        max_length = 1
        max_sub = (0, 0)

        for le in range(1, l + 1):
            for i in range(0, l - le):
                j = i + le
                if eval_mem(i, j) == 1 and j - i + 1 > max_length:
                    max_length = j - i + 1
                    max_sub = (i, j)
        
        i, j = max_sub
        return s[i:j + 1]
                    
# @lc code=end
sol = Solution()
print(sol.longestPalindrome("babad"))
print(sol.longestPalindrome("cbbd"))
print(sol.longestPalindrome("a"))
print(sol.longestPalindrome("ba"))
print(sol.longestPalindrome("bb"))
print(sol.longestPalindrome("bab"))
print(sol.longestPalindrome("baba"))

