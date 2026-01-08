#include <iostream>
#include <string>
#include <vector>

using namespace std;

void merge()

void MergeSort(vector<int> mainArr, string order) {
    if (mainArr.size<=1) { // basically base casing case
        return mainArr;
    } 
    int mid = mainArr.size()/2;
    int lefty = mainArr[mid];
    return merge(mainArr, order);
}


int main() {
    cout << "Sample Run" << endl;
    cout << "Given the array of values: [12, 8, 9, 3, 11, 5, 4], apply Merge Sort (ascending form)." << endl;
    vector<int> sampleRun = {12, 8, 9, 3, 11, 5, 4};

    vector<int> mainArr;
    vector<int> temp; // for temporary merging.
    string order = "ascending"; // sorting order 

    for (int x: sampleRun) {
        mainArr.push_back(x); 
    }
    int start = mainArr[0];
    int mid = mainArr.size(2);
    MergeSort(mainArr, temp, order);
    
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

    MergeSort(mainArr, temp, order);

    return 0;
}