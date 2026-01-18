class AuctionSystem {
public:
    unordered_map<int, unordered_map<int, int>> mp;
    unordered_map<int, set<pair<int,int>>> st;

    AuctionSystem() {
    }

    void addBid(int userId, int itemId, int bidAmount) {
        if(mp[itemId].count(userId)) {
            int old = mp[itemId][userId];
            st[itemId].erase({old, userId});
        }
        mp[itemId][userId] = bidAmount;
        st[itemId].insert({bidAmount, userId});
    }

    void updateBid(int userId, int itemId, int newAmount) {
        int old = mp[itemId][userId];
        st[itemId].erase({old, userId});
        mp[itemId][userId] = newAmount;
        st[itemId].insert({newAmount, userId});
    }

    void removeBid(int userId, int itemId) {
        int old = mp[itemId][userId];
        st[itemId].erase({old, userId});
        mp[itemId].erase(userId);
        if(mp[itemId].empty()) {
            mp.erase(itemId);
            st.erase(itemId);
        }
    }

    int getHighestBidder(int itemId) {
        if(!st.count(itemId) || st[itemId].empty()) {
            return -1;
        }
        return st[itemId].rbegin()->second;
    }
};
