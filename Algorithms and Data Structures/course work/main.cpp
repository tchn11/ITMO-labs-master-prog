#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <time.h>
#include <chrono>
#include <iomanip>


using namespace std;

vector<int> naive_string_matcher(const string& text, const string& pattern)
{
    vector<int> matches;
    int n = text.size();
    int m = pattern.size();

    if (m == 0 || n < m) return matches;

    for (int i = 0; i <= n - m; ++i) 
    {
        int j;
        for (j = 0; j < m; ++j) 
        {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
            matches.push_back(i);
    }
    return matches;
}

vector<int> rabin_karp_matcher(const string& text, const string& pattern) 
{
    vector<int> matches;
    int n = text.size();
    int m = pattern.size();
    if (m == 0 || n < m) return matches;

    const int base = 256;
    const int q = 1e9 + 7;

    long long h = 1;
    for (int i = 0; i < m - 1; i++)
        h = (h * base) % q;

    long long hash_pat = 0, hash_text = 0;
    for (int i = 0; i < m; i++) {
        hash_pat = (hash_pat * base + static_cast<unsigned char>(pattern[i])) % q;
        hash_text = (hash_text * base + static_cast<unsigned char>(text[i])) % q;
    }

    for (int i = 0; i <= n - m; i++) 
    {
        if (hash_pat == hash_text) 
        {
            bool match = true;
            for (int j = 0; j < m; j++) 
            {
                if (static_cast<unsigned char>(text[i + j]) != static_cast<unsigned char>(pattern[j])) 
                {
                    match = false;
                    break;
                }
            }
            if (match)
                matches.push_back(i);
        }

        if (i < n - m) {
            hash_text = (base * (hash_text - static_cast<unsigned char>(text[i]) * h) + static_cast<unsigned char>(text[i + m]));
            hash_text %= q;
            if (hash_text < 0)
                hash_text += q;
        }
    }

    return matches;
}

vector<int> prefix_function(string s)
{
    int n = s.size();
    vector<int> pi(n, 0);
    int k = 0;

    for (int i = 1; i < n; i++)
    {
        while (k > 0 && s[i] != s[k])
            k = pi[k - 1];
        if (s[i] == s[k])
            k++;
        pi[i] = k;
    }
    return pi;
}

vector<int> KMP_matcher(string& text, string& pattern)
{
    vector<int> matches;
    int n = text.size();
    int m = pattern.size();

    if (m == 0 || n < m) return matches;

    vector<int> prefix = prefix_function(pattern);

    int j = 0;
    for (int i = 0; i < n; ++i) 
    {
        while (j > 0 && text[i] != pattern[j])
            j = prefix[j-1];

        if (text[i] == pattern[j])
            ++j;

        if (j == m) {
            matches.push_back(i - m + 1);
            j = prefix[j-1];
        }
    }

    return matches;
}

void getExecutionTime(time_t start, time_t end)
{
    double seconds = difftime(end, start);
    cout << "Execution time " << seconds << " seconds" << endl;
}

int main()
{
    string pattern;
    int number_of_alg;
    char temp;
    ifstream file("input.txt");

    if(!file)
    {
        cerr << "The file doesn't exist!" << endl;
        return 1;
    }

    if (!file.is_open())
    {
        cerr << "File read error!" << endl;
        return 1;
    }

    stringstream buffer;
    buffer << file.rdbuf();

    string s = buffer.str();
    file.close();

    cout << "Enter the substring you are looking for: ";
    getline(cin, pattern);

    cout << "Enter the number of the algorithm: 0 - naive, 1 - Rabin-Karp, 2 - KMP: ";
    cin >> number_of_alg;

    vector<int> result;

    auto start_time = chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count();

    switch (number_of_alg)
    {
    case 0:
        result = naive_string_matcher(s, pattern);
        break;
    case 1:
        result = rabin_karp_matcher(s, pattern);
        break;
    case 2:
        result = KMP_matcher(s, pattern);
        break;
    default:
        break;
    }

    auto end_time = chrono::duration_cast<chrono::seconds>(chrono::system_clock::now().time_since_epoch()).count();

    cout << result.size() << endl;
    for (int num : result)
        cout << num << " ";

    cout << endl;
    cout << setprecision(2) << "Running time of algorithm: " << (start_time - end_time)/1000.0 << "ms.";
}
