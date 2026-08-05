/*
Problem: 138. Copy List with Random Pointer
Platform: LeetCode
Difficulty: Medium

Tags:
- Linked List
- Hash Table

Time Complexity: O(n)
Space Complexity: O(n)

Approach:
Create a copy of each node and store the mapping between
the original node and its copied node using a hash map.
Traverse the list again to assign the next and random
pointers of each copied node using the stored mapping.
Return the head of the copied linked list.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) { //base case
            return NULL;
        }
        unordered_map<Node*, Node*> m;
        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = newHead;
        m[head] = newHead;

        while (oldTemp != NULL) {
            Node* copy = new Node(oldTemp->val);
            m[oldTemp] = copy;
            newTemp->next = copy;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        oldTemp = head;
        newTemp = newHead;

        while (oldTemp != NULL) {
            newTemp->random = m[oldTemp->random];

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        return newHead;
    }
};
