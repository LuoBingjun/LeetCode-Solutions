/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */
#include <vector>
#include <set>
#include <deque>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int> &nums)
    {
        if (nums.empty())
            return {{}};
        DFS(nums, 0);
        return ans;
    }

    void DFS(vector<int> &nums, int i)
    {
        if (i == nums.size() - 1)
        {
            ans.push_back(nums);
        }
        else
        {
            for (int j = i; j < nums.size(); j++)
            {
                swap(nums[i], nums[j]);
                DFS(nums, i + 1);
                swap(nums[i], nums[j]);
            }
        }
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