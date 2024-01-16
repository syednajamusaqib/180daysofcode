class RandomizedSet {
public:
    vector<int> record;
    unordered_map<int,int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        // If val is already present we will return false as we cannot insert
        if(mp.find(val) != mp.end()){
            return false;
        }
        // Put val in record
        record.push_back(val);
        // Update map so that we can access index whenever we want
        mp[val] = record.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        // If val is not present in record then we cannot remove the value
        if(mp.find(val) == mp.end()){
            return false;
        }
        // Shifting current and last element of record
        int currentIndex = mp[val];
        int lastElement = record.back();
        record.back() = val;

        record[currentIndex] = lastElement;
        mp[lastElement] = currentIndex;
        // Removing val from record and its index from map
        record.pop_back();
        mp.erase(val);
        return true;

    }
    
    int getRandom() {
        // Getting random value from record vector
        return record[rand() % record.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
