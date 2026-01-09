#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool sortCheck(vector<int>& mainArr, string order) {
    if (mainArr.size() < 2) return true; 
    for (size_t i = 0; i < mainArr.size() - 1; i++) {
        if (order == "ascending" && mainArr[i] > mainArr[i + 1]) return false;
        if (order == "descending" && mainArr[i] < mainArr[i + 1]) return false;
    }
    return true;
}

void print(vector<int>& mainArr, string order) {
    cout << "\nSorted array (" << order << "): ";
    for (size_t i = 0; i < mainArr.size(); i++) {
        cout << mainArr[i];
        if (i != mainArr.size() - 1) cout << ", ";
    }
    cout << endl;
}

void QuickSort(vector<int>& mainArr, string order) {
    if (mainArr.size() < 2 || sortCheck(mainArr, order)) return;

    size_t pivotIndex = mainArr.size() / 2;
    int pivot = mainArr[pivotIndex];

    vector<int> left;
    vector<int> right;

    for (size_t i = 0; i < mainArr.size(); i++) {
        if (i == pivotIndex) continue; 
        if ((order == "ascending" && mainArr[i] < pivot) || 
            (order == "descending" && mainArr[i] > pivot)) {
            left.push_back(mainArr[i]);
        } else {
            right.push_back(mainArr[i]);
        }
    }

    QuickSort(left, order);
    QuickSort(right, order);

    size_t index = 0;
    for (size_t i = 0; i < left.size(); i++) mainArr[index++] = left[i];
    mainArr[index++] = pivot;
    for (size_t i = 0; i < right.size(); i++) mainArr[index++] = right[i];
}

int main() {
    cout << "Sample Run" << endl;
    cout << "Given the array of values: [12, 8, 9, 3, 11, 5, 4], apply Quick Sort (ascending form)." << endl;
    vector<int> sampleRun = {12, 8, 9, 3, 11, 5, 4};
    
    vector<int> mainArr;
    string order = "descending"; 
    
    for (int x: sampleRun) {
        mainArr.push_back(x); 
    }
    
    QuickSort(mainArr,order);
    print(mainArr, order);

    cout << "\n\n--------------------------------------------\n\n" << "Try it." << endl;
    cout << "Give me values to sort (unsorted):   [-1 to stop]" << endl;
    int values;
    while (true) {
        if (values == -1) {values=0; break;}
        cin >> values; 
        mainArr.push_back(values);
    }
    cout << "Ascending or Descending order? " << endl;

    QuickSort(mainArr, order);
    print(mainArr,order);

    return 0;
}
