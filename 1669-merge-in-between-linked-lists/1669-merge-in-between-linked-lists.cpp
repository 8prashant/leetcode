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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr1=list1;
        ListNode* curr2=list1;
        for(int i=0;i<a-1 && curr1!=NULL;i++){
            curr1=curr1->next;
            curr2=curr2->next;
        }
        for(int i=0;i<b-(a-1)+1 && curr2!=NULL;i++){
            curr2=curr2->next;
        }
        ListNode* tail=list2;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        curr1->next=list2;
        tail->next=curr2;
        return list1;
    }
};