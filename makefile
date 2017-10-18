all: frequencies huffman encode decode
		make clean

frequencies: frequencies.o
		g++ frequencies.o -o frequencies

frequencies.o: frequencies.cpp
		g++ -c -g frequencies.cpp

huffman: huffman.o
		g++ huffman.o -o huffman

huffman.o: huffman.cpp
		g++ -c -g huffman.cpp

encode: encode.o
		g++ encode.o -o encode

encode.o: encode.cpp
		g++ -c -g encode.cpp

decode: decode.o
		g++ decode.o -o decode

decode.o: decode.cpp
		g++ -c -g decode.cpp

		
clean:
		rm -f *.o