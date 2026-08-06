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
          if (head == nullptr)
            return nullptr;

        stack<Node*> st;
        Node* curr = head;

        while (curr != nullptr) {

            // Agar child exist karta hai
            if (curr->child != nullptr) {

                // Current ke next ko stack me save karo
                if (curr->next != nullptr) {
                    st.push(curr->next);
                }

                // Child ko next bana do
                curr->next = curr->child;
                curr->child->prev = curr;

                // Child pointer ko null kar do
                curr->child = nullptr;
            }

            // Agar current ka next nahi hai aur stack me node bachi hai
            if (curr->next == nullptr && !st.empty()) {

                Node* nextNode = st.top();
                st.pop();

                curr->next = nextNode;
                nextNode->prev = curr;
            }

            // Next node par move karo
            curr = curr->next;
        }

        return head;
    }
};