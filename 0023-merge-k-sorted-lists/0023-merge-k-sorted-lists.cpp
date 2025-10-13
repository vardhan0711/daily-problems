//overall TC->O(N * log k) and SC->O(N)
class Solution {
public:
    //this function will take care of the merginf of two lists at a time
    ListNode* mergeTwoList(ListNode* l1,ListNode* l2){
        if(!l1)return l2;
        if(!l2)return l1;
        if(l1->val<=l2->val){//if l1 is smaller then merge the rest of l1 with l2
            l1->next=mergeTwoList(l1->next,l2);
            return l1;
        }else{
            l2->next=mergeTwoList(l1,l2->next);
            return l2;
        }
    }
    //this will divide the list into two parts and then send it for merging to the merger function
    //TC->O(N * log k) and SC->O(N)
    ListNode* divideAndMerge(int start,int end,vector<ListNode*>& lists){
        if(start>end)return NULL;
        if(start==end)return lists[start];
        int mid=(start+end)/2;
        ListNode* l1=divideAndMerge(start,mid,lists);
        ListNode* l2=divideAndMerge(mid+1,end,lists);
        return mergeTwoList(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0)return NULL;
        return divideAndMerge(0,n-1,lists);
    }
};