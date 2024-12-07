import time

# Bubble Sort function for lists
def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

# Utility function to print a list
def print_array(arr):
    print(" ".join(map(str, arr)))

# Main program
if __name__ == "__main__":
    N = 10000  # Array size
    A = list(range(N, 0, -1))  # Fill array with numbers from 1000 to 1

    # print("Original array:")
    # print_array(A)  # Comment this if you don't want to print the original array

    # Start timing
    start_time = time.time()

    # Perform Bubble Sort
    bubble_sort(A)

    # End timing
    end_time = time.time()

    # Calculate and display elapsed time in microseconds
    elapsed_time = (end_time - start_time) *1000 
    print(f"Time taken to sort Python: {elapsed_time:.6f} milliseconds")

    # print("Sorted array:")
    # print_array(A)  # Comment this if you don't want to print the sorted array
