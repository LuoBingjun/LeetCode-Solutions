/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.empty())
            return vector<int>({-1, -1});
        int i = 0;
        int j = nums.size() - 1;
        int k;
        while (i <= j)
        {
            k = (i + j) / 2;
            if (nums[k] == target)
                break;
            else if (nums[k] < target)
                i = k + 1;
            else
                j = k - 1;
        }

        if (nums[k] != target)
            return vector<int>({-1, -1});

        int lower = k;
        while (i < lower)
        {
            if (nums[i] == target)
                break;
            int l = (i + lower) / 2;
            if (nums[l] == target)
                lower = l;
            else
                i = l + 1;
        }

        int higher = k;
        while (higher < j)
        {
            if (nums[j] == target)
                break;
            int l = (higher + j + 1) / 2;
            if (nums[l] == target)
                higher = l;
            else
                j = l - 1;
        }

        return vector<int>({i, j});
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> input1({5, 7, 7, 8, 8, 10});
    sol.searchRange(input1, 8);
    vector<int> input2({5, 7, 7, 8, 8, 10});
    sol.searchRange(input2, 6);
    vector<int> input2({5, 8, 8, 8, 8, 10});
    sol.searchRange(input2, 8);
    return 0;
}