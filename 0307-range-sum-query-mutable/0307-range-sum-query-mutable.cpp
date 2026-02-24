class NumArray {
private:
    vector<int> tree;
    int n;

    void buildTree(vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        buildTree(nums, leftChild, start, mid);
        buildTree(nums, rightChild, mid + 1, end);

        tree[node] = tree[leftChild] + tree[rightChild];
    }

    void updateTree(int node, int start, int end, int ind, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        if (ind <= mid) {
            updateTree(leftChild, start, mid, ind, val);
        } else {
            updateTree(rightChild, mid + 1, end, ind, val);
        }

        tree[node] = tree[leftChild] + tree[rightChild];
    }

    int queryTree(int node, int start, int end, int left, int right) {
        if (end < left || start > right) {
            return 0;
        }
        if (left <= start && end <= right) {
            return tree[node];
        }

        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        int leftSum = queryTree(leftChild, start, mid, left, right);
        int rightSum = queryTree(rightChild, mid + 1, end, left, right);

        return leftSum + rightSum;
    }

public:
    NumArray(vector<int>& nums) {
        if (!nums.empty()) {
            n = nums.size();
            tree.resize(4 * n);
            buildTree(nums, 0, 0, n - 1);
        }
    }

    void update(int index, int val) { updateTree(0, 0, n - 1, index, val); }

    int sumRange(int left, int right) {
        return queryTree(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */