class NumArray {
private:
    vector<int> tree;
    int n;

    int queryTree(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & (-idx)) {
            sum += tree[idx];
        }
        return sum;
    }
    void updateTree(int idx, int val) {
        for (; idx <= n; idx += idx & (-idx)) {
            tree[idx] += val;
        }
    }
    void buildTree(auto& nums) {
        for (int i = 0; i < n; i++) {
            updateTree(i + 1, nums[i]);
        }
    }
public:
    vector<int> nums;
    NumArray(vector<int>& a) {
        if (!a.empty()) {
            nums = a;
            n = nums.size();
            tree.resize(n + 1);
            buildTree(nums);
        }
    }

    void update(int index, int val) {
        int diff = val - nums[index];
        updateTree(index + 1, diff);
        nums[index] = val;
    }

    int sumRange(int left, int right) {
        return queryTree(right + 1) - queryTree(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */