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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) {
            return list2;
        }
        if(list2 == NULL) {
            return list1;
        }
        if(list1->val < list2->val) {
            list1->next =  mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            ListNode *tempNode = new ListNode(list2->val);
            
            list1->val = list1->val ^ tempNode->val;
            tempNode->val = list1->val ^ tempNode->val;
            list1->val = list1->val ^ tempNode->val;
            
            ListNode *prevNext = list1->next;
            list1->next = tempNode;
            tempNode->next = prevNext;
            list1->next = mergeTwoLists(list1->next, list2->next);
            return list1;
        }
    }
};
