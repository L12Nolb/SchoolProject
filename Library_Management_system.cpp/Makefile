CFLAGS =-stdlib=libc++ -std=c++11 -g -Wall
library: main.o Book.o AudioCD.o DVD.o LibraryItem.o LibraryItems.o Patron.o Patrons.o Loan.o Loans.o
	g++ main.o Book.o AudioCD.o DVD.o LibraryItem.o LibraryItems.o Patron.o Patrons.o Loan.o Loans.o -o library
	
main.o: main.cpp Patron.h Patrons.h Book.h AudioCD.h DVD.h LibraryItem.h LibraryItems.h Loan.h Loans.h
	g++ $(CFLAGS) -c main.cpp
	
Book.o: Book.cpp Book.h
	g++ $(CFLAGS) -c Book.cpp

AudioCD.o: AudioCD.cpp AudioCD.h
	g++ $(CFLAGS) -c AudioCD.cpp
	
DVD.o: DVD.cpp DVD.h
	g++ $(CFLAGS) -c DVD.cpp
	
LibraryItem.o: LibraryItem.cpp LibraryItem.h
	g++ $(CFLAGS) -c LibraryItem.cpp
	
LibraryItems.o: LibraryItems.cpp LibraryItems.h
	g++ $(CFLAGS) -c LibraryItems.cpp
	
Patron.o: Patron.cpp Patron.h
	g++ $(CFLAGS) -c Patron.cpp
	
Patrons.o: Patrons.cpp Patrons.h
	g++ $(CFLAGS) -c Patrons.cpp
	
Loan.o: Loan.cpp Loan.h
	g++ $(CFLAGS) -c Loan.cpp
	
Loans.o: Loans.cpp Loans.h
	g++ $(CFLAGS) -c Loans.cpp
	
clean:
	rm *.o library

