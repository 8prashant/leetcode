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
    int size(ListNode* head){
        ListNode* curr=head;
        int sum=0;
        while(curr!=NULL){
            sum++;
            curr=curr->next;
        }
        return sum;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int s=size(head);
        vector<ListNode*> v;
        if(k>s){
            ListNode* curr=head;
            for(int i=0;i<s;i++){
                ListNode* newnode= new ListNode{curr->val,NULL};
                curr=curr->next;
                v.push_back(newnode);
            }
            for(int i=0;i<k-s;i++){
                //ListNode* newnode= new ListNode(nullptr);
                //v.push_back(newnode);
                v.push_back(NULL);
            }
        }
        else{
            int a,b;
            a=s%k;      /*BIG GROUP*/
            b=k-s%k;
            int l=s/k;      /*SMALL GROUP LENGTH*/
            ListNode* curr=head;
            for(int i=0;i<a;i++){
                ListNode* head1=NULL;
                ListNode* tail=NULL;
                for(int j=0;j<l+1;j++){
                    ListNode* newnode= new ListNode{curr->val,NULL};
                    if(head1==NULL){
                        head1=newnode;
                        tail=newnode;
                    }
                    else{
                        tail->next=newnode;
                        tail=newnode;
                    }
                    curr=curr->next;
                }
                v.push_back(head1);
            }
            for(int k=0;k<b;k++){
                ListNode* head2=NULL;
                ListNode* tail2=NULL;
                for(int i=0;i<l;i++){
                    ListNode* newnode =new ListNode{curr->val,NULL};
                    if(head2==NULL){
                        head2=newnode;
                        tail2=newnode;
                    }
                    else{
                        tail2->next=newnode;
                        tail2=newnode;
                    }
                    curr=curr->next;
                }
                v.push_back(head2);
            }


        }
        return v;
        
    }
};