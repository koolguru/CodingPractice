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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* nodeBeforeRemoval = NULL;
        ListNode* start = head;
        if(head->next == NULL)
        {
            return NULL;
        }
        for(int i = 0; i < n-1; i++)
        {
            head = head->next;
        }
        while(head != NULL)
        {
            if(head->next == NULL)
            {
                if(nodeBeforeRemoval == NULL)
                {
                    start = start->next;
                    return start;
                }
                else
                {
                    nodeBeforeRemoval->next = nodeBeforeRemoval->next->next;
                }
            }
            if(nodeBeforeRemoval == NULL)
            {
                nodeBeforeRemoval = start;
            }
            else
            {
                nodeBeforeRemoval = nodeBeforeRemoval->next;
            }
            head = head->next;
        }

        return start;
    }
};
