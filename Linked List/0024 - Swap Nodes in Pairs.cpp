/*
Problem: 24. Swap Nodes in Pairs
Platform: LeetCode
Difficulty: Medium

Tags:
- Linked List
- Recursion

Time Complexity: O(n)
Space Complexity: O(n)   // Recursion stack

Approach:
Swap two nodes at a time using recursion.
For each pair, make the second node the new head,
recursively swap the remaining nodes, and connect the
first node after the second node.
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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) { // base case
            return head;
        }

        ListNode* first = head;
        ListNode* sec = head->next;
        ListNode* prev = NULL;

        while (first != NULL && sec != NULL) {
            ListNode* third = sec->next;
            sec->next = first;
            first->next = third;

            if (prev != NULL) {
                prev->next = sec;
            } else {
                head = sec;
            }
            // update
            prev = first;
            first = third;
            if (third != NULL) {
                sec = third->next;
            } else {
                sec = NULL;
            }
        }
        return head;
    }
};
