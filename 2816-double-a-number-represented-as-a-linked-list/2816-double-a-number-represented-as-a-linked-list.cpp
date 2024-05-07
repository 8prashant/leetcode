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
    ListNode* doubleIt(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* curr=head;
        vector<int> v;
        while(curr!=NULL){
            v.push_back(curr->val);
            curr=curr->next;
        }
        ListNode* head2=NULL;
        int c=0;
        while(v.size()!=0){
            int a=v[v.size()-1]*2+c;
            v.pop_back();
            int b=a%10;
            c=a/10;
            ListNode* newnode= new ListNode{b,head2};
            head2=newnode;
        }
        if(c!=0){
            ListNode* newnode= new ListNode{c,head2};
            head2=newnode; 
        }
        return head2;
    }
};