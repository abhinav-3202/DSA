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
    ListNode* mergeSort(ListNode* one,ListNode* two){
        ListNode dummy(0);
        ListNode* temp =&dummy;
        while(one!=NULL && two!=NULL){
            if(one->val>=two->val){
                temp->next=two;
                two=two->next;
            }
            else{
                temp->next=one;
                one=one->next;
            }
            temp=temp->next;
        }
        if(one!=NULL) temp->next=one;
        else temp->next=two;
        return dummy.next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=nullptr;
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL; //unlink kar diya middle ke phle wla and middle ke baad se 
        ListNode* left=sortList(head); //breaking until single node
        ListNode* right=sortList(slow);
        return mergeSort(left,right); // combining 
    }
};