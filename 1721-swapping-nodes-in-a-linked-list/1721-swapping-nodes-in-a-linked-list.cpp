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
        ListNode* temp=head;
        ListNode* left;
        ListNode* curr;
        int count=0;
        while(temp!=NULL){
            count++;
            if(count==k) {
                left=temp;
                curr=left;
                break;
            }
            temp=temp->next;
        }
        temp=head;
        while(curr->next!=NULL){
            curr=curr->next;
            temp=temp->next;
        }
        swap(left->val,temp->val);
        return head;
    }
};