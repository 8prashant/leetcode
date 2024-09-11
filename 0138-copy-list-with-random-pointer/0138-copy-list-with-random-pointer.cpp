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
            return NULL;
        }
        unordered_map<Node*,Node*>m;
        m[NULL]=NULL;
        Node* curr=head;
        Node* h2=NULL;
        Node* t2=NULL;
        while(curr!=NULL){
            if(m.find(curr)!=m.end()){
                t2->next=m[curr];
                t2=m[curr];
            }
            else{
                Node* newnode=new Node{curr->val,NULL};
                m[curr]=newnode;
                if(h2==NULL){
                    h2=newnode;
                    t2=newnode;
                }
                else{
                    t2->next=newnode;
                    t2=newnode;
                }
            }
            if(m.find(curr->random)!=m.end()){
                t2->random=m[curr->random];
            }
            else{
                Node* rnode=new Node{curr->random->val,NULL};
                t2->random=rnode;
                m[curr->random]=rnode;
            }
            curr=curr->next;
        }
        return h2;
    }
};