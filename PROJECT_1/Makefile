CXXFLAGS=-g -Iinc -Isrc -Ifml -Wall -pedantic -std=c++17

# __start__: MessagesP
# 	./MessagesP

MessagesP: obj obj/main.o obj/Packets.o obj/Tree.o obj/Heap.o
	g++ -Wall -pedantic -std=c++0x -o MessagesP obj/main.o obj/Packets.o obj/Tree.o obj/Heap.o

obj:
	mkdir obj

obj/main.o: src/main.cpp inc/Packets.hpp inc/Tree.hpp inc/Heap.hpp
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Packets.o: src/Packets.cpp inc/Packets.hpp
	g++ -c ${CXXFLAGS} -o obj/Packets.o src/Packets.cpp

obj/Tree.o: src/Tree.cpp inc/Tree.hpp fml/Tree.tpp
	g++ -c ${CXXFLAGS} -o obj/Tree.o src/Tree.cpp

obj/Heap.o: src/Heap.cpp inc/Heap.hpp fml/Heap.tpp
	g++ -c ${CXXFLAGS} -o obj/Heap.o src/Heap.cpp

clean:
	rm -f obj/*.o MessagesP