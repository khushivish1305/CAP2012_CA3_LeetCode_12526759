
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*ptrA=headA;
        ListNode*ptrB=headB;
        while(ptrA!=ptrB){
            ptrA=(ptrA==nullptr)?headB:ptrA->next;
            ptrB=(ptrB==nullptr)?headA:ptrB->next;
        }
        return ptrA;
    }
};
