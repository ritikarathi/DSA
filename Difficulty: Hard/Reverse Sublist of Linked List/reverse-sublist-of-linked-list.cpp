/* Structure of a Linked List Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    Node* reverseBetween(int a, int b, Node* head) {
        // code here
        Node* curr=head;
        Node* tail=head;
        Node* dummy =new Node(0);
        dummy->next=head;
        Node* prev =dummy;
        int count=1;
        
        while(count<a && curr!=NULL){
            count++;
            prev=curr;
            curr=curr->next;
        }
            
        
        Node* start=curr;
        Node* p=prev;
        count =(b-a)+1;
        while(count--){
            Node*temp =curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            
        }
        p->next=prev;
        start->next=curr;
        return dummy->next;
    }
};