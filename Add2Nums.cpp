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
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* l3 = new ListNode;
        ListNode* head = new ListNode;
        int carryover = 0;
        ListNode* temp = new ListNode; // for the first l3 node
        cout<<l1->val + l2->val;
        temp->val = l1->val+l2->val;
        if(temp->val <= 9)
        {
            l3 = temp;
            l2 = l2->next;
            l1 = l1->next;
            head = l3;
        }
        else
        {
            carryover = temp->val/10;
            temp->val = temp->val%10;
            l3 = temp;
            l2 = l2->next;
            l1 = l1->next;
            head = l3;
        }
        while(l1!=NULL && l2!=NULL)
        {
            ListNode* temp = new ListNode;
            temp->val = l1->val+l2->val + carryover;
            if(temp->val <= 9)
            {
                l3->next = temp;
                l3 = l3->next;
                l2 = l2->next;
                l1 = l1->next;
                carryover = 0;
            }
            else
            {
                carryover = temp->val/10;
                temp->val = temp->val%10;
                l3->next = temp;
                l3 = l3->next;
                l2 = l2->next;
                l1 = l1->next;
            }
        }
        if(l1 == NULL)
        {
            while(l2!=NULL)
            {
                if(carryover != 0)
                {
                    ListNode* temp = new ListNode;
                    temp->val = l2->val + carryover;
                    if(temp->val <= 9)
                    {
                        l3->next = temp;
                        l2 = l2->next;
                        l3 = l3->next;
                        carryover = 0;
                    }
                    else
                    {
                        carryover = temp->val/10;
                        temp->val = temp->val%10;
                        l3->next = temp;
                        l2 = l2->next;
                        l3 = l3->next;
                    }
                }
                else
                {
                    l3->next = l2;
                    l2 = l2->next;
                    l3 = l3->next;
                }
            }
        }
        if(l2 == NULL)
        {
            while(l1!=NULL)
            {
                if(carryover != 0)
                {
                    ListNode* temp = new ListNode;
                    temp->val = l1->val + carryover;
                    if(temp->val <= 9)
                    {
                        l3->next = temp;
                        l1 = l1->next;
                        l3 = l3->next;
                        carryover = 0;
                    }
                    else
                    {
                        carryover = temp->val/10;
                        temp->val = temp->val%10;
                        l3->next = temp;
                        l1 = l1->next;
                        l3 = l3->next;
                    }
                }
                else
                {
                    l3->next = l1;
                    l1 = l1->next;
                    l3 = l3->next;
                }
            }
        }
        if(carryover)
        {
            ListNode* temp = new ListNode;
            temp->val = carryover;
            l3->next = temp;
        }
        return head;
    }
};