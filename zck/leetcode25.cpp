/*给你这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

/*放进vector容器，k个为一组进行翻转*/
ListNode* reverseKGroup(ListNode* head, int k) {
    vector<int> nums;
    while(head != NULL){
        nums.push_back(head->val);
        head = head->next;
    }
    int n = nums.size() / k;
    for(int i = 0; i < n; i++){
        reverse(nums.begin() + i * k, nums.begin() + (i + 1) * k);
    }
    ListNode *res = new ListNode(nums[0]);
    ListNode *tail = res;
    for(int i = 1; i < nums.size(); i++){
        ListNode *temp = new ListNode(nums[i]);
        tail->next = temp;
        tail = tail->next;
    }
    return res;
}


int main(){
    ListNode *n1= new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    ListNode *head = n1;
    ListNode *res = reverseKGroup(head, 3);
    while (res != NULL){
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}



