CXX = g++
CXXFLAGS = -Wall

lab7: Gemstone.o lab7.cpp
	$(CXX) $(CXXFLAGS) Gemstone.o lab7.cpp -o lab7
Gemstone.o: Gemstone.cpp Gemstone.h
	$(CXX) $(CXXFLAGS) -c Gemstone.cpp
clean:
	rm *.o
	rm *~
run:
	./lab7