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
    int getDecimalValue(ListNode* head) {
        if(head==NULL)return 0;
        if(head->next==NULL)return head->val;
        string st ="";
        ListNode* current=head;
        while(current != nullptr){ // Iterate through the entire linked list
            st += std::to_string(current->val); // Convert int to string and append
            current = current->next;
        }
        return std::stoi(st, nullptr, 2); 
    }
};