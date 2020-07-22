/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */
#include <vector>
#include <set>
#include <stack>
using namespace std;
// @lc code=start
class Solution
{
    vector<vector<int>> ans;
    void DFS(vector<int> &nums, vector<int> &path, int n, int i)
    {
        if (path.size() == n)
        {
            ans.push_back(path);
            return;
        }

        for(int j = i; j < nums.size(); j++)
        {
            path.push_back(nums[j]);
            DFS(nums, path, n, j + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        ans.emplace_back();
        if (nums.empty())
            return ans;
        vector<int> path;
        for (int i = 1; i <= nums.size(); i++)
        {
            DFS(nums, path, i, 0);
        }
        return ans;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> input({1, 2, 3});
    sol.subsets(input);
    return 0;
}