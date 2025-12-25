class MedianFinder {
public:
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    bool even = true;

    MedianFinder() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    void addNum(int num) {
        if (even) {
            minh.push(num);

            maxh.push(minh.top());
            minh.pop();
        } else {
            maxh.push(num);
            
            minh.push(maxh.top());
            maxh.pop();
        }
        even = !even;
    }

    double findMedian() {
        if (maxh.size() == minh.size()) {
            return (maxh.top() + minh.top()) / 2.0;
        }
        return maxh.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */