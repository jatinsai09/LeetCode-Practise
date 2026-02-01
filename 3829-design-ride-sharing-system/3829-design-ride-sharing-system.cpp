class RideSharingSystem {
public:
    queue<int> drivers, riders;
    unordered_set<int> waiting;
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
        while (!riders.empty() && !waiting.count(riders.front())) {
            int rId = riders.front();
            riders.pop();
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
            waiting.erase(riderId);
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