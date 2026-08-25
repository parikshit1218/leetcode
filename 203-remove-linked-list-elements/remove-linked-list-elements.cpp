class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Remove matching nodes from the beginning
        while (head != nullptr && head->val == val) {
            head = head->next;
        }

        // Remove matching nodes from the middle/end
        ListNode* temp = head;

        while (temp != nullptr && temp->next != nullptr) {
            if (temp->next->val == val) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }

        return head;
    }
};