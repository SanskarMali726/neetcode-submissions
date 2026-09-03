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
    ListNode* reverseList(ListNode* head) {
        // if(head == NULL) return NULL;
        // if(head->next == NULL) return head;
        // ListNode* current = head->next;
        // ListNode* prv = head;
        // ListNode* forw = current->next;
        // prv->next = NULL;
        // while(current->next != NULL){
        //     current->next = prv;
        //     prv = current;
        //     current = forw;
        //     forw = forw->next;
        // }
        // current->next = prv;
        // delete forw;

        // return current;
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
};
