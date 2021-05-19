/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */
#include<queue>
#include<unordered_map>
#include<iostream>
using namespace std;
// @lc code=start

class List
{
private:
    struct ListNode
    {
        int key;
    };
    ListNode* m_head;
    ListNode* m_tail;
    int m_nsize;
public:
    int size(){return m_nsize;}
    int get
};
class LRUCache {
public:
    queue<pair<int, int>> m_que;
    unordered_map<int, int> m_map;
    int m_capacity;
    LRUCache(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {
        if (m_map.find(key) != m_map.end())
        {
            if (m_que.)
            {
                /* code */
            }
            
            return m_map[key];
        }
        else
        {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (m_map.find(key) == m_map.end())
        {
            if(m_que.size() <= m_capacity)
            {
                m_map[key] = value;
                m_que.emplace(m_map.equal_range(key));
            }
            else
            {
                m_que.pop();
                m_map[key] = value;
                m_que.emplace(m_map.equal_range(key));            
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

