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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        ListNode* slow = head;
        ListNode* fast = head;
        // here middle of list find
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        ListNode* temp ;
        slow->next = nullptr;
        while(curr!=NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr=temp;
        }
        // now prev is the head of the reversed L.L. of the second half 
        ListNode* second = prev;
        ListNode* first = head;
        while(second!=nullptr){
            ListNode* temp1= first->next;
            ListNode* temp2= second->next;

            first->next=second;
            second->next=temp1;

            first = temp1;
            second = temp2; 

        }
    }
};