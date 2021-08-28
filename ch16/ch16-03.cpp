#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.3: Call your compare function on two Sales_data objects to
 *  see how your compiler handles errors during instantiation.
 *
 */

class SalesData
{   
    struct units_price
    {
        uint64_t units;
        double prices;

        units_price(uint64_t u, double p) : units{u}, prices{p} {}

        explicit operator double() const
        {
            return units * prices;
        }

    };
public:
    SalesData(string br) : branch{br}, revenue{0.0} {}
    SalesData() {}
    ~SalesData() {}

    SalesData& addSellingItem(string isbn, uint64_t u, double p)
    {
        auto itor = db.find(isbn);
        if (itor != db.end())
        {
            itor->second.push_back(units_price{u, p});
        }
        else
        {
            db[isbn] = vector<units_price>{units_price{u, p}};
        }

        return *this;
    }

    bool operator==(const SalesData& rhs) const
    {
        updateRevenue();
        return this->revenue == rhs.revenue;
    }

    bool operator!=(const SalesData& rhs) const
    {
        updateRevenue();
        return this->revenue != rhs.revenue;
    }

    bool operator<(const SalesData& rhs) const
    {
        updateRevenue();
        return this->revenue < rhs.revenue;
    }

    bool operator>(const SalesData& rhs) const
    {
        updateRevenue();
        return this->revenue > rhs.revenue;
    }

    void print()
    {
        updateRevenue();
        cout << "Store name : " << branch << ", revenue " << revenue << endl;
        for (auto&& it = db.begin(); it != db.end(); it++)
        {
            cout << "isbn : " << it->first << endl;
            cout << "\tunits\t\t" << "price" << endl;
            for (auto&& element: it->second)
                cout << "\t" << element.units << "\t\t" << element.prices << endl;
        }
        cout << endl;
    }
private:
    string branch;
    mutable double revenue; /* We allow revenue is modifiable */
    map<string, vector<units_price>> db;

    void updateRevenue() const
    {
        revenue = 0;
        for (auto&& it = db.begin(); it != db.end(); it++)
        {
            for (auto&& element: it->second)
                revenue += static_cast<double>(element);
        }
    }
};

template <typename T>
int myCompare(const T& lhs,const T& rhs)
{
    if (lhs == rhs) return 0;

    return (lhs < rhs) ? 1 : -1;
}

int main(int argc, char **argv)
{

    SalesData bookstore1{"Store 1"};
    SalesData bookstore2{"Store 2"};
    SalesData bookstore3{"Store 3"};

    bookstore1.addSellingItem("1A", 3, 1.1);
    bookstore1.addSellingItem("1A", 6, 1.0);
    bookstore1.addSellingItem("1B", 2, 1.2);
    bookstore1.addSellingItem("1C", 2, 1.2);

    bookstore2.addSellingItem("1B", 3, 1.1);
    bookstore2.addSellingItem("1A", 2, 1.2);
    bookstore2.addSellingItem("1C", 2, 1.2);

    bookstore3.addSellingItem("1A", 3, 1.1);
    bookstore3.addSellingItem("1A", 6, 1.0);
    bookstore3.addSellingItem("1B", 2, 1.2);
    bookstore3.addSellingItem("1C", 2, 1.2);

    bookstore1.print();
    bookstore2.print();

    // cout << std::boolalpha << (bookstore1 < bookstore2) << endl;

    // compare we do on revenue only
    cout << "expectation  0 : " << myCompare<SalesData>(bookstore1, bookstore1) << endl;
    cout << "expectation -1 : " << myCompare<SalesData>(bookstore1, bookstore2) << endl;
    cout << "expectation  1 : " << myCompare<SalesData>(bookstore2, bookstore1) << endl;
    return 0;
}