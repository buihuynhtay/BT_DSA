#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define all(x) x.begin(), x.end()
#define ll long long
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
long long R(long long l, long long r) {
    return l + rd() % (r - l + 1);
}

int partition(vector<int> &arr, int low, int high) {
   
    int random_index = low + rd() % (high - low + 1);
    swap(arr[random_index], arr[high]);

    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
        quickSort(data, 0, data.size() - 1);
        auto end = high_resolution_clock::now();

        cout << duration_cast<milliseconds>(end - start).count() << '\n';
        // cout << " ms\n";
    }

    return 0;
}