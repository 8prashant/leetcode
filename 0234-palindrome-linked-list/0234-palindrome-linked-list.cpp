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
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){
            return true;
        }
        ListNode* prev=NULL;
        ListNode* slow=head;
        ListNode* fwd=head->next;
        ListNode* fast=head;
        while(fast!=NULL and fast->next!=NULL){
            fast=fast->next->next;
            slow->next=prev;
            prev=slow;
            slow=fwd;
            fwd=fwd->next;
        }
        if(fast!=NULL){
            slow=slow->next;
        }
        while(prev!=NULL && slow!=NULL){
            if(prev->val!=slow->val){
                return false;
            }
            prev=prev->next;
            slow=slow->next;
        }
        if(prev==NULL && slow!=NULL || prev!=NULL && slow==NULL){
            return false;
        }
        return true;
    }
};