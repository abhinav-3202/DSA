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
    void reverse(ListNode* left,ListNode* nextright){
        ListNode* prev = nextright;
        while(left!=nextright){
            ListNode* front = left->next ;
            left->next= prev;
            prev = left;
            left = front;
        }
        return;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right ) return head;
        ListNode* leftt;
        ListNode* rightt;
        ListNode* prevleft = NULL;
        ListNode* nextright = NULL;
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        dummy->next = head;
        int count=0;
        while(temp !=NULL){
            if(count==left-1){
                prevleft= temp;
            }
            else if(count==left){
                leftt= temp;
            } 
            else if(count==right){
                rightt= temp;
            }
            else if(count==right+1){
                nextright = temp;
            }
            temp = temp->next;
            count++;
        }
        reverse(leftt,nextright);
        prevleft->next = rightt;
        // leftt->next = nextright;
        return dummy->next;
    }
};