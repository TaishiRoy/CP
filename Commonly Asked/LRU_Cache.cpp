

// function to implement LRU cache operations
// more at https://www.interviewbit.com/problems/lru-cache/
// O(capacity) time complexity O(capacity) auxiliary space


int capa;
unordered_map<int, int> mp;
list<int> dl;

LRUCache::LRUCache(int capacity) {
    capa = capacity;
    mp.clear();
    dl.clear();
}

int LRUCache::get(int key) {
    if(mp.count(key))
    {
        dl.remove(key);
        dl.push_back(key);
        return mp[key];
    }
    return -1;
}

void LRUCache::set(int key, int value) {
    if(mp.count(key))  
    {
        dl.remove(key);
        dl.push_back(key);
        mp[key] = value;
        return;
    }
    if(mp.size()>=capa)
    {
        mp.erase(dl.front());
        dl.pop_front();
        dl.push_back(key);
        mp[key] = value;
        return;
    }
    dl.push_back(key);
    mp[key]=value;
    
}
    
