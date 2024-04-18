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
    bool hasCycle(ListNode *head) {
        ListNode * ptr = head;

        while(ptr && ptr->next )    // if anyone reaches end --> Terminate
        {
            head = head->next;      // slow ptr
            ptr = ptr->next->next;  // fast ptr
            if(head == ptr) return true;
        }
        return false;
    }
};