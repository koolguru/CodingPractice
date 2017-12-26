// Solution for Leetcode #61 Rotating a Linked List
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
    ListNode* rotateRight(ListNode* head, int k) {
        // Security Checks
        if(head == nullptr)
        {
            return nullptr;
        }
        if(head->next == nullptr)
        {
            return head;
        }

        ListNode* end = head;
        ListNode* newHead = nullptr;
        int size = 1;

        while(end->next != nullptr)
        {
            size++;
            end = end->next;

        }

        if(size == 1)
        {
            return head;
        }

        k = k%size;

        for(int i = 0; i < size-k; i++)
        {
            newHead = head->next;
            head->next = nullptr;
            end->next = head;
            end = end->next;
            head = newHead;
        }
        return head;
    }
};
