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
        ListNode* front;
        for(int j =0;j<i;j++){
            ListNode* back = st.top();
            st.pop();
            // temp->next=front;
            //jab hm temp->next = front kar rhe and then jab same kp back kar rhe then phle wala reference lost ho jaa rha
            front = temp->next;
            temp->next=back;
            back->next=front;
            temp=front;
        }
        temp->next=NULL;
        return ;
    }
};