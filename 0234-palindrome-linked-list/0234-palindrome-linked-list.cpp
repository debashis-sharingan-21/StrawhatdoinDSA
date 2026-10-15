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
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;
        vector<int> arr;
        while(curr!=NULL){
            int temp = curr->val;
            arr.push_back(temp);
            curr = curr->next;
        }
        int n = arr.size();
        int i = 0;
        int j = n-1;
        while(i<j){
            if(arr[i]!=arr[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};