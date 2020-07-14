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
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mem;
        for (int i = 0; i < strs.size(); i++)
        {
            string key(strs[i]);
            sort(key.begin(), key.end());
            pair<unordered_map<string, vector<string>>::iterator, bool> ret = mem.emplace(key, vector<string>());
            ret.first->second.push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto i : mem)
        {
            ans.push_back(i.second);
        }
        return ans;
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