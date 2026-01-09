#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print (vector<int>&mainArr, string order) {
    cout << "\nSorted array (" << order << "): ";
        for (int x : mainArr) {
            if (x == mainArr[mainArr.size()-1]) {
                cout << x;
                break;
            }
            cout << x << ", ";
        };
    cout << endl;
}

void merge(vector<int>& mainArr, vector<int>& left, vector<int>& right, string order) {
    int i = 0, j = 0, k = 0;

    while (i < left.size() && j < right.size()) {
        if (order == "ascending") {
            if (left[i] <= right[j]) {
                mainArr[k++] = left[i++];
            } else {
                mainArr[k++] = right[j++];
            }
        } else { 
            if (left[i] >= right[j]) {
                mainArr[k++] = left[i++];
            } else {
                mainArr[k++] = right[j++];
            }
        }
    }

    while (i < left.size()) mainArr[k++] = left[i++];
    while (j < right.size()) mainArr[k++] = right[j++];
}


void MergeSort(vector<int>& mainArr, string order) {
    if (mainArr.size() <= 1) return;

    int mid = mainArr.size()/2;
    vector<int> left(mainArr.begin(), mainArr.begin() + mid);
    vector<int> right(mainArr.begin() + mid, mainArr.end());

    MergeSort(left, order);
    MergeSort(right, order);

    merge(mainArr, left, right, order);
}

int main() {
    cout << "Sample Run" << endl;
    cout << "Given the array of values: [12, 8, 9, 3, 11, 5, 4], apply Merge Sort (ascending form)." << endl;
    vector<int> sampleRun = {12, 8, 9, 3, 11, 5, 4};

    vector<int> mainArr;
    string order = "descending"; // sorting order 

    for (int x: sampleRun) {
        mainArr.push_back(x); 
    }
    MergeSort(mainArr, order);
    print(mainArr,order);

    mainArr.clear();

    cout << "\n\n--------------------------------------------\n\n" << "Try it." << endl;
    cout << "Give me values to sort (unsorted):   [-1 to stop]" << endl;
    int values;
    while (true) {
        if (values == -1) {values=0; break;}
        cin >> values; 
        mainArr.push_back(values);
    }
    cout << "Ascending or Descending order? " << endl;

    MergeSort(mainArr, order);

    print(mainArr,order);
    // cout << "\nSorted array (" << order << "): ";
    // for (int x : mainArr) {
    //     if (x == mainArr[mainArr.size()-1]) {
    //         cout << x;
    //         break;
    //     }
    //     cout << x << ", ";
    // };
    // cout << endl;

    return 0;
}