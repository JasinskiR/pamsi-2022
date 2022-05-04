CXXFLAGS=-g -Iinc -Isrc -Ifml -Wall -pedantic -std=c++17

# __start__: MessagesP
# 	./MessagesP

Ranking: obj obj/main.o obj/Data.o obj/QuickSort.o obj/Film.o obj/BinSort.o obj/MergeSort.o
	g++ -Wall -pedantic -std=c++0x -o Ranking obj/main.o obj/Data.o obj/QuickSort.o obj/Film.o obj/BinSort.o obj/MergeSort.o

obj:
	mkdir obj

obj/main.o: src/main.cpp inc/Data.hpp inc/QuickSort.hpp inc/BinSort.hpp inc/MergeSort.hpp
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp 

obj/Data.o: src/Data.cpp inc/Data.hpp
	g++ -c ${CXXFLAGS} -o obj/Data.o src/Data.cpp

obj/QuickSort.o: src/QuickSort.cpp inc/QuickSort.hpp
	g++ -c ${CXXFLAGS} -o obj/QuickSort.o src/QuickSort.cpp

obj/Film.o: src/Film.cpp inc/Film.hpp
	g++ -c ${CXXFLAGS} -o obj/Film.o src/Film.cpp

obj/BinSort.o: src/BinSort.cpp inc/BinSort.hpp
	g++ -c ${CXXFLAGS} -o obj/BinSort.o src/BinSort.cpp	

obj/MergeSort.o: src/MergeSort.cpp inc/MergeSort.hpp
	g++ -c ${CXXFLAGS} -o obj/MergeSort.o src/MergeSort.cpp

clean:
	rm -f obj/*.o MessagesP