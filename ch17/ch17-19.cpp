#include <bits/stdc++.h>

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include <regex>
using std::regex;
using std::sregex_iterator;
using std::smatch;


using namespace std;

/*
 *
 *  Exercise 17.1: 
 * 
 */


bool valid(const smatch& m);

int main()
{
	string phone = "(\\()?(\\d{ 3 })(\\))?([-. ])?(\\d{ 3 })([-. ]?)(\\d{ 4 })";
    try
    {
        regex r(phone);
       	smatch m;
        string s;
        bool valid_record;
        // read each record from the input file
        while (getline(cin, s))
        {
            valid_record = false;
            // for each matching phone number
            for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it)
            {
                valid_record = true;
                // check whether the number's formatting is valid
                if (valid(*it))
                    cout << "valid phone number: " << it->str() << endl;
                else
                    cout << "invalid phone number: " << it->str() << endl;
            }

            if (!valid_record)
                cout << "invalid record!" << endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
	

	return 0;
}

bool valid(const smatch& m)
{
	// if there is an open parenthesis before the area code
	if (m[1].matched)
		// the area code must be followed by a close parenthesis
		// and followed immediately by the rest of the number or a space
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	else
		// then there can't be a close after the area code
		// the delimiters between the other two components must match
		return !m[3].matched && m[4].str() == m[6].str();
}