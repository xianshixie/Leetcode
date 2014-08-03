/******************
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. 
When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*******************/

class LRUCache{
public:
    LRUCache(int capacity) {
       _size = capacity; 
    }
    
    int get(int key) {
        
       if (_myhash.find(key)==_myhash.end())
            return -1;
       else
       {
           _mylist.splice(_mylist.begin(),_mylist,_myhash[key]);
           _myhash[key] = _mylist.begin();
           return (_mylist.begin())->val;
       }
            
    }
    
    void set(int key, int value) {
       if (_myhash.find(key)!=_myhash.end())
       {
           (_myhash[key])->val = value;
           _mylist.splice(_mylist.begin(),_mylist,_myhash[key]);
           _myhash[key]=_mylist.begin();
       }
       else
       {
           if (_myhash.size()==_size)
            {
                
                _myhash.erase(_mylist.back().key);
                _mylist.pop_back();
            }
           
           _mylist.push_front(cache_node(key,value));
           _myhash[key]=_mylist.begin();
           
       }
        
    }
    
private:
    struct cache_node{
        int key;
        int val;
        cache_node(int k, int v):key(k),val(v) {}
    };
    
    list<cache_node> _mylist;
    unordered_map<int, list<cache_node>::iterator> _myhash;
    int _size;
    
};


