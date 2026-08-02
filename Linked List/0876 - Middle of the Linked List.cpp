/*
Problem: 876. Middle of the Linked List
Platform: LeetCode
Difficulty: Easy

Tags:
- Linked List
- Two Pointers
- Fast & Slow Pointer

Time Complexity: O(n)
Space Complexity: O(1)

Approach:
Use two pointers: slow and fast.
Move slow one step at a time and fast two steps at a time.
When fast reaches the end of the list, slow will be at the middle.
If there are two middle nodes, return the second middle node.
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
