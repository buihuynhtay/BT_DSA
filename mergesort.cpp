#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define all(x) x.begin(), x.end()
#define ll long long
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
long long R(long long l, long long r) {
    return l + rd() % (r - l + 1);
}

void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;


    vector<int> L(n1), R(n2);

   
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
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
        mergeSort(data, 0, data.size() - 1);
        auto end = high_resolution_clock::now();

        cout << duration_cast<milliseconds>(end - start).count() << '\n';
        // cout << " ms\n";
    }

    return 0;
}
