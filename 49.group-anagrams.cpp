/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    inline string getKey(string str)
    {
        sort(str.begin(), str.end());
        return str;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;
        unordered_map<string, int> keyToPos;
        for (const auto &str : strs)
        {
            string k(str);
            sort(k.begin(), k.end());
            if (keyToPos.count(k) == 0)
            {
                keyToPos[k] = res.size();
                res.emplace_back();
            }
            res[keyToPos[k]].push_back(str);
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<string> input1({"eat", "tea", "tan", "ate", "nat", "bat"});
    sol.groupAnagrams(input1);
    return 0;
}