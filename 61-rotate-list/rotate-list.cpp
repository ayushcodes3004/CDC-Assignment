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
private:
    ListNode* findNthNode(ListNode* temp, int n){
        if(temp==NULL)  return NULL;
        int pos=1;
        while(temp){
            if(pos==n)  break;
            pos++;
            temp=temp->next;
        }
        return temp;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)  return NULL;
        int len=1;
        ListNode* tail=head;
        while(tail->next){
            tail=tail->next;
            len++;
        }
        if(k%len==0)    return head;
        k=k%len;
        tail->next=head;
        ListNode* temp=findNthNode(head,len-k);
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};