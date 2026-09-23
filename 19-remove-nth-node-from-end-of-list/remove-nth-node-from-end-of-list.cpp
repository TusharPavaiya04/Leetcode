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
    private:
    int LengthOfLL(ListNode* head){
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL)return NULL;
        ListNode* temp=head;
        int k=LengthOfLL(head)-n;
        if(k==0)return head->next;
        int cnt=1;
        while(k!=cnt){
            if(k==cnt){
             temp->next=temp->next->next;
             return head;
            }
            cnt++;
            temp=temp->next;
        }
        if(k==cnt){
             temp->next=temp->next->next;
             return head;
        }
        return head;

    }
};