/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *newHead = new ListNode(0);
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *curr = newHead;
        int carry = 0;
        while(p != NULL || q != NULL){
            int sum = 0, x = 0, y = 0;
            if(p){
                x = p->val;
                p = p->next;
            }
            if(q){
                y = q->val;
                q = q->next;
            }
            sum = x + y + carry;
            carry = sum/10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        } 
        if(carry) {
            curr->next = new ListNode(carry);
        }
        return newHead->next;
    }
};
