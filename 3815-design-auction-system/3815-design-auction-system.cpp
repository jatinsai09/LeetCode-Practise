class AuctionSystem {
public:
    unordered_map<int, unordered_map<int, int>> mp;
    unordered_map<int, set<pair<int,int>>> st;

    AuctionSystem() {
    }

    void addBid(int userId, int itemId, int bidAmount) {
        if(mp[itemId].count(userId)) { // if this user already holds a bid for this item
            int old = mp[itemId][userId]; 
            st[itemId].erase({old, userId}); // remove old bid
        }
        mp[itemId][userId] = bidAmount; // update bid amount
        st[itemId].insert({bidAmount, userId}); // add new bid
    }

    void updateBid(int userId, int itemId, int newAmount) {
        int old = mp[itemId][userId];
        st[itemId].erase({old, userId}); // remove old bid
        mp[itemId][userId] = newAmount; // update bid amount
        st[itemId].insert({newAmount, userId}); // add new bid
    }

    void removeBid(int userId, int itemId) {
        int old = mp[itemId][userId];
        st[itemId].erase({old, userId}); // remove current bid
        mp[itemId].erase(userId); // remove this bidder for the item
        if(mp[itemId].empty()) { // if the item has no acitve bid left
            mp.erase(itemId);
            st.erase(itemId); // remove
        }
    }

    int getHighestBidder(int itemId) {
        if(!st.count(itemId) || st[itemId].empty()) { // if this item has no active bids presnt
            return -1;
        }
        return st[itemId].rbegin()->second; // return user who holds the highest bid for this item
    }
};
