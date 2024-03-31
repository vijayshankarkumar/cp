#include <iostream>

struct ListNode
{
    int val;
    ListNode* next;

    ListNode(int v) : val(v), next(nullptr){}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    if(!head || k == 1) return head;
    ListNode *dummy= new ListNode(-1); 
    dummy->next= head;
    ListNode *cur= dummy, *nex, *pre= dummy;
    
    //1. get the length of linked list
    int count= 0;
    while(cur= cur->next) count++;
    
    //2. use the length to do swapping
    while(count >= k){
        cur= pre->next;
        nex= cur->next;
        for(int i= 1; i< k; i++){ //IMPORTANT: change in k groups, only needs to swap k-1 times
            cur->next= nex->next;
            nex->next= pre->next;
            pre->next= nex;
            nex= cur->next;
        }
        pre= cur;
        count -= k;
    }
    return dummy->next;
}


int main() {
    return 0;
}