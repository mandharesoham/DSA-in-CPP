/*
Problem: 430. Flatten a Multilevel Doubly Linked List
Platform: LeetCode
Difficulty: Medium

Tags:
- Linked List
- Depth-First Search (DFS)
- Recursion

Time Complexity: O(n)
Space Complexity: O(n)   // Due to recursion stack

Approach:
Traverse the multilevel doubly linked list recursively.
Whenever a node has a child:
1. Save the current node's next pointer.
2. Recursively flatten the child list.
3. Connect the flattened child list after the current node.
4. Set the child's prev pointer and remove the child link.
5. Traverse to the tail of the flattened child list.
6. Attach the original next node to the tail.
Continue until all nodes are flattened into a single-level doubly linked list.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        Node* curr = head;
        while (curr != NULL) {
            if(curr->child != NULL) {
            Node* next = curr->next;
            // flatten chid nodes
            curr->next = flatten(curr->child);

            curr->next->prev = curr;
            curr->child = NULL;

            // find tail
            while(curr->next != NULL) {
                curr = curr->next;
            }

            // attach tail with next  ptr
            if(next!=NULL) {
            curr->next=next;
            next->prev = curr;
            }
        }
        curr = curr->next;
        }
        return head;
    }
};
