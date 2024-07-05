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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>v;
        ListNode* curr=head;
        ListNode* prev=NULL;
        int sum=0;
        while(curr!=NULL){
            if(prev==NULL || curr->next==NULL){
                prev=curr;
                curr=curr->next;
                sum++;
                continue;
            }
            if((curr->val>curr->next->val && curr->val>prev->val)||(curr->val<curr->next->val && curr->val<prev->val)){
                v.push_back(sum);
            }
            prev=curr;
            curr=curr->next;
            sum++;
        }
        int mi=INT_MAX,ma=INT_MIN;
        if(v.size()==1){
            return {-1,-1};
        }
        for(int i=1;i<v.size();i++){
            mi=min(mi,(v[i]-v[i-1]));
            ma=max(ma,(v[i]-v[0]));
        }

        if(mi==INT_MAX){
            return {-1,-1};
        }
        return {mi,ma};
    }
};