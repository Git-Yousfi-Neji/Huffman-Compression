# Huffman Compression Algorithm

**This project is an implementation of the Huffman compression algorithm in C++. The Huffman algorithm is a lossless data compression algorithm that uses variable-length coding to compress data.**

## Requirements

- C++11 or later
- GNU Make

## Usage

To compile the project, run the following command:

```
make 
```
This will create an executable file named main in the bin directory. 

To clean the project, run the following command:

```
make clean
```

To run the program, use the following command:

```
./bin/main -c < input.txt >
```

This will compress the text in input.txt and write the compressed data to output.bin.

To decompress the data, use the following command:

```
./bin/main -d < output.bin >
```

This will decompress the data in output.bin and write the decompressed text to output.txt.

The project directory is structured as follows:

```
Huffman-Compression/
├── Makefile
├── README.md
├── bin/
│   └── main
├── include/
│   └── huffman.h
├── input.txt
├── obj/
│   ├── huffman.o
│   └── main.o
├── src/
│   └── huffman.cpp
└── tests/
    ├── input1.txt
    ├── input2.txt
    ├── output1.bin
    ├── output2.bin
    ├── output3.txt
    ├── output4.txt
    └── test.cpp

```

- bin: Contains the executable files.

- include: Contains the header files.

- obj: Contains the object files.

- src: Contains the source files.

- tests: Contains the test files.

- Makefile: Defines the build instructions.

- README.md: Provides information about the project.

## License

This project is licensed under the [MIT License](https://en.m.wikipedia.org/wiki/MIT_License ). See the LICENSE file for details.

## References

- [Huffman coding - Wikipedia](https://en.m.wikipedia.org/wiki/Huffman_coding)

- [Data Compression With Huffman Coding](https://freecontent.manning.com/data-compression-with-huffmans-algorithm/)

- [Huffman Coding | Greedy Algo-3](https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/?)