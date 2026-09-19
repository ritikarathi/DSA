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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *start=head;
        ListNode *dummy= new ListNode(0);
        dummy->next=head;
        ListNode *gprev=dummy;
        ListNode *curr=head;
        ListNode *prev=NULL;
        int size=0;
        while(curr!=NULL){
            curr=curr->next;
            size++;
        }
        curr=head;
        int count=size;
        while(count>=k){
            start=gprev->next;
            curr=start;
            prev=NULL;
            
            for(int i=0;i<k;i++){
                ListNode *temp= curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }
            gprev->next=prev;
            start->next=curr;
            gprev=start;
            count-=k;
        }
        return dummy->next;;
    }
};