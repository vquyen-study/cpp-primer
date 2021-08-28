#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 17.9: Explain the bit pattern each of the following bitset objects contains:
 * 
 *  (a) bitset<64> bitvec(32);                          ==>     64 bits, lower-order 6 bits are 100000, remaining bits are 0
 *  (b) bitset<32> bv(1010101);                         ==>     1010101(Decima) = 00000000000011110110100110110101 ( binary)
 *  (c) string bstr; cin >> bstr; bitset<8> bv(bstr);   ==>     depends on what user has been input.
 * 
 *  Exercise 17.10: Using the sequence 1, 2, 3, 5, 8, 13, 21, initialize a bitset that has a 1 bit in each position corresponding to a number 
 *  in this sequence. Default initialize another bitset and write a small program to turn on each of the appropriate bits.
 * 
 *  Exercise 17.11: Define a data structure that contains an integral object to track responses to a true/false quiz containing 10 questions. 
 *  What changes, if any, would you need to make in your data structure if the quiz had 100 questions?
 * 
 */

/*  Exercise 17.10:     */
void bitset_sequence(void)
{
    bitset<32> b_seq = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 8) | (1 << 13) | (1 << 21);
    cout << "bit set on (1, 2, 3, 5, 8, 13, 21) is " << b_seq << endl;
}

/*  Exercise 17.11     */
template <size_t BS_SIZE>
struct TrackQuiz
{
    bitset<BS_SIZE> b_track_quizz;

    void set(size_t pos)
    {
        assert(BS_SIZE > pos);
        b_track_quizz.set(pos);
    }

    void clear(size_t pos)
    {
        assert(BS_SIZE > pos);
        b_track_quizz.reset(pos);
    }

    friend ostream& operator<<(ostream& os, const TrackQuiz& obj)
    {
        cout << obj.b_track_quizz;
        return os;
    }

    TrackQuiz() = default;
    ~TrackQuiz() = default;
};

int main(int argc, char **argv)
{
    ostringstream oss;
    cout << "Hello ex-ch17-09" << endl;

    bitset_sequence();

    /*  Exercise 17.11     */
    TrackQuiz<10> tq;
    tq.set(1);
    tq.set(2);
    tq.set(6);
    // tq.set(22);          /*  Fail to set this value. */
    cout << tq << endl;

    TrackQuiz<100> tq1;
    tq1.set(1);
    tq1.set(2);
    tq1.set(6);
    tq1.set(22);
    cout << tq1 << endl;

    return 0;
}