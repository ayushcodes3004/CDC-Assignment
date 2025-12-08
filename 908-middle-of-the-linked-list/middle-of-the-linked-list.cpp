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
    ListNode* middleNode(ListNode* head) {
        // int cnt=1;
        // ListNode* temp=head;
        // int ind=-1;
        // while(temp->next!=NULL){
        //     cnt++;
        //     temp=temp->next;
        // }
        // ind=(cnt/2);
        // for(int i=1;i<=ind;i++)
        //     head=head->next;
        // return head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;

    }
};