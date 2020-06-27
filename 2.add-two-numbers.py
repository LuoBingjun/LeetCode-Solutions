#
# @lc app=leetcode id=2 lang=python3
#
# [2] Add Two Numbers
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        n1 = l1
        n2 = l2
        # l3 = l1
        res = 0
        while True:
            res = n1.val + n2.val + res
            n1.val = res % 10
            res = res // 10

            if n1.next != None:
                n1 = n1.next
                if n2.next != None:
                    n2 = n2.next
                else:
                    if res > 0:
                        n2.val = 0
                    else:
                        break
            else:
                if n2.next == None:
                    if res > 0:
                        n1.next = ListNode(res)
                    break
                else:
                    n1.next = n2.next
                    if res == 0:
                        break
                    else:
                        n1 = n1.next
                        n2.val = 0
                        n2.next = None

        return l1
# @lc code=end

