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
        Node* curr=head;
        Node* dummy =new Node(0);
        Node* prev=dummy;
        unordered_map<Node*,Node*>mp;
        while(curr!=NULL){
            Node *n =new Node(curr->val);
            prev->next=n;
            mp[curr]=n;
            prev=n;
            curr=curr->next;
        }
        curr=head;
        while(curr!=NULL){
            if(curr->random==NULL){
                mp[curr]->random=NULL;
            }
            else{
                mp[curr]->random = mp[curr->random];
            }
            curr=curr->next;
        }
        return dummy->next;
    }
};