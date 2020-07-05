#
# @lc app=leetcode id=19 lang=python3
#
# [19] Remove Nth Node From End of List
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        i = 0
        n0 = None
        n1 = p = head
        while p:
            if i == n:
                n0 = n1
                n1 = n1.next
            else:
                i += 1
            p = p.next
        
        if n0:
            n0.next = n1.next
        else:
            head = n1.next
        return head
# @lc code=end
head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
sol = Solution()
sol.removeNthFromEnd(head, 2)