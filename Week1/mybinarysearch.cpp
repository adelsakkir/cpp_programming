#include<iostream>
using namespace std;
#include <vector> 
#include <algorithm>

int mybinarysearch(vector<int> arr, int search_value, int start, int end){
    while(start <= end){
        int mid = (start+end) / 2;

        if (arr[mid] == search_value) {
            // cout << 1;
            return 1;}
        else if (arr[mid] > search_value){return mybinarysearch(arr, search_value, start, mid-1);}
        else {return mybinarysearch(arr, search_value, mid+1, end);}
    }
    return 0;

}

int main(void){
    int size;
    int search_value;
    cout << "Enter the number of elements in the array" << endl;
    cin >> size ;

    // vector<int> arr(size);
    int* arr = new int[size];

    cout << "Enter " << size << " elements: " << endl;
    for (int i = 0; i < size; i++){
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "You entered: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout <<endl;

    cout << "Enter a search value: " << endl;
    cin >> search_value;

    // cout << mybinarysearch(arr, search_value, 0, arr.size());
    // int found = mybinarysearch(arr, search_value, 0, arr.size());
    int found = binary_search(arr, arr + size, search_value);
    cout << "Found Status: " << found << endl;
    delete[] arr;
    return found;
}