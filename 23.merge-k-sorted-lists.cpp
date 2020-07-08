/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return nullptr;
        vector<ListNode *> heads;
        for (ListNode *h : lists)
        {
            if (h)
                heads.push_back(h);
        }

        auto cmp = [](const ListNode *a, const ListNode *b) -> bool {
            return a->val > b->val;
        };
        make_heap(heads.begin(), heads.end(), cmp);

        ListNode head(-1);
        ListNode *cur = &head;
        while (!heads.empty())
        {
            ListNode* minNode = heads.front();
            cur->next = minNode;
            cur = cur->next;
            pop_heap(heads.begin(), heads.end(), cmp);
            heads.pop_back();
            if (minNode->next)
            {
                heads.push_back(minNode->next);
                push_heap(heads.begin(), heads.end(), cmp);
            }
        }
        return head.next;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    ListNode *ans;
    vector<ListNode *> input0({new ListNode(1, new ListNode(4, new ListNode(5))),
                               new ListNode(1, new ListNode(3, new ListNode(4))),
                               new ListNode(2, new ListNode(6))});
    ans = sol.mergeKLists(input0);
    vector<ListNode *> input1({nullptr,
                               new ListNode(2, new ListNode(6)),
                               nullptr});
    ans = sol.mergeKLists(input1);
    vector<ListNode *> input2({nullptr,
                               nullptr});
    ans = sol.mergeKLists(input2);
    return 0;
}