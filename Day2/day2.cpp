#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

bool isRepeatedTwice(long long num) {
    string s = to_string(num);
    if (s.size() % 2 != 0) return false;

    if (s.substr(0, s.size() / 2) == s.substr(s.size() / 2, s.size())) 
        return true;
    return false;
}

int main() {
    string str;
    cin >> str;
    vector<string> ranges = split(str, ',');
    long long result = 0;

    for (const string &range : ranges) {
        vector<string> bounds = split(range, '-');
        long long lower = stoll(bounds[0]);
        long long upper = stoll(bounds[1]);
        
        for (long long num = lower; num <= upper; ++num) {
            if (isRepeatedTwice(num)) {
                result+=num;
                cout << "invalid: " << num << endl;
            }
        }
    }
    cout << "Result: " << result << endl;

    return 0;
}
