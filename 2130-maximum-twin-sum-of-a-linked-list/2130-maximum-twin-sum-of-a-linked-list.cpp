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
    int pairSum(ListNode* head) {
        vector<int>first;
        vector<int>second;
        ListNode* slow =head;
        ListNode* fast =head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *curr=head;
        while(curr!=slow){
            first.push_back(curr->val);
            curr=curr->next;    
        }
        
        while(curr!=NULL){
            second.push_back(curr->val);
            curr=curr->next;
        }

        reverse(second.begin(),second.end());
        
        int maxi=0;
        for(int i=first.size()-1; i>=0;i--){
            int sum=first[i]+second[i];
            maxi=max(sum,maxi);
        }
        return maxi;
    }
};