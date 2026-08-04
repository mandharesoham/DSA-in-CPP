/*
Problem: 21. Merge Two Sorted Lists
Platform: LeetCode
Difficulty: Easy

Tags:
- Linked List
- Recursion

Time Complexity: O(n + m)
Space Complexity: O(n + m)   // Due to recursion stack

Approach:
Use recursion to merge the two sorted linked lists.
If either list is empty, return the other list.
Compare the current nodes of both lists:
- If the first node is smaller, recursively merge the
  remaining part of the first list with the second list.
- Otherwise, recursively merge the first list with the
  remaining part of the second list.
Return the head of the merged list.
*/


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {

        if (head1 == NULL || head2 == NULL) {

            return head1 == NULL ? head2 : head1;
        }
        //case 1
        if (head1->val <= head2->val) {
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        } else { //case 2
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }
};
