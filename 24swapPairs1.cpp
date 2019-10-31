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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* first = head;
        ListNode* second = head->next;
        head = second;
        first->next = swapPairs(second->next);
        second->next = first;
        return head;
    }
};
