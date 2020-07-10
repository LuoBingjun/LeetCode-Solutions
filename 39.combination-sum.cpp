/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
    vector<vector<int>> ans;

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        ans.clear();
        sort(candidates.begin(), candidates.end());
        selectElement(candidates, target, vector<int>(), 0);
        return ans;
    }

    void selectElement(vector<int> &candidates, int target, vector<int> path, int i)
    {
        if (target == 0)
        {
            ans.push_back(path);
            return;
        }
        if (i == candidates.size() || target < candidates[i])
            return;

        selectElement(candidates, target, path, i + 1);
        while (target >= candidates[i])
        {
            target -= candidates[i];
            path.push_back(candidates[i]);
            selectElement(candidates, target, path, i + 1);
        }
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> input1({2, 3, 6, 7});
    sol.combinationSum(input1, 7);
    vector<int> input2({2, 3, 5});
    sol.combinationSum(input2, 8);
    return 0;
}