import time  # Import the time module

def main():
    n = 0

    # Start timing
    start_time = time.time()

    # Your original loop
    while n < 1000000000:
        n += 1

    # Stop timing
    end_time = time.time()

    # Calculate the elapsed time
    elapsed_time = end_time - start_time

    # Output the elapsed time
    print(f"Elapsed time: {elapsed_time:.6f} seconds")
    print("Done!")

if __name__ == "__main__":
    main()
