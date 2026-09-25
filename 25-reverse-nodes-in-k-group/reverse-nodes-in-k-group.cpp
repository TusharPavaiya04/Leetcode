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
    ListNode* reverseLL(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp){
            ListNode* nextNode=temp->next;
               temp->next=prev;
               prev=temp;
               temp=nextNode;
        }
        return prev;
    }

    ListNode* findKthNode(ListNode* temp,int k){
             k-=1;
             while(k>0&&temp!=NULL){
                k--;
                temp=temp->next;
             }
             return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==0||head==NULL)return head;
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp){
            ListNode* kthNode=findKthNode(temp,k);
            if(kthNode==NULL){
                if(prev){
                    prev->next=temp;
                    break;
                }
            }
            ListNode* nextNode=kthNode->next;

            
           kthNode->next=NULL;
           reverseLL(temp);
           if(temp==head){
            head=kthNode;
           }else{
            prev->next=kthNode;
           }
           prev=temp;
           temp=nextNode;
        }
       return head;
    }
};