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
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        selectElement(candidates, target, path, 0);
        return ans;
    }

    void selectElement(vector<int> &candidates, int target, vector<int> &path, int i)
    {
        if (target == 0)
        {
            ans.push_back(path);
            return;
        }
        if (i == candidates.size() || target < candidates[i])
            return;

        for (int j = i; j < candidates.size(); j++)
        {
            path.push_back(candidates[j]);
            selectElement(candidates, target - candidates[j], path, j);
            path.pop_back();
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