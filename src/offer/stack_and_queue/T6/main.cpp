#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 方法一：栈
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> result;
        stack<int> s;
        while(head) {
            s.push(head->val);
            head = head->next;
        }
        while(!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }
        return result;
    }
};

// 方法二：递归
/*class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        if(!head)
            return {};
        vector<int> a = reversePrint(head->next);
        a.push_back(head->val);
        return a;
    }
};*/

// 方法三：就地逆序数组（向量）
/*
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> result;
        while (head) {
            result.push_back(head->val);
            head = head->next;
        }
        int len = result.size();
        for (int i = 0; i < len / 2; i++) {
            swap(result[i], result[len-i-1]);
        }
        return result;
    }
};
*/

// 方法四：反转链表（先反转链表，再遍历，这样就不需要额外的栈空间开销）
// 【没想明白】
/*class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> result;
        // 空链表
        if (head == nullptr) return result;
        // 反转链表
        ListNode *curr = head->next;
        ListNode *temp;
        head->next = nullptr;
        while(curr) {
            temp = curr->next;
            curr->next = head;
            head = curr;
            curr = temp;
        }
        // 取出链表中的值
        while(head) {
            result.push_back(head->val);
            head = head->next;
        }
        return result;
    }
};*/
