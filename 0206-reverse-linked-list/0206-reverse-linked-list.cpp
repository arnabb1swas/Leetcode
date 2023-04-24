class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* current;
        ListNode* prevNode = NULL;
        
        while (head) {
            current = head->next;
            head->next = prevNode;
            prevNode = head;
            head = current;
        }
        
        return prevNode;
    }
};
