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

    //not using a string , rather just adding the values in the decimal format 
public:
    int getDecimalValue(ListNode* head) {
        if(head==NULL)return 0;
        if(head->next==NULL)return head->val;
        int res=0;
        ListNode* current=head;
        while(current != nullptr){ // Iterate through the entire linked list
            res=(res*2)+current->val;
            current = current->next;
        }
        return res;
         
    }
};