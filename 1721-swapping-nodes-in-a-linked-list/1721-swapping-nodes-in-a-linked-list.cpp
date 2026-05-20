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
    ListNode* swapNodes(ListNode* head, int k) {
        int count =0;
        ListNode* temp = head;
        int start=-1;
        int end=-1;
        while(temp!=NULL){
            count++;
            if(count==k) start=temp->val;
            temp=temp->next;
        }
        int newCount = count;
        temp=head;
        while(temp!=NULL){
            if(newCount==k) {
                end=temp->val;
                // temp->val=start;
                break;    
            }
            temp=temp->next;
            newCount--;
        }
        int i=0;
        temp=head;
        while(temp!=NULL){
            i++;
            if(i==k){
                temp->val=end;
                break;
            }
            temp=temp->next;
        }
        temp=head;
        i = count;
        while(temp!=NULL){
            if(i==k) {
                temp->val=start;
                break;
            }
            temp=temp->next;
            i--;
        }
        return head;
    }
};