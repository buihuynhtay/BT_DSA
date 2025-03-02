#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define all(x) x.begin(), x.end()
#define ll long long
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

vector<int> readFile(const string& filename) {
    ifstream file(filename);
    vector<int> data;
    int value;

    if (file.is_open()) {
        while (file >> value) {
            data.push_back(value);
        }
        file.close();
    } else {
        cerr << "Unable to open file " << filename << endl;
    }

    return data;
}



int main() {
    vector<string> filenames;
    for (int i = 1; i <= 10; ++i) {
        filenames.push_back("test" + to_string(i) + ".inp");
    }

    for (const string& filename : filenames) {
        // cout << "Processing file: " << filename << endl;

        vector<int> data = readFile(filename);

        
        auto start = high_resolution_clock::now();
        sort(data.begin(), data.end());
        auto end = high_resolution_clock::now();

        cout << duration_cast<milliseconds>(end - start).count() << '\n';
        // cout << " ms\n";
    }

    return 0;
}