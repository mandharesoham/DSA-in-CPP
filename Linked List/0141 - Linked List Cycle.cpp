/*
Problem: 141. Linked List Cycle
Platform: LeetCode
Difficulty: Easy

Tags:
- Linked List
- Two Pointers
- Floyd's Cycle Detection

Time Complexity: O(n)
Space Complexity: O(1)

Approach:
Use two pointers: slow and fast.
Move slow one step at a time and fast two steps at a time.
If the linked list contains a cycle, the two pointers
will eventually meet. If fast reaches NULL, no cycle exists.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
                return true;
        }
        return false;
    }
};
