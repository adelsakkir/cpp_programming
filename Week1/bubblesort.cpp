// bubble sort - O(n**2)

#include<iostream>
using namespace std;


int main(void){
    int size;
    cout << "Enter the number of elements in the array" << endl;
    cin >> size ;

    int* arr = new int[size];
    // int arr[size];
    // vector<int> arr(size);

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

    int end = size -1;
    while (end >= 1){
        for (int i = 1; i < end+1; i++){
            if (arr[i] < arr[i-1]){
                int temp = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = temp;
            }
        }
        end--;
    }

    // int end = size -1;
    // while (end >= 1){
    //     for (int i = 1; i < end+1; i++){
    //         if (arr[i] < arr[i-1]){
    //             int temp = *(arr+i-1);
    //             arr[i-1] = *(arr+i);
    //             arr[i] = temp;
    //         }
    //     }
    //     end--;
    // }


    cout << "Sorted array: ";
    for (int i = 0; i < size; i++){
        
        cout << arr[i] << " ";
    }
    cout <<endl;
    delete[] arr; // delete if vector

    return 0;
}