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

    ListNode* findMiddle(ListNode* head){
        ListNode* fast = head->next;
        ListNode* slow = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode *dummy = new ListNode(0);
        ListNode *pointer = dummy;

        while (head1 != NULL && head2 != NULL) {
            if (head1->val < head2->val) {
                pointer->next = head1;
                head1 = head1->next;
            } else {
                pointer->next = head2;
                head2 = head2->next;
            }
            pointer = pointer->next;
        }

        if (head1 != NULL) {
            pointer->next = head1;
        } else {
            pointer->next = head2;
        }

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* mid = findMiddle(head);
        ListNode* right = sortList(mid->next);
        mid->next = NULL;
        ListNode* left = sortList(head);
        return merge(left, right);
    }
};