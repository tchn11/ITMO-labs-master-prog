#include <string>
#include <iostream>
#include <vector>

using namespace std;

int parse_pol(vector<string>& words, int* iter)
{
    string op = words[*iter];

    *iter = *iter - 1;

    switch (op[0])
    {
    case '+':
        return parse_pol(words, iter) + parse_pol(words, iter);
    case '-':
        {
            int res1 = parse_pol(words, iter);
            int res2 = parse_pol(words, iter);
            return res2 - res1;

        }
    case '*':
        return parse_pol(words, iter) * parse_pol(words, iter);
    default:
        return stoi(op);
    }
}

int main()
{
    vector<string> words;

    string tmp;

    while (cin >> tmp)
        words.push_back(tmp);

    int iter = words.size() - 1;

    cout << parse_pol(words, &iter);

    return 0;
}
