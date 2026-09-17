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
        if(head==NULL)return NULL;
        ListNode* temp=head;
        int len=0;
        while(temp){
            temp=temp->next;
            len++;
        }
       int rem=len-n;
       if(rem==0)return head->next;
       int cnt=1;
       temp=head;
       while(temp){
        if(cnt==rem){
            temp->next=temp->next->next;
            return head;
        }
        temp=temp->next;
        cnt++;
       }
return head;

    }
};