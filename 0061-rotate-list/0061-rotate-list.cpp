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
    ListNode* rotateRight(ListNode* head, int k) {
        // Handle empty list or a single-node list
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Calculate the length
        int n = 0;
        ListNode* curr = head;

        while (curr != nullptr) {
            n++;
            curr = curr->next;
        }

        // Avoid unnecessary rotations
        k = k % n;

        if (k == 0) {
            return head;
        }

        // Move fast k nodes ahead
        ListNode* slow = head;
        ListNode* fast = head;

        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }

        // Find the new tail
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Rotate the list
        ListNode* newHead = slow->next;
        slow->next = nullptr;
        fast->next = head;

        return newHead;
    }
};