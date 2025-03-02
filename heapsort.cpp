#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define all(x) x.begin(), x.end()
#define ll long long
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
long long R(long long l, long long r) {
    return l + rd() % (r - l + 1);
}

void heapify(vector<int>& arr, int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;


    if (l < n && arr[l] > arr[largest])
        largest = l;


    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr){
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


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
        heapSort(data);
        auto end = high_resolution_clock::now();

        cout << duration_cast<milliseconds>(end - start).count() << '\n';
        // cout << " ms\n";
    }

    return 0;
}
