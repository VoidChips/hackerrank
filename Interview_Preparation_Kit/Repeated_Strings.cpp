#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long repeatedString(string s, long n)
{
    long countOfA{};
    long origCountOfA{};
    long sLen{static_cast<long>(s.length())};
    long remainder{n % sLen};
    vector<long> indexOfA;

    for (long i{}; i < s.length(); i++)
    {
        if (s[i] == 'a')
        {
            origCountOfA++;
            indexOfA.push_back(i);
        }
    }

    if (origCountOfA == 0)
    {
        return 0;
    }

    // cout << "original count of a: " << origCountOfA << endl;
    // cout << "remainder: " << remainder << endl;

    countOfA = origCountOfA * (n / sLen);

    if (remainder == 0)
    {
        return countOfA;
    }

    for (long i{}; i < remainder; i++)
    {
        if (count(indexOfA.begin(), indexOfA.end(), i) == 1)
        {
            countOfA++;
        }
    }

    return countOfA;
}

int main()
{
    cout << repeatedString("abcac", 10) << endl;
    cout << repeatedString("aba", 10) << endl;
    cout << repeatedString("a", 1000000000000) << endl;
    cout << repeatedString("gfcaaaecbg", 547602) << endl;
    cout << repeatedString("jdiacikk", 899491) << endl;
    cout << repeatedString("epsxyyflvrrrxzvnoenvpegvuonodjoxfwdmcvwctmekpsnamchznsoxaklzjgrqruyzavshfbmuhdwwmpbkwcuomqhiyvuztwvq", 549382313570) << endl;
    return 0;
}