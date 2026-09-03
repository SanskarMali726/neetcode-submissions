class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode* prev = NULL;
        int carry = 0;

        while (l1 != NULL || l2 != NULL) {
            int val1 = (l1 != NULL) ? l1->val : 0;
            int val2 = (l2 != NULL) ? l2->val : 0;
            int sum = val1 + val2 + carry;

            int reminder = sum % 10;
            carry = sum / 10;

            if (l1 != NULL) {
                l1->val = reminder;
                prev = l1;
                l1 = l1->next;
            } else {
                prev->next = new ListNode(reminder);
                prev = prev->next;
            }

            if (l2 != NULL) l2 = l2->next;
        }
        if (carry > 0) prev->next = new ListNode(carry);
        return head;
    }
};
