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
    void reorderList(ListNode* head) {
        vector<int> ans;
        vector<int> result;
        ListNode* temp =head;
        while(temp != NULL){
            ans.push_back(temp->val);
            temp = temp->next;
        }
        
        int i=0;
        int j=ans.size()-1;
        while(i<=j){
            if(i==j){
                result.push_back(ans[i]);
                break;
            }
            result.push_back(ans[i]);
            result.push_back(ans[j]);
            i++;
            j--;
        }
        temp = head;
        for (int k = 0; k < result.size(); k++) {
            temp->val = result[k];
            temp = temp->next;
        }
    }
};
