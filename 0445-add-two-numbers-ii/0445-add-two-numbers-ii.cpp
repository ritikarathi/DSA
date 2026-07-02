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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>s1;
        stack<int>s2;
        ListNode* curr =l1;
        while(curr){
            s1.push(curr->val);
            curr=curr->next;
        }
        curr=l2;
        while(curr){
            s2.push(curr->val);
            curr=curr->next;
        }
        ListNode* n=new ListNode(0);
        int sum=0;
        while(!s1.empty() || !s2.empty()){
           if(!s1.empty()){
            sum+=s1.top();
            s1.pop();
           }
           if(!s2.empty()){
            sum+=s2.top();
            s2.pop();
           }
           n->val=sum%10;
           ListNode *head = new ListNode(sum/10);
           head->next=n;
           n=head;
           sum/=10;
        }
        return n->val==0 ?n->next :n;
    }
};