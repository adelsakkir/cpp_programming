import ctypes
import numpy as np

# Load the shared library
bubble_sort_lib = ctypes.CDLL('./export_sort.dll')  # Use 'bubble_sort.dll' on Windows

# Define argument and return types for the function
bubble_sort_lib.bubble_sort.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
bubble_sort_lib.bubble_sort.restype = None

bubble_sort_lib.measure_bubble_sort_time.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
bubble_sort_lib.measure_bubble_sort_time.restype = ctypes.c_longlong

# Create an array and call the function
array = np.array([10, 9, 8, 7, 6, 5, 4, 3, 2, 1], dtype=np.int32)
size = len(array)

# Measure time
time_taken = bubble_sort_lib.measure_bubble_sort_time(array.ctypes.data_as(ctypes.POINTER(ctypes.c_int)), size)
print(f"Time taken to sort: {time_taken} milliseconds")

# Print the sorted array
print("Sorted array:", array)
