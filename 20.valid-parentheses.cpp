/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
#include <string>
#include <stack>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            switch (c)
            {
            case '(':
            case '{':
            case '[':
                st.push(c);
                continue;

            case ')':
                if (!st.empty() && st.top() == '(')
                {
                    st.pop();
                    continue;
                }
                break;
            case '}':
                if (!st.empty() && st.top() == '{')
                {
                    st.pop();
                    continue;
                }
                break;
            case ']':
                if (!st.empty() && st.top() == '[')
                {
                    st.pop();
                    continue;
                }
                break;
            }
            return false;
        }
        if (st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
// @lc code=end

int main()
{
    Solution sol;
    cout << sol.isValid("()") << endl;
    cout << sol.isValid("()[]{}") << endl;
    cout << sol.isValid("(]") << endl;
    cout << sol.isValid("([)]") << endl;
    cout << sol.isValid("{[]}") << endl;
    return 0;
}
