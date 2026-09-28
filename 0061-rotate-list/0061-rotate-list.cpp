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
        if(head==NULL || head->next==NULL) return head;
        
        int n=1;
        ListNode* tail = head;

        while(tail->next != NULL){
            tail = tail->next;
            n++;
        }

        k = k%n;
        if(k==0) return head;

        tail->next=head;

        int steps = n-k;
        ListNode* newTail = head;
        for(int i=1; i<steps; i++) newTail=newTail->next;

        ListNode* newhead = newTail->next;

        newTail->next=NULL;

        return newhead;

    }
};