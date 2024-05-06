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

    void print(ListNode* curr){
        cout<<"s = ";
        while(curr!=NULL){
            cout<<curr->val<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }

    ListNode* rev(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr!=NULL){
            ListNode* frw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=frw;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head=rev(head);
        print(head);
        int le=head->val;
        ListNode* prev=head;
        ListNode* curr=head->next;
        while(curr!=NULL){
            ListNode* frw=curr->next;
            if(curr->val<le){
                prev->next=frw;
                curr=frw;
            }
            else{
                le=curr->val;
                prev=curr;
                curr=curr->next;
            }
        }
        head=rev(head);
        return head;
    }
};