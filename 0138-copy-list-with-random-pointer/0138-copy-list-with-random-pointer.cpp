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
        // if (head == NULL) {
        //     return NULL;
        // }

        // unordered_map<Node*, Node*> m;

        // Node* newHead = new Node(head->val);
        // Node* oldTemp = head->next;
        // Node* newTemp = newHead;
        // m[head] = newHead;

        // while (oldTemp != NULL) {
        //     Node* copyNode = new Node(oldTemp->val);
        //     m[oldTemp] = copyNode;
        //     newTemp->next = copyNode;

        //     oldTemp = oldTemp->next;
        //     newTemp = newTemp->next;
        // }

        // oldTemp = head;
        // newTemp = newHead;

        // while (oldTemp != NULL) {
        //     newTemp->random =
        //         m[oldTemp->random]; // oldtemp ka random pointer point to be
        //                             // newTemp ka random ptr
        //     oldTemp = oldTemp->next;
        //     newTemp = newTemp->next;
        // }
        // return newHead;

          if(head == NULL)
            return NULL;

        Node* curr = head;

        // Step 1: Insert copied nodes
        while(curr != NULL)
        {
            Node* copy = new Node(curr->val);

            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }

        // Step 2: Set random pointers
        curr = head;

        while(curr != NULL)
        {
            if(curr->random != NULL)
            {
                curr->next->random = curr->random->next;
            }

            curr = curr->next->next;
        }

        // Step 3: Separate the lists
        Node* dummy = new Node(-1);
        Node* copyTail = dummy;

        curr = head;

        while(curr != NULL)
        {
            Node* copy = curr->next;

            curr->next = copy->next;

            copyTail->next = copy;
            copyTail = copy;

            curr = curr->next;
        }

        return dummy->next;
    }
};