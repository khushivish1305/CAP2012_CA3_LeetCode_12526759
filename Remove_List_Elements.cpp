
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode*dummy=new ListNode(0,head);
        ListNode*curr=dummy;
        while(curr->next!=nullptr){
            if(curr->next->val == val){
                ListNode*temp=curr->next;
                curr->next=curr->next->next;
                delete temp;
            }
            else{
                curr=curr->next;
            }
        }
        ListNode*newHead=dummy->next;
        delete dummy;
        return newHead;
    }
};
