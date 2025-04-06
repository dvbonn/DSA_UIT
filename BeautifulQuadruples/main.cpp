#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the beautifulQuadruples function below.
 */
int beautifulQuadruples(int a, int b, int c, int d) {
    map<int, int> xorFreq;
    int total = 0;

    // Loop 1: Calculate XOR frequencies and total count
    for (int i = 1; i <= c; ++i) {
        for (int j = i; j <= d; ++j) {
            xorFreq[i ^ j]++;
            total++;
        }
    }

    long long result = 0;

    // Loop 2: Calculate the result
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            // Decrease frequency and total count
            xorFreq[i ^ j]--;
            total--;

            // Iterate through all values of c and d
            for (int k = 1; k <= c; ++k) {
                for (int l = 1; l <= d; ++l) {
                    // Increment result by total - frequency
                    result += total - xorFreq[i ^ j];
                }
            }

            // Restore frequency and total count
            xorFreq[i ^ j]++;
            total++;
        }
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string abcd_temp;
    getline(cin, abcd_temp);

    vector<string> abcd = split_string(abcd_temp);

    int a = stoi(abcd[0]);

    int b = stoi(abcd[1]);

    int c = stoi(abcd[2]);

    int d = stoi(abcd[3]);

    int result = beautifulQuadruples(a, b, c, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
