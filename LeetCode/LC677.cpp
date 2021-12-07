/**
 *
 * Design a map that allows you to do the following:
 * Maps a string key to a given value.
 * Returns the sum of the values that have a key with a prefix equal to a given string.
 * 
 * Implement the MapSum class:
 * MapSum() Initializes the MapSum object.
 * void insert(String key, int val) Inserts the key-val pair into the map. 
 * If the key already existed, the original key-value pair will be overridden to the new one.
 * 
 * int sum(string prefix) Returns the sum of all the pairs' value whose key starts with the 
 * prefix.
 */

/**
 * Runtime: 4 ms, faster than 61.96% of C++ online submissions for Map Sum Pairs.
 * Memory Usage: 7.9 MB, less than 80.84% of C++ online submissions for Map Sum Pairs.
 */

#include <iostream>
#include <iterator>
#include <map>
#include <iterator>
#include <string>

using namespace std;

class MapSum {
    private:
        map<string, int> mapsum;
        
    public:
        MapSum() {

        }

        void insert(string key, int val) {
            if (this->mapsum.find(key) == this->mapsum.end())
                this->mapsum.insert(pair<string, int>(key, val));
            else
                this->mapsum[key] = val;
        }

        int sum(string prefix) {
            int res = 0;
            map<string, int>::iterator it = this->mapsum.begin();

            while (it != this->mapsum.end()) {
                string word = it->first;
                int value = it->second;
                int i = 0;
                while (i < prefix.length() && prefix[i] == word[i]) {
                    i += 1;
                }
                if (i == prefix.length()) {
                    res += value;
                }
                it++;
            }
            return res;
        }
};


int main() {
    MapSum *obj = new MapSum();

    obj->insert("juan", 1);
    obj->insert("cande", 2);
    obj->insert("juanfrin", 3);
    obj->insert("juancruz", 4);
    obj->insert("caro", 5);
    obj->insert("flor", 6);

    cout << obj->sum("juan") << endl;
    return 0;
}

