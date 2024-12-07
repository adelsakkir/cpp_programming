#include <iostream>
using namespace std;

class IntContainer{
    private:
        int* data;
        size_t size;

    public:
        IntContainer(size_t size) : size(size){
            data = new int[size];
            for (size_t i =0; i <size;i++){
                data[i] = i+1;
            }
        }

        ~IntContainer(){
            delete[] data;
        }

        size_t getSize() const {
            return size;
        }

        class Iterator{
            private:
                int *ptr;   // pointer to current element in the container

            public:
                Iterator(int*p) : ptr(p) {}

                int& operator*() {
                    return *ptr;
                }

                // Overload pre-increment operator (++iter)
                Iterator& operator++() {
                    ++ptr;
                    return *this;

                };
                bool operator==(const Iterator& other) const {
                    return ptr == other.ptr;
                }

                // Overload inequality operator to compare iterators
                bool operator!=(const Iterator& other) const {
                    return ptr != other.ptr;
                }

        };

        Iterator begin() {
            return Iterator(data);
        }

        Iterator end() {
            return Iterator(data + size);
        }
};

template<class T1, class T2>
bool find(T1 arr, T2 search_val){
    for (typename T1::Iterator it = arr.begin(); it != arr.end(); ++it) {
        if (*it== search_val){
            return true;
        }
    }
    return false;
}

int main() {
    IntContainer container(5);  // Create a container with 5 elements

    // Use the custom iterator to traverse and print elements
    for (IntContainer::Iterator it = container.begin(); it != container.end(); ++it) {
        cout << *it << " ";
    }

    int out = find<IntContainer, int>(container, 7);
    cout << "Search Log: " << out << endl;

    return 0;
}