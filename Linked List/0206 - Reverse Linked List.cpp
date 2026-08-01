/*
Problem: 206. Reverse Linked List
Platform: LeetCode
Difficulty: Easy

Tags:
- Linked List
- Recursion

Time Complexity: O(n)
Space Complexity: O(1)   // Iterative approach

Approach:
Traverse the linked list while maintaining three pointers:
prev, curr, and next.
Reverse the direction of each node's next pointer.
Move all pointers forward until the end of the list.
Return the new head (prev).
*/

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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr != NULL) {

            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
