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
        stack<ListNode*>st;
        int count=0;
        ListNode* temp = head;
        while(temp!=NULL){
            count++;
            st.push(temp);
            temp=temp->next;
        }
        int i=count/2 ;
        temp=head;
        ListNode* front=temp->next;
        int j=0;
        while(j < i){
            temp->next=st.top();
            st.pop();
            temp->next->next=front;
            temp=front;
            front=front->next;
            j++;
        }
        if(count%2==0) front->next=NULL;
        else if(count%2!=0) temp->next=NULL;
        return ;
    }
};