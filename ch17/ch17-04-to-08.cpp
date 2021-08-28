#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 17.5: Exercise 17.4: Write and test your own version of the findBook function.
 * 
 *  Exercise 17.5: Rewrite findBook to return a pair that holds an index and a pair of iterators.
 * 
 *  Exercise 17.6: Rewrite findBook so that it does not use tuple or pair.
 * 
 *  Exercise 17.6: Explain which version of findBook you prefer and why.
 * 
 *  Answer : I prefer Tuple version because this is more flexible.
 * 
 *  Exercise 17.8: What would happen if we passed Sales_data() as the
 *  third parameter to accumulate in the last code example in this section?
 * 
 *  Answer : Nothing happened, it's the same as passed Sales_data(s). Because std::accumulate's third parameter is the 
 *  initial value of the sum. It's will be zero whether Sales_data() or Sales_data(s). Check the constructor of Sales_data 
 *  and the operator+= member for more information.
 */
struct Sales_Data;
using ItVec = vector<Sales_Data>::const_iterator; 
using ItorPair = pair<ItVec, ItVec>;
using SizeVec = vector<Sales_Data>::size_type; 
using StorePair_t = pair<SizeVec, ItorPair>;

struct Sales_Data
{
    string isbn;
    Sales_Data(const string s) : isbn{s} {}

    friend ostream& operator<<(ostream& _os,const Sales_Data& obj)
    {
        _os << obj.isbn;
        return _os;
    }

    // Todo: remember we need const at the end of function
    // Reference : https://en.cppreference.com/w/cpp/language/operator_comparison
    bool operator==( const Sales_Data& rhs) const       /*  (1)     */
    //                                      ^^^^^ Signature for overload operator==
    {
        return isbn == rhs.isbn;
    }
};


// TODO Explain why we need overload operator== outside of class.
// Same as  /*  (1)     Ref: https://en.cppreference.com/w/cpp/language/operator_comparison */
// bool operator==(const Sales_Data& lhs, const Sales_Data& rhs)
// {
//     return lhs.isbn == rhs.isbn;
// }

// matches has three members: an index of a store and iterators into that store's vector
typedef tuple<vector<Sales_Data>::size_type,
        vector<Sales_Data>::const_iterator,
        vector<Sales_Data>::const_iterator> matches;

/* Exercise 17.4 */
vector<matches> findBookTuple(const vector<vector<Sales_Data>> &files,
                        const Sales_Data &book)
{
    vector<matches> result;
    for (auto it = files.cbegin(); it != files.cend(); it++)
    {
        auto found = find(it->cbegin(), it->cend(), book);

        if (found != it->cend())
        {
            auto next = found;
            std::advance(next, 1);
            result.push_back(make_tuple(it - files.cbegin(), found, next));
        }
    }

    return result;
}

/* Exercise 17.5 */
vector<StorePair_t> findBookPairVer(const vector<vector<Sales_Data>> &files,
                            const Sales_Data &book)
{
    vector<StorePair_t> result;
    ItorPair itPair;

    for (auto it = files.cbegin(); it != files.cend(); it++)
    {
        auto found = find(it->cbegin(), it->cend(), book);

        if (found != it->cend())
        {
            auto next = found;
            std::advance(next, 1);
            result.push_back(make_pair(it - files.cbegin(), make_pair(found, next)));
        }
    }

    return result;
}

/* Exercise 17.6 */
struct StoreData
{
    SizeVec index;
    ItVec first, last;

    StoreData(SizeVec _idx, ItVec _first, ItVec _last) : index{_idx}, first{_first}, last{_last} {}
    ~StoreData() {}
};

vector<StoreData> findBookNomal(const vector<vector<Sales_Data>> &files,
                            const Sales_Data &book)
{
    vector<StoreData> result;

    for (auto it = files.cbegin(); it != files.cend(); it++)
    {
        auto found = find(it->cbegin(), it->cend(), book);

        if (found != it->cend())
        {
            auto next = found;
            std::advance(next, 1);
            result.push_back(StoreData{static_cast<SizeVec>(it - files.cbegin()), found, next});
        }
    }

    return result;
}


int main(int argc, char **argv)
{
    vector<Sales_Data> store1{Sales_Data("123456789"), Sales_Data("12345678910"), Sales_Data("12345678"), Sales_Data("123456789"), Sales_Data("12345")};
    vector<Sales_Data> store2{Sales_Data("123456789"), Sales_Data("12345678910"), Sales_Data("12345678"), Sales_Data("12356789"), Sales_Data("12345")};

    vector<vector<Sales_Data>> stores{store1, store2};

    Sales_Data book{"123456789"};
    vector<matches> available_book = findBookTuple(stores, book);

    for (auto store = available_book.cbegin(); store != available_book.cend(); ++store)
    {
        cout << "Store " << get<0>(*store) << endl;
        for (auto it = get<1>(*store); it != get<2>(*store); ++it)
            cout << "  " << *it << endl;
    }

    cout << endl << " Version using pair" << endl;
    vector<StorePair_t> available_book_pair = findBookPairVer(stores, book);
    for (auto store = available_book_pair.cbegin(); store != available_book_pair.cend(); ++store)
    {
        cout << "Store pair ver " << store->first << endl;
        for (auto it = store->second.first; it != store->second.second; ++it)
            cout << "  " << *it << endl;
    }

    cout << endl << " Version using Normal" << endl;
    vector<StoreData> store_vec = findBookNomal(stores, book);
    for (auto store = store_vec.cbegin(); store != store_vec.cend(); ++store)
    {
        cout << "Store pair ver " << store->index << endl;
        for (auto it = store->first; it != store->last; ++it)
            cout << "  " << *it << endl;
    }

    return 0;
}