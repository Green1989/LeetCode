/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include<stack>
#include<iostream>
using namespace std;
// @lc code=start
class MinStack {
private:
    stack<int> m_staData;
    stack<int> m_staMin;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int val) {
        m_staData.push(val);
        if (m_staMin.empty())
        {            
            m_staMin.push(val);
        }
        else
        {
            m_staMin.push(min(m_staMin.top(), val));
        }
    }
    
    void pop() {
        m_staData.pop();
        m_staMin.pop();
    }
    
    int top() {
        return m_staData.top();
    }
    
    int getMin() {
        return m_staMin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

