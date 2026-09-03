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
      //check if k nodes exist
      ListNode* temp = head;
      int count = 0;
      while(count < k){
        if(!temp){
            return head;
        }
        temp = temp->next;
        count++;
      }
      //recursively call the rest linked list
      ListNode* nextNode = reverseKGroup(temp,k);
      //reverse the current group
      temp = head;
      count = 0;
      while(count < k){
        ListNode* next = temp->next;
        temp->next = nextNode;

        nextNode = temp;
        temp = next;
        count++;
      }
      return nextNode;
    }
};