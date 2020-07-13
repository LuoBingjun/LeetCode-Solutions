/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */
#include <vector>
#include <set>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int> &nums)
    {
        if (nums.empty())
        {
            ans.push_back({});
            return ans;
        }
        set<int> rest(nums.begin(), nums.end());
        vector<int> path;
        for (auto i : rest)
        {
            DFS(path, rest, i);
        }
        return ans;
    }

    void DFS(vector<int> &path, set<int> rest, int val)
    {
        rest.erase(val);
        path.push_back(val);
        if (rest.empty())
        {
            ans.push_back(path);
        }
        else
        {
            for (auto i : rest)
            {
                DFS(path, rest, i);
            }
        }
        path.pop_back();
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> input1({1, 2, 3});
    sol.permute(input1);
    return 0;
}