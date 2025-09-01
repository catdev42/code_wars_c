#include <deque>
#include <cctype>
#include <exception>
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;
// no checked for bad input

// 7789 77

class bigint
{
public:
    bigint() {}
    bigint(unsigned int n)
    {
        while (n > 0)
        {
            num.push_front(n % 10);
            n = n / 10;
        }
    }
    bigint(string strnum)
    {
        for (size_t i = 0; i < strnum.size(); i++)
        {
            if (strnum[i] < '0' && strnum[i] > '9')
                throw runtime_error("Not a digit");
            num.push_back(strnum[i] - '0');
        }
    }
    bigint(const bigint &other) : num(other.num) {}
    ~bigint() {}

    deque<int> getNum() const
    {
        return num;
    }

    bool operator>(const bigint &other) const
    {
        return this->num > other.num;
    }

    bool operator<(const bigint &other) const
    {
        return this->num < other.num;
    }

    bool operator==(const bigint &other) const
    {
        return this->num == other.num;
    }
    bool operator!=(const bigint &other) const
    {
        return !(this->num == other.num);
    }

    bool operator>=(const bigint &other) const
    {
        return !(operator<(other));
    }
    bool operator<=(const bigint &other) const
    {
        return !(operator>(other));
    }

    bigint operator+(const bigint &other) const
    {
        bigint ret = *this;

        deque<int> otherNum = other.num;

        int i = num.size() - 1;
        int j = otherNum.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0)
        {
            int a = 0;
            int b = 0;
            int result = 0;

            if (i >= 0)
                a = num[i];
            if (j >= 0)
                b = otherNum[j];
            if (carry == 1)
                a = a + 1;

            if ((a + b) > 9)
                carry = 1;
            else
                carry = 0;

            result = (a + b) % 10; // ex: (9 + 8 )% 10 = 5 //757
            ret.num.push_front(result);
            i--;
            j--;
        }
        return ret;
    }

private:
    deque<int> num;
};

ostream &operator<<(ostream &o, const bigint &infile)
{
    deque<int> num = infile.getNum();
    for (deque<int>::const_iterator it = num.begin(); it != num.end(); it++)
        o << *it;
    return o;
}
