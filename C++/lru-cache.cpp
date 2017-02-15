// Time:  O(1), per operation.
// Space: O(k), k is the capacity of cache.

#include <list>

class LRUCache {
public:
    LRUCache(int capacity) : capa_(capacity) {
    }
    
    int get(int key) {
        if (map_.find(key) != map_.end()) {
            // It key exists, update it.
            const auto value = map_[key]->second;
            update(key, value);
            return value;
        } else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        // If cache is full while inserting, remove the last one.
        if (map_.find(key) == map_.end() && list_.size() == capa_) {
            auto del = list_.back(); list_.pop_back();
            map_.erase(del.first);
        }
         update(key, value);
    }
    
private:
    list<pair<int, int>> list_; // key, value
    unordered_map<int, list<pair<int, int>>::iterator> map_; // key, list iterator
    int capa_;
    
    // Update (key, iterator of (key, value)) pair
    void update(int key, int value) {
        auto it = map_.find(key);
        if (it != map_.end()) {
            list_.erase(it->second);
        }
        list_.emplace_front(key, value);
        map_[key] = list_.begin();
    }
};
-e 
// -----JF-----

class LRUCache{
  public:
    unordered_map<int, int> dict_;
    unordered_map<int, list<int>::iterator> pos_;
    list<int> current_list_;
    int capacity_;

    LRUCache(int capacity) {
      dict_.clear();
      pos_.clear();
      current_list_.clear();
      capacity_ = capacity;
    }

    int get(int key) {
      if (dict_.find(key) == dict_.end()) return -1;
      int res = dict_[key];
      update(key);
      return res;
    }

    void set(int key, int value) {
      if (dict_.find(key) == dict_.end() && dict_.size() == capacity_) pop();
      dict_[key] = value;
      update(key);
    }

  private:
    void update(const int &key) {
      if (pos_.find(key) != pos_.end()) {
        list<int>::iterator iter = pos_[key];
        current_list_.erase(iter);
      }
      current_list_.push_back(key);
      pos_[key] = -- current_list_.end();
    }

    void pop() {
      int key = *current_list_.begin();
      dict_.erase(key);
      pos_.erase(key);
      current_list_.pop_front();
    }
};
