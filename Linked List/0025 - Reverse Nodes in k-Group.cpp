/*
Problem: 25. Reverse Nodes in k-Group
Platform: LeetCode
Difficulty: Hard

Tags:
- Linked List
- Recursion

Time Complexity: O(n)
Space Complexity: O(n / k)   // Recursion stack

Approach:
First, check if there are at least k nodes available.
If fewer than k nodes remain, return the current head.
Reverse the first k nodes.
Recursively reverse the remaining list in groups of k.
Connect the tail of the reversed group to the head of the
next reversed group and return the new head.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;
        // check if k nodes exists
        while (cnt < k) {
            if (temp == NULL) {
                return head;
            }

            temp = temp->next;
            cnt++;
        }

        // recursively call for rest of LL
        ListNode* prevNode = reverseKGroup(temp, k);

        // reverse current group
        temp = head;
        cnt = 0;
        while (cnt < k) {
            ListNode* next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;
            cnt++;
        }

        return prevNode;
    }
};
