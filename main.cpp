#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>
#include <numeric>
#include <algorithm>
#include <stack>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

bool isPerfectSquare(int n) {
    if (n < 0) {
        return false;
    }
    else if (n == 0 || n == 1) {
        return true;
    }

    long left = 1, right = n;

    while (left <= right) {
        long mid = left + (right - left) / 2;
        long square = mid * mid;

        if (square == n) {
            return true;
        }
        else if (square < n) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return false;
}

std::vector<int> mergeSortedLists(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> result;

    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            result.push_back(a[i]);
            i++;
        }
        else {
            result.push_back(b[j]);
            j++;
        }
    }

    while (i < a.size()) {
        result.push_back(a[i]);
        i++;
    }

    while (j < b.size()) {
        result.push_back(b[j]);
        j++;
    }

    return result;
}

bool areBracketsBalanced(const std::string& s) {
    std::stack<char> stack;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (stack.empty()) {
                return false;
            }

            char top = stack.top();
            stack.pop();

            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return false;
            }
        }
    }

    return stack.empty();
}

std::vector<int> removeLastDuplicates(const std::vector<int>& num) {
    std::unordered_map<int, int> count;
    std::vector<int>nums(num.size());
    for (int i = 0; i < num.size(); i++) nums[i] = num[i];
    for (int i = (int)nums.size() - 1; i >= 0; i--) {
        int nu = nums[i];

        if (count[nu] > 0) {
            nums.erase(nums.begin() + i);
        }
        else {
            count[nu]++;
        }
    }
    std::vector<int>ans;
    for (int i = 0; i < nums.size(); i++) ans.push_back(nums[i]);
    return ans;
}


std::string addStrings(std::string a, std::string b) {
    int n = (int)a.size(), m = (int)b.size();
    if (n < m) {
        std::swap(a, b);
        std::swap(n, m);
    }

    int carry = 0;
    std::string result = "";
    for (int i = 0; i < n; i++) {
        int digit_a = a[n - i - 1] - '0';
        int digit_b = i < m ? b[m - i - 1] - '0' : 0;

        int sum = digit_a + digit_b + carry;
        carry = sum / 10;
        result.push_back(sum % 10 + '0');
    }

    if (carry != 0) {
        result.push_back(carry + '0');
    }

    std::reverse(result.begin(), result.end());
    return result;
}

std::string evaluate(std::string s) {
    std::vector<std::string> conditions, expressions;
    int i = 0;

    // Extract conditions from input string
    while (i < s.size()) {
        std::string temp;
        while (i < s.size() && s[i] != ' ') {
            temp.push_back(s[i]);
            i++;
        }
        i++;
        if (s[i] == ':')
            break;
        else
            conditions.push_back(temp);
    }

    // Extract expressions from input string
    i = (int)s.size() - 1;
    while (i >= 0) {
        std::string temp;
        while (i >= 0 && s[i] != ' ') {
            temp.push_back(s[i]);
            i--;
        }
        i--;
        reverse(temp.begin(), temp.end());
        expressions.push_back(temp);
        if (s[i] == '?')
            break;
    }

    // Check if number of conditions and expressions are valid
    if (conditions.size() + 1 != expressions.size())
        return "Invalid Input";
    else {
        bool is_output_print = false;

        // Evaluate conditions and print corresponding expressions
        for (int j = 0; j < conditions.size(); j++) {
            if (conditions[j] == "false") {
                is_output_print = true;
                return expressions[j];
            }
        }

        // Print last expression if no conditions evaluated to false
        if (!is_output_print)
            return expressions.back();
    }
    return "";
}


std::vector<int> squareSorted13(const std::vector<int>& nums) {
    std::vector<int> res(nums.size());
    int left = 0, right = (int)nums.size() - 1;
    for (int i = right; i >= 0; i--) {
        if (abs(nums[left]) > abs(nums[right])) {
            res[i] = nums[left] * nums[left];
            left++;
        }
        else {
            res[i] = nums[right] * nums[right];
            right--;
        }
    }
    return res;
}


int sum_of_numbers(const std::string& s) {
    int sum = 0, current_number = 0;
    for (char c : s) {
        if (isdigit(c)) {
            current_number = current_number * 10 + (c - '0');
        }
        else {
            sum += current_number;
            current_number = 0;
        }
    }
    return sum + current_number;
}

bool fourSum(std::vector<int>& nums, int k) {
    int n = (int)nums.size();
    if (n < 4) return false;

    // Create a hash table to store two element sums and their pair
    std::unordered_map<int, std::pair<int, int>> twoSums;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            twoSums[nums[i] + nums[j]] = { i, j };
        }
    }

    // Find four element sum using the hash table
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int twoSum = nums[i] + nums[j];
            if (twoSums.find(k - twoSum) != twoSums.end()) {
                auto p = twoSums[k - twoSum];
                if (p.first != i && p.first != j && p.second != i && p.second != j) {
                    return true;
                }
            }
        }
    }

    return false;
}


