/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */
#include <string>
#include <vector>
#include <climits>
using namespace std;
// @lc code=start
class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.empty() || t.empty())
            return "";
        vector<int> t_c(128, 0);
        for (char c : t)
            t_c[c]++;
        int counter = t.size();
        int left = 0, min = s.size() + 1;
        int i = 0, j = 0;
        while (j <= s.size() && i < s.size())
        {
            if (counter > 0)
            {
                if (j == s.size())
                    break;
                t_c[s[j]]--;
                if (t_c[s[j]] >= 0)
                {
                    counter--;
                }
                j++;
            }
            else
            {
                if (j - i < min)
                {
                    min = j - i;
                    left = i;
                }
                t_c[s[i]]++;
                if (t_c[s[i]] > 0)
                {
                    counter++;
                }
                i++;
            }
        }

        if (min == s.size() + 1)
            return "";
        else
            return s.substr(left, min);
    }
};
// @lc code=end

int main()
{
    Solution sol;
    sol.minWindow("ADOBECODEBANC", "ABC");
    sol.minWindow("a", "a");
    return 0;
}