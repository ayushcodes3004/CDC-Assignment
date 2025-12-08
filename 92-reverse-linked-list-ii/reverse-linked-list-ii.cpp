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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp1=head;
        int pos=1;
        while(temp1 && pos<left){
            temp1=temp1->next;
            pos++;
        }
        ListNode* temp2=temp1;
        while(temp2 && pos<right){
            temp2=temp2->next;
            pos++;
        }

        stack<int>st;
        ListNode* temp=temp1;
        while(temp!=temp2){
            st.push(temp->val);
            temp=temp->next;
        }
        st.push(temp2->val);
        while(!st.empty()){
            temp1->val=st.top();
            st.pop();
            temp1=temp1->next;
        }
        return head;
    }
};