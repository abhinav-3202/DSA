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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        ListNode* prev = &dummy;
        while(head!=NULL){
            if(head->next!=NULL &&      head->val==head->next->val){
            while(head->next!=NULL &&   head->val==head->next->val){
                head=head->next;
            }
                head=head->next;
                prev->next = head;
            }
            // else if(head->next==NULL){
            //     prev->next=head;
            //     head=head->next;
            // } // i was missing this prev->next=head;
            //which solves the issue no need for that else if block it was wrong anyways
            else{
                prev->next=head;
                prev=head;
                head=head->next;
            }
        }
        return dummy.next;
    }
};