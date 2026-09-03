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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        int index = 1;
        int N =0;
        ListNode* temp = head;
        while(temp != NULL){
            N+=1;
            temp = temp->next;
        }

        if (N == n) {
            ListNode* deln = head;
            head = head->next;
            deln->next = NULL;
            return head;
        }

        temp = head->next;
        ListNode* prv = head;
        while(index < N-n){
            temp = temp->next;
            prv =prv->next;
            index+=1;
        }

        ListNode* deln = temp;
        temp = temp->next;
        prv->next = temp;
        deln->next = NULL; 
        return head;
    }
};
