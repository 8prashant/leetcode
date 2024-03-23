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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return;
        }
        stack<int> s;
        ListNode* curr=head;
        int size=0;
        while(curr!=NULL){
            size++;
            curr=curr->next;
        }
        int m= size%2!=0 ? (size/2)+1:size/2;
        cout<<m<<endl;
        curr=head;
        ListNode* nhead=NULL;
        ListNode* ntail=NULL;
        for(int i=0;i<m;i++){
            if (curr == nullptr) {
                return; // handle case where list is shorter than expected
            }
            ListNode* newnode= new ListNode{curr->val,NULL};
            if(nhead==NULL){
                nhead=newnode;
                ntail=newnode;
            }
            else{
                ntail->next=newnode;
                ntail=newnode;
            }
            curr=curr->next;
        }/*
        curr=nhead;
        while(curr!=NULL){
            cout<<"1= "<<curr->val<<" ";
            curr=curr->next;
        }
        cout<<endl;
        curr=nhead;*/

        for(int j=m;j<size;j++){
            if (curr == nullptr) {
                return; // handle case where list is shorter than expected
            }
            s.push(curr->val);
            curr=curr->next;
        }
        cout<<"s="<<s.size()<<" "<<"t="<<s.top()<<endl;
        curr=nhead;
        while(s.size()!=0){
            ListNode* newnode= new ListNode{s.top(),NULL};
            newnode->next=curr->next;
            curr->next=newnode;
            curr=newnode->next;
            s.pop();
        }
        curr=nhead;
        while(curr!=NULL){
            cout<<"n="<<curr->val<<" ";
            curr=curr->next;
        }
        cout<<endl;
        curr=head;
        ListNode* curr2=NULL;
        curr2=nhead;
        while(curr!=NULL && curr2!=NULL){
            curr->val=curr2->val;
            curr=curr->next;
            curr2=curr2->next;
        }
        return;
        
    }
};