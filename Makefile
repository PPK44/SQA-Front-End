all: auction-system.exe auction-system.cpp Users.cpp Admin.cpp Advertise.cpp Bid.cpp Items.cpp AuctionLib.cpp

auction-system.exe: auction-system.o Users.o Admin.o Advertise.o Bid.o Items.o Writer.o AuctionLib.o
	 g++ -o auction-system.exe auction-system.o Users.o Admin.o Advertise.o Bid.o Items.o Writer.o AuctionLib.o

auction-system.cpp: auction-system.cpp
	 g++ -c auction-system.cpp

Users.cpp: Users.cpp
	 g++ -c Users.cpp

Admin.cpp: Admin.cpp
	 g++ -c Admin.cpp	

Advertise.cpp: Advertise.cpp
	 g++ -c Advertise.cpp 

Bid.cpp: Bid.cpp
	 g++ -c Bid.cpp

Items.cpp: Items.cpp
	 g++ -c Items.cpp

Writer.cpp: Writer.cpp
	 g++ -c Writer.cpp	  

AuctionLib.cpp: AuctionLib.cpp
	 g++ -c AuctionLib.cpp	  
     
clean:
	 del auction-system.o auction-system.exe Users.o Admin.o Advertise.o Bid.o Items.o Writer.o	AuctionLib.o
