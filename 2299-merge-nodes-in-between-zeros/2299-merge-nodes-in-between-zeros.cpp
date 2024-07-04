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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr=head->next;
        ListNode* prev=head->next;
        head=head->next;
        while(curr!=NULL){
            // cout<<prev->val<<" "<<curr->val<<endl;
            if(curr==prev){
                curr=curr->next;
            }
            else if(curr->val==0){
                prev->next=curr->next;
                curr=curr->next;
                prev=curr;
            }
            else{
                prev->val+=curr->val;
                curr=curr->next;
            }
        }
        return head;
    }
};