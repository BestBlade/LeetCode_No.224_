/* ------------------------------------------------------------------|
实现一个基本的计算器来计算一个简单的字符串表达式 s 的值。

 

示例 1：

输入：s = "1 + 1"
输出：2
示例 2：

输入：s = " 2-1 + 2 "
输出：3
示例 3：

输入：s = "(1+(4+5+2)-3)+(6+8)"
输出：23
 

提示：

1 <= s.length <= 3 * 105
s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
s 表示一个有效的表达式

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/basic-calculator
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*
*
*	执行用时：8 ms, 在所有 C++ 提交中击败了92.89%的用户
*	内存消耗：7.9 MB, 在所有 C++ 提交中击败了81.50%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

int calculate(string s) {
    int res = 0;
    int sign = 1;
    stack<int> operators;
    operators.emplace(1);

    int n = s.size();
    int i = 0;
    while (i < n) {
        if (s[i] == ' ') {
            i++;
        }
        else if (s[i] == '(') {
            operators.emplace(sign);
            i++;
        }
        else if (s[i] == '+') {
            sign = operators.top();
            i++;
        }
        else if (s[i] == '-') {
            sign = -operators.top();
            i++;
        }
        else if (s[i] == ')') {
            operators.pop();
            i++;
        }
        else {
            long tmp = 0;
            while (i < n && s[i] >= '0' && s[i] <= '9') {
                tmp = tmp * 10 + s[i] - '0';
                i++;
            }
            res += tmp * sign;
        }
    }
    return res;
}

int main() {
    string s = "(1+(4+5+2)-3)+(6+8)";
    calculate(s);
}