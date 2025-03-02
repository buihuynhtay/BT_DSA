import os
import time
import numpy as np

def read_input_file(file_path):
    with open(file_path, 'r') as file:
        data = file.read().strip().split()
    return [int(x) for x in data]

def main():
    
    input_files = [os.path.join( f'test{i}.inp') for i in range(1, 11)]

    for file_path in input_files:
        arr = read_input_file(file_path)
        arr = np.array(arr)

        start = time.time()
        np.sort(arr)
        end = time.time()

        print(f"{(end - start) * 1000} ms")

if __name__ == "__main__":
    main()