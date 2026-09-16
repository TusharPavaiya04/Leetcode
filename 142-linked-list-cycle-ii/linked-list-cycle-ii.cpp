/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL&&fast!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==NULL||fast->next==NULL)return NULL;
            if(slow==fast){
                slow=head;
                while(1){
                    if(slow==fast)return slow;
                    slow=slow->next;
                    fast=fast->next;
                }
            }
        }
return NULL;
    }
};