std::string reverseWords(std::string s) {
    std::vector<std::string> words;
    std::string word;

    // Split the string into words
    for (char c : s) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word = "";
            }
        }
        else {
            word += c;
        }
    }

    if (!word.empty()) {
        words.push_back(word);
    }

    std::string reversed;

    // Reverse the order of words and concatenate them
    for (auto it = words.rbegin(); it != words.rend(); ++it) {
        reversed += *it;
        reversed += ' ';
    }

    // Remove the last space
    if (!reversed.empty()) {
        reversed.pop_back();
    }

    return reversed;
}

std::string toBase3(int n) {
    if (n == 0) {
        return "0";
    }

    std::string result = "";
    while (n > 0) {
        int rem = n % 3;
        result += std::to_string(rem);
        n /= 3;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

int maxOperations(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> freq;
    int count = 0;
    for (int i : nums) {
        if (freq[target - i] > 0) {
            count++;
            freq[target - i]--;
        }
        else {
            freq[i]++;
        }
    }
    return count;
}

std::vector<int> mergeSortedArrays1(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> result;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            result.push_back(a[i]);
            i++;
        }
        else {
            result.push_back(b[j]);
            j++;
        }
    }
    while (i < a.size()) {
        result.push_back(a[i]);
        i++;
    }
    while (j < b.size()) {
        result.push_back(b[j]);
        j++;
    }
    return result;
}

std::vector<int> squareSorted(const std::vector<int>& nums) {
    std::vector<int> result(nums.size());
    int left = 0, right = (int)nums.size() - 1, idx = right;
    while (left <= right) {
        int leftSq = nums[left] * nums[left];
        int rightSq = nums[right] * nums[right];
        if (leftSq > rightSq) {
            result[idx--] = leftSq;
            left++;
        }
        else {
            result[idx--] = rightSq;
            right--;
        }
    }
    return result;
}

struct TreeNode {
    int val;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool checkLeavesAtSameLevel(const std::shared_ptr<TreeNode>& root) {
    if (!root) 
        return true;
    std::queue<std::shared_ptr<TreeNode>> q;
    q.push(root);
    int targetLevel = -1;

    while (!q.empty()) {
        int size = (int)q.size();
        int level = -1;

        for (int i = 0; i < size; i++) {
            auto node = q.front();
            q.pop();

            if (!node->left && !node->right) {
                if (level == -1)
                    level = targetLevel;
                if (level != targetLevel)
                    return false;
            }

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        targetLevel++;
    }

    return true;
}
 
std::string addStrings4(std::string a, std::string b) {
    int i = (int)a.length() - 1, j = (int)b.length() - 1, carry = 0;
    std::string result = "";

    while (i >= 0 || j >= 0 || carry != 0) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }
        carry = sum / 10;
        result += std::to_string(sum % 10);
    }

    std::reverse(result.begin(), result.end());
    return result;
}



 
int  sumTree(const std::shared_ptr<TreeNode>& root) {
    if (!root)
        return 0;

    int sum = root->val + sumTree(root->left) + sumTree(root->right);
    return sum;
}

