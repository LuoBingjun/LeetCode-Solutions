#
# @lc app=leetcode id=10 lang=python3
#
# [10] Regular Expression Matching
#

# @lc code=start
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        dp = [[-1 for j in range(len(p) + 1)] for i in range(len(s) + 1)]

        def _isMatch(i, j) -> bool: 
            if dp[i][j] != -1:
                return dp[i][j]

            if j == len(p):
                if i == len(s):
                    dp[i][j] = True
                    return True
                else:
                    dp[i][j] = False
                    return False

            if j == len(p) - 1 or p[j + 1] != '*':
                if i == len(s):
                    dp[i][j] = False
                elif s[i] == p[j] or p[j] == '.':
                    dp[i][j] = _isMatch(i + 1, j + 1)
                else:
                    dp[i][j] = False
            else: #p[j + 1] == '*'
                if i == len(s):
                    dp[i][j] = _isMatch(i, j + 2)
                elif s[i] == p[j] or p[j] == '.':
                    dp[i][j] = _isMatch(i + 1, j) or _isMatch(i, j + 2)
                else:
                    dp[i][j] = _isMatch(i, j + 2)
            
            return dp[i][j]

        return _isMatch(0, 0)
# @lc code=end

sol = Solution()
print(sol.isMatch("aa", "a"))
print(sol.isMatch("aa", "a*"))
print(sol.isMatch("ab", ".*"))
print(sol.isMatch("aab", "c*a*b"))
print(sol.isMatch("mississippi", "mis*is*p*."))
