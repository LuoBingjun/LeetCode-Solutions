/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else if (nums[mid] == 2)
            {
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> input1({2, 0, 2, 1, 1, 0});
    sol.sortColors(input1);
    return 0;
}