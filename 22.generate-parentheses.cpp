/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
#include <vector>
#include <string>
#include <set>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<vector<string>> ans(n + 1);
        ans[0].push_back("");
        ans[1].push_back("()");
        for (int i = 2; i <= n; i++)
        {
            vector<string>& v = ans[i];
            for (int l = 0; l < i; l += 1)
            {
                for(auto& m : ans[l])
                {
                    for(auto& n : ans[i - 1 - l])
                    {
                        v.push_back('(' + m + ')' + n);
                    }
                }
            }
        }
        return vector<string>(ans[n].begin(), ans[n].end());
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<string> &&res = sol.generateParenthesis(4);
    return 0;
}