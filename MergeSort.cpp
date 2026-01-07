#include <iostream>
#include <string>
#include <vector>

using namespace std;


// void MergeSort() {
// 
// }


int main() {
    cout << "Sample Run" << endl;
    cout << "Given the array of values: [12, 8, 9, 3, 11, 5, 4], apply Merge Sort." << endl;
    vector<int> sampleRun = {12, 8, 9, 3, 11, 5, 4};
    vector<int> mainArr;
    vector<int> temp; // for temporary merging.
    
    for (int x: sampleRun) {
        mainArr.push_back(x);
    }
    
    
    
    return 0;
}