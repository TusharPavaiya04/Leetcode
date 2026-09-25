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
    int lenOfLL(ListNode* head){
        ListNode* temp=head;
      int cnt=0;
      while(temp){
        cnt++;
        temp=temp->next;
      }
      return cnt;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL)return head;
        k=k%lenOfLL(head);
        ListNode* temp=head;
        int cnt=lenOfLL(head)-k;
        while(temp){
          
            if(cnt==1){
                ListNode* nextNode=temp->next;
                if(nextNode){
                    ListNode* newHead=nextNode;
                    ListNode* mover=newHead;
                    while(mover->next!=NULL){
                        mover=mover->next;
                    }
                    temp->next=NULL;
                    mover->next=head;
                    return newHead;
                }
            }
              cnt--;
            temp=temp->next;

        }
        return head;
    }
};