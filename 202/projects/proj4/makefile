CXX = g++
CXX_FLAGS = -Wall

proj4: MailHouse.o driver.cpp
	$(CXX) $(CXX_FLAGS) MailHouse.o Ups.o FedEx.o Carrier.o Package.o Letter.o Mail.o driver.cpp -o proj4

MailHouse.o: MailHouse.h MailHouse.cpp Ups.o FedEx.o Carrier.o Package.o Letter.o
	$(CXX) $(CXX_FLAGS) -c MailHouse.cpp

Ups.o: Ups.h Ups.cpp Carrier.o
	$(CXX) $(CXX_FLAGS) -c Ups.cpp

FedEx.o: FedEx.h FedEx.cpp Carrier.o
	$(CXX) $(CXX_FLAGS) -c FedEx.cpp

Carrier.o: Carrier.h Carrier.cpp Mail.o
	$(CXX) $(CXX_FLAGS) -c Carrier.cpp

Package.o: Package.h Package.cpp Mail.o
	$(CXX) $(CXX_FLAGS) -c Package.cpp

Letter.o: Letter.h Letter.cpp Mail.o
	$(CXX) $(CXX_FLAGS) -c Letter.cpp

Mail.o: Mail.h Mail.cpp
	$(CXX) $(CXX_FLAGS) -c Mail.cpp

clean:
	rm *.o*
	rm *~

run:
	./proj4

run1:
	./proj4 proj4_t1.txt

run2:
	./proj4 proj4_t2.txt

run3:
	./proj4 proj4_t3.txt

run4:
	./proj4 proj4_t4.txt

val1:
	valgrind ./proj4 proj4_t1.txt

val2:
	valgrind ./proj4 proj4_t2.txt

val3:
	valgrind ./proj4 proj4_t3.txt

val4:
	valgrind ./proj4 proj4_t4.txt
