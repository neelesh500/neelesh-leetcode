class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        int k = queryIndices.size(); 

        struct Node {
            int maxLen;
            int prefixLen;
            int suffixLen;
            char leftChar;
            char rightChar;
        };

        vector<Node> tree(4 * n);

        auto merge = [](const Node& left, const Node& right, int leftSize, int rightSize) -> Node {
            Node parent;
            parent.leftChar = left.leftChar;
            parent.rightChar = right.rightChar;
            parent.maxLen = max(left.maxLen, right.maxLen);
            parent.prefixLen = left.prefixLen;
            parent.suffixLen = right.suffixLen;

            if (left.rightChar == right.leftChar) {
                parent.maxLen = max(parent.maxLen, left.suffixLen + right.prefixLen);

                if (left.prefixLen == leftSize) {
                    parent.prefixLen = leftSize + right.prefixLen;
                }
                if (right.suffixLen == rightSize) {
                    parent.suffixLen = rightSize + left.suffixLen;
                }
            }
            return parent;
        };

     
        auto build = [&](auto& self, int node, int start, int end) -> void {
            if (start == end) {
                tree[node] = {1, 1, 1, s[start], s[start]};
                return;
            }
            int mid = start + (end - start) / 2;
            int leftChild = 2 * node;
            int rightChild = 2 * node + 1;

            self(self, leftChild, start, mid);
            self(self, rightChild, mid + 1, end);

            int leftSize = mid - start + 1;
            int rightSize = end - mid;

            tree[node] = merge(tree[leftChild], tree[rightChild], leftSize, rightSize);
        };

        auto update = [&](auto& self, int node, int start, int end, int idx, char ch) -> void {
            if (start == end) {
                tree[node] = {1, 1, 1, ch, ch};
                return;
            }
            int mid = start + (end - start) / 2;
            int leftChild = 2 * node;
            int rightChild = 2 * node + 1;

            if (idx <= mid) {
                self(self, leftChild, start, mid, idx, ch);
            } else {
                self(self, rightChild, mid + 1, end, idx, ch);
            }

            int leftSize = mid - start + 1;
            int rightSize = end - mid;

            tree[node] = merge(tree[leftChild], tree[rightChild], leftSize, rightSize);
        };

        build(build, 1, 0, n - 1);

        vector<int> ans(k);

        for (int i = 0; i < k; ++i) {
            int idx = queryIndices[i];
            char ch = queryCharacters[i];

            update(update, 1, 0, n - 1, idx, ch);
            ans[i] = tree[1].maxLen;
        }

        return ans;
    }
};