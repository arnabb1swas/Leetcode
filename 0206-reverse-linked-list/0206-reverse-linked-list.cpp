class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* current, *prevNode = NULL;
        
        while (head) {
            current = head->next;
            head->next = prevNode;
            prevNode = head;
            head = current;
        }
        
        return prevNode;
    }
};