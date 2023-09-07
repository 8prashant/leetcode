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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* before=NULL;
        ListNode* prev=NULL;
        ListNode* curr=head;
        int i=1;
        while(i!=left && curr!=NULL){
            before=curr;
            curr=curr->next;
            i++;
        }
        ListNode* temp=curr;
        while(i!=right+1 && curr!=NULL){
            cout<<"cu="<<curr->val<<" "<<"i="<<i<<endl;
            ListNode* frw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=frw;
            i++;
        }
        if(left==1){
            head=prev;
            temp->next=curr;
            return head;
        }
        else{
            before->next=prev;
            temp->next=curr; 
        } 
        return head; 
        
    }
};