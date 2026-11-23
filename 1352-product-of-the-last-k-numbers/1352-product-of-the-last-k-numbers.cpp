class ProductOfNumbers {
public:
    vector<int> v = {1};
    ProductOfNumbers() {}

    void add(int num) {
        if (num) {
            v.push_back(v.back() * num);
        } else {
            v = {1};
        }
    }

    int getProduct(int k) {
        return k < v.size() ? v.back() / v[v.size() - k - 1] : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */