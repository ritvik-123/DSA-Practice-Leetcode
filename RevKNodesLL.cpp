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
    ListNode* reverseKGroup(ListNode* head, int k) {

        // Points to the first node of the group
        // that we are currently trying to reverse.
        ListNode* groupStart = head;

        // After reversing a group, we need its old first node
        // to connect to the NEXT reversed group.
        //
        // Example:
        // 1 -> 2 becomes 2 -> 1
        //                       ^
        //                       previousGroupTail
        ListNode* previousGroupTail = nullptr;

        bool firstGroup = true;

        while (groupStart != nullptr) {

            /*
             * STEP 1: Check whether we actually have k nodes left.
             *
             * Example, k = 3:
             *
             * groupStart
             *    ↓
             *    1 -> 2 -> 3 -> 4 -> 5
             *
             * Move 'afterGroup' k times:
             *
             *                   afterGroup
             *                       ↓
             *    1 -> 2 -> 3 -> 4 -> 5
             *
             * So:
             * groupStart = first node we're going to reverse
             * afterGroup = first node AFTER the group
             */
            ListNode* afterGroup = groupStart;

            for (int i = 0; i < k; i++) {
                // Fewer than k nodes remain.
                // Problem says leave these nodes unchanged.
                if (afterGroup == nullptr) {
                    return head;
                }

                afterGroup = afterGroup->next;
            }


            /*
             * STEP 2: Save the old first node.
             *
             * Before:
             *
             * groupTail
             *    ↓
             *    1 -> 2 -> 3
             *
             * After reversal:
             *
             *    3 -> 2 -> 1
             *              ↑
             *          groupTail
             *
             * The old HEAD becomes the new TAIL.
             */
            ListNode* groupTail = groupStart;


            /*
             * STEP 3: Reverse exactly k nodes.
             *
             * Before:
             *
             * 1 -> 2 -> 3 -> 4
             *
             * After reverseList(..., 3):
             *
             * 3 -> 2 -> 1    4
             * ↑               ↑
             * reversedHead    afterGroup
             */
            ListNode* reversedHead = reverseList(groupStart, k);


            /*
             * STEP 4: Connect the PREVIOUS group
             * to this newly reversed group.
             *
             * Suppose we already had:
             *
             * 2 -> 1
             *
             * and we just reversed:
             *
             * 3 -> 4
             *
             * into:
             *
             * 4 -> 3
             *
             * We need:
             *
             * 2 -> 1 -> 4 -> 3
             *      ↑    ↑
             *      |    reversedHead
             * previousGroupTail
             */
            if (firstGroup) {

                // The first reversed group's head becomes
                // the head of the ENTIRE linked list.
                head = reversedHead;
                firstGroup = false;
            }
            else {

                // Connect previous group's tail
                // to current group's new head.
                previousGroupTail->next = reversedHead;
            }


            /*
             * STEP 5: Connect the tail of the reversed group
             * to the untouched part of the list.
             *
             * Currently:
             *
             * 3 -> 2 -> 1    4 -> 5
             *
             * Connect:
             *
             * 3 -> 2 -> 1 -> 4 -> 5
             */
            groupTail->next = afterGroup;


            /*
             * STEP 6: Prepare for the next group.
             */

            // Current group's tail becomes the
            // "previous group tail" for next iteration.
            previousGroupTail = groupTail;

            // Move to the beginning of the next group.
            groupStart = afterGroup;
        }

        return head;
    }


    /*
     * Reverse exactly k nodes starting from 'head'.
     *
     * Example:
     *
     * 1 -> 2 -> 3 -> 4
     *
     * k = 3
     *
     * returns:
     *
     * 3 -> 2 -> 1
     *
     * NOTE:
     * Connecting 1 back to 4 is handled by reverseKGroup().
     */
    ListNode* reverseList(ListNode* head, int k) {

        ListNode* prev = nullptr;
        ListNode* current = head;

        int count = 0;

        while (count < k && current != nullptr) {

            // Save the next node BEFORE breaking the link.
            ListNode* nextNode = current->next;

            // Reverse the arrow.
            current->next = prev;

            // Move prev forward.
            prev = current;

            // Move current forward using the saved pointer.
            current = nextNode;

            count++;
        }

        // 'prev' is now the new head of this reversed group.
        return prev;
    }
};