#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.22: Revise your TextQuery programs from § 12.3 (p. 484) so
 *   that the shared_ptr members use a DebugDelete as their deleter (§
 *   12.1.4, p. 468).
 * 
 */

class DeleterDebug
{
private:
    ostream& os;
public:
    DeleterDebug(ostream& _os = std::cerr) : os(_os) {}
    ~DeleterDebug() {}

    template<typename T>
    void operator() (T* p)
    {
        os << "[DeleterDebugger] You are deleting the object " << reinterpret_cast<void *>(p) << endl;
        delete p;
        os << "[DeleterDebugger] The memory " << reinterpret_cast<void *>(p) << " has been deleted " << endl;
    }
};

class TextResult
{
private:
    weak_ptr<set<size_t>> ws_line_nums;
    weak_ptr<vector<string>> wv_content;
    string key;
public:
    explicit TextResult(shared_ptr<set<size_t>> _ws,
                        shared_ptr<vector<string>> _ct, 
                        string _key) : ws_line_nums{_ws}
                                    , wv_content{_ct}
                                    , key(_key)
    {

    }
    ~TextResult() {}

    void print(void)
    {
        if (ws_line_nums.lock() == nullptr || wv_content.lock() == nullptr)
        {
            cout << key << "Not found!" << endl;
            return;
        }
            

        auto s_line = ws_line_nums.lock();
        auto contents = wv_content.lock();

        cout << key << " Found "<< s_line->size() << " lines" << endl;
        for (auto itor = s_line->begin(); itor != s_line->end(); itor++)
        {
            cout << "line: " << *itor << " " << (*contents)[*itor] << endl;
        }

    }
};

class TextQuery
{
private:
    shared_ptr<map<string, shared_ptr<set<size_t>>>> hash;
    shared_ptr<vector<string>> contents;
public:
    explicit TextQuery(const string& filename)  : hash{new map<string, shared_ptr<set<size_t>>>, DeleterDebug()}
                                                , contents{new vector<string>, DeleterDebug()}
    {
        ifstream ifs(filename);
        string line;
        size_t line_num = 1;
        
        contents->push_back("dummy for first line");

        while (getline(ifs, line))
        {
            istringstream oss(line);
            string word;

            while (oss >> word)
            {
                auto itor = hash->find(word);
                if (itor == hash->end())
                {
                    shared_ptr<set<size_t>> p_set{new set<size_t>{line_num}, DeleterDebug()};
                    hash->insert_or_assign(word, p_set);
                }    
                else
                    itor->second->insert(line_num);
            }

            contents->push_back(line);
            line_num++;
        }
        cout << endl;
    }

    ~TextQuery() {}

    TextResult query(string s)
    {
        auto itor = hash->find(s);
        if (itor == hash->end())
            return TextResult(make_shared<set<size_t>>(), make_shared<vector<string>>(), s);

        return TextResult{itor->second, contents, s};
    }

    void print_contents()
    {
        for (auto& p : (*contents))
            cout << p << endl;
    }

    void print_hash()
    {
        for (auto map_itor = hash->begin(); map_itor != hash->end(); map_itor++)
        {
            cout << map_itor->first << ": ";
            auto& line_set = map_itor->second;

            for (auto set_itor = line_set->begin(); set_itor != line_set->end(); set_itor++)
                cout << *set_itor << ", ";
            
            cout << endl;
        }
    }
};


int main(int argc, char **argv)
{
    cout << "Hello chapter " << endl;
    
    TextQuery tq("tq-data.txt");

    auto rs = tq.query("their");
    rs.print();

    return 0;
}