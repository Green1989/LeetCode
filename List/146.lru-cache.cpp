/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */
#include<conio.h>
#include<unordered_map>
#include<iostream>
using namespace std;
// @lc code=start

class MyListNode
{
public:    
    MyListNode(int nKey):key(nKey),next(nullptr),pre(nullptr){}
    int key;
    MyListNode* next;
    MyListNode* pre;
};

class List
{
private:    
    MyListNode* m_head;
    MyListNode* m_tail;
    int m_nSize;
public:
    List():m_nSize(0),m_head(nullptr),m_tail(nullptr){}
    int size(){return m_nSize;}
    int getHeadKey(){return m_head->key;}
    void get(MyListNode* node)
    {
        if (node == nullptr || node == m_tail)
        {
            return;
        }
        else if (node == m_head)
        {
            m_head = m_head->next;
        }
        else
        {
            MyListNode* pre = node->pre;
            MyListNode* next = node->next;
            pre->next = next;
            next->pre = pre;            
        }
        insert(node);
        m_nSize--;
    }
    void insert(MyListNode* node)
    {
        if (node == nullptr)
        {
            return;
        }
        if (m_tail != nullptr)
        {
            m_tail->next = node;
            node->pre = m_tail;
            node->next = nullptr;
            m_tail = node;
        }
        else
        {
            m_head = node;
            m_tail = node;
        }
        m_nSize++;
    }
    MyListNode* replace(int key)
    {
        if (m_head != m_tail)
        {
            MyListNode* head = m_head->next;
            m_head->key = key;
            insert(m_head);
            m_nSize--;
            m_head = head;
        }
        else
        {
            m_tail->key = key;
        }
        return m_tail;
    }
};
class LRUCache {
private:
    List m_List;
    unordered_map<int, pair<int, MyListNode*>> m_map;
    int m_capacity;
public:

    LRUCache(int capacity):m_capacity(capacity) {
    }
    
    int get(int key) {
        if (m_map.find(key) != m_map.end())
        {
            m_List.get(m_map[key].second);            
            return m_map[key].first;
        }
        else
        {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (m_map.find(key) == m_map.end())
        {
            if(m_List.size() < m_capacity)
            {
                MyListNode* cur = new MyListNode(key);                
                m_map[key].first = value;
                m_map[key].second = cur;
                m_List.insert(cur);
            }
            else
            {
                m_map.erase(m_List.getHeadKey());
                m_map[key].second = m_List.replace(key);
                m_map[key].first = value;
            }
        }
        else
        {
            m_map[key].first = value;
            m_List.get(m_map[key].second);
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

int main()
{
    LRUCache lRUCache(2);
    lRUCache.put(2, 1); // 缓存是 {1=1}
    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    lRUCache.get(2);    // 返回 1
    lRUCache.put(1, 1); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    lRUCache.put(4, 1); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    lRUCache.get(2);    // 返回 -1 (未找到)  
    // LRUCache lRUCache(2);
    // lRUCache.put(1, 1); // 缓存是 {1=1}
    // lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    // lRUCache.get(1);    // 返回 1
    // lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    // lRUCache.get(2);    // 返回 -1 (未找到)
    // lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    // lRUCache.get(1);    // 返回 -1 (未找到)
    // lRUCache.get(3);    // 返回 3
    // lRUCache.get(4);    // 返回 4    
    _getch();
    return 0;
}
