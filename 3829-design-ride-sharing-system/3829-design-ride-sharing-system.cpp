class RideSharingSystem {
public:
    queue<int> drivers, riders;
    unordered_set<int> waiting, cancelled;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        riders.push(riderId);
        waiting.insert(riderId);
    }
    
    void addDriver(int driverId) {
        drivers.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while (!riders.empty() && cancelled.count(riders.front())) {
            int rId = riders.front();
            riders.pop();
            cancelled.erase(rId);
            waiting.erase(rId);
        }

        if (!riders.empty() && !drivers.empty()) {
            int dId = drivers.front();
            drivers.pop();
            int rId = riders.front();
            riders.pop();
            waiting.erase(rId);

            return {dId, rId};
        }

        return {-1, -1};
    }
    
    void cancelRider(int riderId) {
        if (waiting.count(riderId)) {
            cancelled.insert(riderId);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */