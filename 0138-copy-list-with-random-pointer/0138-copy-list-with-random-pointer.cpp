/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return head;
        }
        Node* curr=head;
        while(curr!=NULL){
            Node* newnode = new Node(curr->val);
            newnode->next=curr->next;
            curr->next=newnode;
            curr=newnode->next;
        }

        curr=head;
        while(curr!=NULL){
            if(curr->random!=NULL){
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }
        curr=head;
        Node* currhead=curr->next;
        Node* currtail=currhead;
        while(currtail->next!=NULL){
            curr->next=currtail->next;
            curr=currtail->next;
            currtail->next=currtail->next->next;
            currtail=currtail->next;
        }
        curr->next=NULL;
        currtail->next=NULL;
        return currhead;
        
    }
};