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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;

        ListNode* curr = head;

        while(curr != NULL && curr->next != NULL) {

            ListNode* temp = head;

            while(temp->next != NULL && temp->next->next != NULL) {
                temp = temp->next;
            }
            ListNode* last = temp->next;
            temp->next = NULL;
            last->next = curr->next;
            curr->next = last;
            curr = last->next;
        }
    }
};