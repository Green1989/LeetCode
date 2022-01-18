#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include <numeric>
#include<istream>
#include<string>
#include<sstream>
#include<iostream>
#include<conio.h>
#include<assert.h>
#include<unordered_set>
#include<unordered_map>
#include<math.h>
using namespace std;

class trie
{
private:
    bool m_bFlag;
    string m_sData;
    unordered_map<string, trie*> m_mpNext;
public:
    trie():m_bFlag(false)
    {
    }
    void insert(string data)
    {
        int nPos = 0;
        int start = data.find('/', nPos);
        while (start != string::npos)
        {
            start = data.find('/', nPos);
        }
        
    }
    // ~trie()
    // {}
};


class FileSystem {
public:
    FileSystem() {

    }
    
    vector<string> ls(string path) {

    }
    
    void mkdir(string path) {

    }
    
    void addContentToFile(string filePath, string content) {

    }
    
    string readContentFromFile(string filePath) {

    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */

