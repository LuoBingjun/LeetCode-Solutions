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
        vector<set<string>> ans(n + 1);
        ans[0].insert("");
        ans[1].insert("()");
        for (int i = 2; i <= n; i++)
        {
            set<string>& v = ans[i];
            for (int l = 0; l < i; l += 1)
            {
                for(auto& m : ans[l])
                {
                    for(auto& n : ans[i - 1 - l])
                    {
                        v.insert('(' + m + ')' + n);
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