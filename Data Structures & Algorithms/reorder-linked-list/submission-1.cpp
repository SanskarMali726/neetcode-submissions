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

  // vector<int> ans;
        // vector<int> result;
        // ListNode* temp =head;
        // while(temp != NULL){
        //     ans.push_back(temp->val);
        //     temp = temp->next;
        // }
        
        // int i=0;
        // int j=ans.size()-1;
        // while(i<=j){
        //     if(i==j){
        //         result.push_back(ans[i]);
        //         break;
        //     }
        //     result.push_back(ans[i]);
        //     result.push_back(ans[j]);
        //     i++;
        //     j--;
        // }
        //     temp = head;
        // for (int k = 0; k < result.size(); k++) {
        //     temp->val = result[k];
        //     temp = temp->next;
        // }

class Solution {
public:
    ListNode* reverseList(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
    void reorderList(ListNode* head) {
       ListNode* slow = head;
       ListNode* fast = head;
       while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
       }
        ListNode* tail = reverseList(slow->next);
        slow->next = NULL; 

        ListNode* temp = head;
        ListNode* temp2 = tail; 
        while(temp2 != NULL){
            ListNode* next1 = temp->next;
            ListNode* next2 = temp2->next;

            temp->next = temp2;
            temp2->next = next1;
            temp = next1;
            temp2= next2;
        }

    }   
};
