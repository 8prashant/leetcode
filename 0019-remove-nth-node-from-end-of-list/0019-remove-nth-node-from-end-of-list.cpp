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
        ListNode* prev=head;
        ListNode* slow=head;
        ListNode* fast=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(fast!=NULL){
            while(fast!=NULL){
                prev=slow;
                slow=slow->next;
                fast=fast->next;
            }
        }
        if(slow==head){
            if(slow->next==NULL){
                return  NULL;
            }
            else{
                return head->next;
            }
        }
        prev->next=slow->next;
        return head;

    }
};