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
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        ListNode* curr=NULL;
            while(fast!=NULL && fast->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
            }
            if(fast==NULL){
                curr=slow;
            }
            else{
                curr=slow->next;
            }
            while(curr!=NULL){
                ListNode* few=curr->next;
                curr->next=prev;
                prev=curr;
                curr=few;
            }
            ListNode* curr1=head;
            ListNode* curr2=prev;
            while(curr2!=NULL){
                if(curr1->val!=curr2->val){
                    return false;
                }
                else{
                    curr1=curr1->next;
                    curr2=curr2->next;
                }
            }
            return true;

        

        
    }
};