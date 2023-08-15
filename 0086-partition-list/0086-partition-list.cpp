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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* l1=head;
        if(head->val<x){
            while(l1->next!=NULL && l1->next->val<x){
                l1=l1->next;
            }
            if(l1==NULL){
                return head;
            }
        }
        cout<<"l="<<l1->val<<endl;
        ListNode* curr=l1->next;
        ListNode* prev=l1;
        while(curr!=NULL){
            ListNode* frw=curr->next;
            if(curr->val<x){
                prev->next=curr->next;
                if(l1==head && l1->val>=x){
                    curr->next=head;
                    head=curr;
                    l1=head;
                    curr=frw;
                }
                else{
                    curr->next=l1->next;
                    l1->next=curr;
                    l1=curr;
                    curr=frw;
                }
            }
            else{
                prev=curr;
                curr=frw;
            }
        }
        return head;

    }
};