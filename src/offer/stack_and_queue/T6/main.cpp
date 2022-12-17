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

// ����һ��ջ
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

// ���������ݹ�
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

// ���������͵��������飨������
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

// �����ģ���ת�����ȷ�ת�����ٱ����������Ͳ���Ҫ�����ջ�ռ俪����
// ��û�����ס�
/*class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> result;
        // ������
        if (head == nullptr) return result;
        // ��ת����
        ListNode *curr = head->next;
        ListNode *temp;
        head->next = nullptr;
        while(curr) {
            temp = curr->next;
            curr->next = head;
            head = curr;
            curr = temp;
        }
        // ȡ�������е�ֵ
        while(head) {
            result.push_back(head->val);
            head = head->next;
        }
        return result;
    }
};*/
