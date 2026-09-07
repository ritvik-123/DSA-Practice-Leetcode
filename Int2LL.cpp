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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int ctr = 0;
        ListNode* nodeA = headA;
        ListNode* nodeB = headB;
        ListNode* inter = nullptr;
        bool switcha = false;
        bool switchb = false;
        while(nodeA != nullptr && nodeB != nullptr && inter==nullptr)
        {
            if(nodeA == nodeB)
            {
                inter = nodeA;
                return inter;
            }
            else if(nodeA->next == nullptr && !switcha)
            {
                nodeA = headB;
                switcha = true;
                nodeB = nodeB->next;
            }
            else if(nodeB->next == nullptr && !switchb)
            {
                nodeB = headA;
                switchb = true;
                nodeA = nodeA->next;
            }
            else
            {
                nodeA = nodeA->next;
                nodeB = nodeB->next;
            }
        }
        return inter;
    }
};