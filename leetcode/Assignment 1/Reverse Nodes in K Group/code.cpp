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
    ListNode *getKthNode(ListNode *head, int k){
            ListNode *ptr = head;
            int count = 0;
            while (ptr != nullptr && count < k)
            {
                ptr = ptr->next;
                count++;
            }
            return ptr;
        }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
            ListNode *dummy = new ListNode(0, head); // dummy node to handle edge cases
            ListNode *groupPrev = dummy;

            while (true)
            {
                ListNode *kthNode = getKthNode(groupPrev, k);
                if (kthNode == nullptr)
                    break;

                ListNode *groupNext = kthNode->next;

                // reverse the group (normal reversing)
                ListNode *prev = kthNode->next;
                ListNode *curr = groupPrev->next;

                while (curr != groupNext)
                {
                    ListNode *next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                }

                // connect the group
                ListNode *groupTail = groupPrev->next;
                groupPrev->next = kthNode;
                groupPrev = groupTail;
            }
            return dummy->next;
    }
};