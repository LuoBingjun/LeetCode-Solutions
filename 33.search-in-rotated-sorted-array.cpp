/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.empty())
            return -1;
        int i = 0;
        int j = nums.size() - 1;
        while (i < j)
        {
            int k = (i + j) / 2;
            if (nums[k] == target)
                return k;
            else
            {
                if (nums[i] < nums[j])
                {
                    if (nums[k] < target)
                        i = k + 1;
                    else
                        j = k - 1;
                }
                else
                {
                    if (nums[k] >= nums[i])
                    {
                        if (target > nums[k] || target <= nums[j])
                            i = k + 1;
                        else
                            j = k - 1;
                    }
                    else
                    {
                        if (target < nums[k] || target >= nums[i])
                            j = k - 1;
                        else
                            i = k + 1;
                    }
                }
            }
        }
        if (nums[i] == target)
            return i;
        else
            return -1;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> input1({4, 5, 6, 7, 0, 1, 2});
    sol.search(input1, 0);
    vector<int> input2({4, 5, 6, 7, 0, 1, 2});
    sol.search(input2, 3);
    return 0;
}