std::string toBase34(int n) {
    if (n == 0) {
        return "0";
    }

    std::string result = "";
    while (n > 0) {
        int rem = n % 3;
        result += std::to_string(rem);
        n /= 3;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

bool isPerfectSquare1(int n) {
    if (n < 0) {
        return false;
    }
    else if (n == 0 || n == 1) {
        return true;
    }

    long left = 1, right = n;

    while (left <= right) {
        long mid = left + (right - left) / 2;
        long square = mid * mid;

        if (square == n) {
            return true;
        }
        else if (square < n) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return false;
}
 

int maxPathSum11(const std::shared_ptr<TreeNode>& root,int &ans) {
    if (!root) return 0;
    int l = std::max(0, maxPathSum11(root->left,ans));
    int r = std::max(0, maxPathSum11(root->right,ans));
    ans = std::max(ans, l + r + root->val);
    return std::max(l, r) + root->val;
}
int maxPathSum(const std::shared_ptr<TreeNode>& root) {
    int ans= std::numeric_limits<int>::min();
    if (!root) return 0;
    maxPathSum11(root,ans);
    return ans;
}
 

struct ListNode {
    int val;
    std::shared_ptr<ListNode> next;

    ListNode(int x) : val(x), next(nullptr) {}
};

int binaryToDecimal1(const std::shared_ptr<ListNode>& head) {
    int result = 0;
    std::shared_ptr<ListNode> curr = head;

    while (curr) {
        result = (result << 1) | curr->val;
        curr = curr->next;
    }

    return result;
}

std::vector<int> merge(std::vector<int> v1, std::vector<int> v2) {
    std::vector<int> result;
    int i = 0, j = 0;

    while (i < v1.size() && j < v2.size()) {
        if (v1[i] <= v2[j]) {
            result.push_back(v1[i]);
            i++;
        }
        else {
            result.push_back(v2[j]);
            j++;
        }
    }

    // Copy the remaining elements from v1, if any
    while (i < v1.size()) {
        result.push_back(v1[i]);
        i++;
    }

    // Copy the remaining elements from v2, if any
    while (j < v2.size()) {
        result.push_back(v2[j]);
        j++;
    }

    return result;
}

 


bool isPalindrome(const std::shared_ptr<ListNode>& head) {
    if (!head || !head->next)
        return true;

    // Find the middle of the linked list
    std::shared_ptr<ListNode> slow = head;
    std::shared_ptr<ListNode> fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list
    std::shared_ptr<ListNode> prev = nullptr;
    std::shared_ptr<ListNode> curr = slow->next;
    while (curr) {
        std::shared_ptr<ListNode> next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Compare the first half with the reversed second half
    std::shared_ptr<ListNode> p1 = head;
    std::shared_ptr<ListNode> p2 = prev;
    while (p1 && p2) {
        if (p1->val != p2->val)
            return false;
        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}

std::vector<int> primeFactors(int n) {
    std::vector<int> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    // Check for divisibility by odd primes starting from 3
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    // If n is still greater than 2, it must be a prime number
    if (n > 2) {
        factors.push_back(n);
    }

    return factors;
}

int largestCommonDivisor(const std::vector<int>& nums) {
    //std::assert(nums.size() > 0);
    if (nums.size() == 1) return nums[0];
    int ans = gcd(nums[0], nums[1]);
    for (size_t i = 2; i < nums.size(); i++) {
        ans = gcd(ans, nums[i]);
    }
    return ans;
}



int sumOf(const std::shared_ptr<TreeNode>& root,int &ans1)
{
    if (root == NULL)
        return ans1;

    if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
        ans1 += root->left->val;

    sumOf(root->left,ans1);
    sumOf(root->right,ans1);
    return ans1;
}

int sumOfLeftLeaves(const std::shared_ptr<TreeNode>& root) {
    int ans1 = 0;
    return sumOf(root, ans1);
}

 
bool only235PrimeFactors1(int n) {
    if (n == 1||n==0) return false;
    int x = n;
    while (1) {
        if (n % 2 == 0) n /= 2;
        if (n % 3 == 0) n /= 3;
        if (n % 5 == 0) n /= 5;
        if (x == n) return false;
        if (n == 1) return true;
        x = n;
    }
}


int binaryListToInt(const std::shared_ptr<ListNode>& root) {
    int num = 0;
    std::shared_ptr<ListNode> head = root;
    while (head != nullptr) {
        num = num * 2 + head->val;
        head = head->next;
    }
    return num;
}


int maxUniqueSublistSum1(const std::vector<int>& nums) {
    int left = 0, right = 0;
    int sum = 0, max_sum = 0;
    std::unordered_set<int> seen_values;

    while (right < nums.size()) {
        if (seen_values.find(nums[right]) == seen_values.end()) {
            seen_values.insert(nums[right]);
            sum += nums[right];
            max_sum = std::max(max_sum, sum);
            right++;
        }
        else {
            seen_values.erase(nums[left]);
            sum -= nums[left];
            left++;
        }
    }

    return max_sum;
}


std::vector<int> ranking(const std::vector<int>& nums) {
    int n = (int)nums.size();
    std::vector<int> sorted_nums(nums.begin(), nums.end());
    sort(sorted_nums.begin(), sorted_nums.end(), std::greater<int>());
    std::unordered_map<int, int> rank_map;
    int a = 0;
    for (int i = 0; i < n; i++) {
        if (rank_map.find(sorted_nums[i]) == rank_map.end()) {
            rank_map[sorted_nums[i]] = a;
            a++;
        }
    }
    std::vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = rank_map[nums[i]];
    }
    return result;
}

std::string addStrings12(std::string a, std::string b) {
    int n = (int)a.size(), m = (int)b.size();
    if (n < m) {
        std::swap(a, b);
        std::swap(n, m);
    }

    int carry = 0;
    std::string result = "";
    for (int i = 0; i < n; i++) {
        int digit_a = a[n - i - 1] - '0';
        int digit_b = i < m ? b[m - i - 1] - '0' : 0;

        int sum = digit_a + digit_b + carry;
        carry = sum / 10;
        result.push_back(sum % 10 + '0');
    }

    if (carry != 0) {
        result.push_back(carry + '0');
    }

    std::reverse(result.begin(), result.end());
    return result;
}


std::string evaluate11(std::string s) {
    std::vector<std::string> conditions, expressions;
    int i = 0;

    // Extract conditions from input string
    while (i < s.size()) {
        std::string temp;
        while (i < s.size() && s[i] != ' ') {
            temp.push_back(s[i]);
            i++;
        }
        i++;
        if (s[i] == ':')
            break;
        else
            conditions.push_back(temp);
    }

    // Extract expressions from input string
    i = (int)s.size() - 1;
    while (i >= 0) {
        std::string temp;
        while (i >= 0 && s[i] != ' ') {
            temp.push_back(s[i]);
            i--;
        }
        i--;
        reverse(temp.begin(), temp.end());
        expressions.push_back(temp);
        if (s[i] == '?')
            break;
    }

    // Check if number of conditions and expressions are valid
    if (conditions.size() + 1 != expressions.size())
        return "Invalid Input";
    else {
        bool is_output_print = false;

        // Evaluate conditions and print corresponding expressions
        for (int j = 0; j < conditions.size(); j++) {
            if (conditions[j] == "false") {
                is_output_print = true;
                return expressions[j];
            }
        }

        // Print last expression if no conditions evaluated to false
        if (!is_output_print)
            return expressions.back();
    }
    return "";
}



int largestCommonDivisor11(const std::vector<int>& nums) {
    int result = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        result = gcd(result, nums[i]);
    }
    return result;
}


bool isPerfectSquare2(int n) {
    int sum = 0;
    int i = 1;

    while (sum < n) {
        sum += i;
        i += 2;
    }

    return (sum == n);
}

int findMiddleNode(const std::shared_ptr<ListNode>& head) {
    if (!head) return -1;
    if (!head->next) return head->val;
    std::shared_ptr<ListNode> l = head;
    std::shared_ptr<ListNode> h = head;
    while (h && h->next) {
        l = l->next;
        h = h->next->next;
    }
    return l->val;
}

 

bool isPerfectSquare4(int n) {
    int sum = 0;
    int i = 1;

    while (sum < n) {
        sum += i;
        i += 2;
    }

    return (sum == n);
}

int sum_of_numbers1(const std::string& s) {
    int sum = 0, current_number = 0;
    for (char c : s) {
        if (isdigit(c)) {
            current_number = current_number * 10 + (c - '0');
        }
        else {
            sum += current_number;
            current_number = 0;
        }
    }
    return sum + current_number;
}

int maxUniqueSublistSum(const std::vector<int>& nums) {
    std::unordered_set<int> unique_nums;
    int sum = 0, max_sum = 0;
    int left = 0, right = 0;

    while (right < nums.size()) {
        if (unique_nums.find(nums[right]) == unique_nums.end()) {
            unique_nums.insert(nums[right]);
            sum += nums[right];
            max_sum = std::max(max_sum, sum);
            ++right;
        }
        else {
            unique_nums.erase(nums[left]);
            sum -= nums[left];
            ++left;
        }
    }

    return max_sum;
}

int maxSumSublist(const std::vector<int>& nums) {
    int n = (int)nums.size();
    int max_sum = 0;
    int i = 0, j = 0;
    std::unordered_set<int> st;
    while (i < n && j < n) {
        if (st.count(nums[j]) == 0) {
            st.insert(nums[j]);
            max_sum = std::max(max_sum, accumulate(nums.begin() + i, nums.begin() + j + 1, 0));
            j++;
        }
        else {
            st.erase(nums[i]);
            i++;
        }
    }
    return max_sum;
}

 

int getDecimalValue(const std::shared_ptr<ListNode>& head) {
    int result = 0;
    std::shared_ptr<ListNode> current = head;
    while (current != NULL) {
        result = result * 2 + current->val;
        current = current->next;
    }
    return result;
}

std::string deleteConsecutiveDuplicates(std::string s) {
    std::stack<char> st;
    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop();
        }
        else {
            st.push(c);
        }
    }
    std::string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    std::reverse(result.begin(), result.end());
    return result;
}

std::string toBase31(int n) {
    if (n == 0) {
        return "0";
    }

    std::string result = "";
    while (n > 0) {
        int rem = n % 3;
        result += std::to_string(rem);
        n /= 3;
    }

    std::reverse(result.begin(), result.end());
    return result;
}


bool only235PrimeFactors(int n) {
    if (n == 1) return false;
    while (n % 2 == 0) {
        n /= 2;
    }
    while (n % 3 == 0) {
        n /= 3;
    }
    while (n % 5 == 0) {
        n /= 5;
    }
    return n == 1;
}


int maxOperations1(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> freq;
    int count = 0;
    for (int i : nums) {
        if (freq[target - i] > 0) {
            count++;
            freq[target - i]--;
        }
        else {
            freq[i]++;
        }
    }
    return count;
}

int main() {
    return 0;
}