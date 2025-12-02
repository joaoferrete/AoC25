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

bool hasRepeatedSequence(long long num) {
    string s = to_string(num);
    string act = "";
    for (long long i = 0; i < s.size(); ++i) {
        if (act.empty()) {
            act += s[i];
            continue;
        } 
        for (long long j = 0; j < s.size(); j += act.size()) {
            if (s.substr(j, act.size()) != act) {
                act += s[i];
                break;
            }
            if (j + act.size() >= s.size()) 
                return true;
        }
    }
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
            if (hasRepeatedSequence(num)) {
                result+=num;
                cout << "invalid: " << num << endl;
            }
        }
    }
    cout << "Result: " << result << endl;

    return 0;
}
