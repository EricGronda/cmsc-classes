CXX = g++
CXX_FLAGS = -ansi -Wall

lab9: Emp.o Manager.o Developer.o main.cpp
	$(CXX) $(CXX_FLAGS) Emp.o Manager.o Developer.o main.cpp -o lab9

Developer.o: Emp.h Emp.cpp Developer.h Developer.cpp
	$(CXX) $(CXX_FLAGS) -c Developer.cpp

Manager.o: Emp.h Emp.cpp Manager.h Manager.cpp
	$(CXX) $(CXX_FLAGS) -c Manager.cpp

Emp.o: Emp.h Emp.cpp
	$(CXX) $(CXX_FLAGS) -c Emp.cpp

run:
	./lab9

clean:
	rm *.o*
	rm *~