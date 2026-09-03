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
    ListNode* MergeTwoList(ListNode* list1,ListNode* list2){
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        while(l1 && l2){
            if(l1->val <= l2->val){
                temp->next = l1;
                temp = temp->next;
                l1 = l1->next;
            }
            else{
                temp->next = l2;
                temp = temp->next;
                l2 = l2->next;
            }
        }
        if(l1){
            temp->next = l1;
        }
        else{
            temp->next = l2;
        }
        return   dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) return NULL;
        if(n==1) return lists[0];
        ListNode* list1 = lists[0];
        ListNode* head;
        for(int i = 1;i < n; i++){
            ListNode* list2 = lists[i];
            head = MergeTwoList(list1,list2);
            list1 = head;
        }
        return list1;
    }
};
