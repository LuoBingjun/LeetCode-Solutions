#
# @lc app=leetcode id=10 lang=python3
#
# [10] Regular Expression Matching
#

# @lc code=start
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        def _isMatch(i, j) -> bool: 
            if j == len(p):
                if i == len(s):
                    return True
                else:
                    return False

            if j == len(p) - 1 or p[j + 1] != '*':
                if i == len(s):
                    return False
                elif s[i] == p[j] or p[j] == '.':
                    return _isMatch(i + 1, j + 1)
            else: #p[j + 1] == '*'
                if i == len(s):
                    return _isMatch(i, j + 2)
                elif s[i] == p[j] or p[j] == '.':
                    return _isMatch(i + 1, j) or _isMatch(i, j + 2)
                else:
                    return _isMatch(i, j + 2)
            
            return False

        return _isMatch(0, 0)
# @lc code=end

sol = Solution()
print(sol.isMatch("aa", "a"))
print(sol.isMatch("aa", "a*"))
print(sol.isMatch("ab", ".*"))
print(sol.isMatch("aab", "c*a*b"))
print(sol.isMatch("mississippi", "mis*is*p*."))
