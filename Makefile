  #the compiler: gcc for C program, define as g++ for C++
  CC = g++

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
  CFLAGS  = -g -Wall

  # the build target executable:
  TARGET = BankCluster3
  FILEMAIN = main.cpp
  CLASS = Information.cpp BankAccount.cpp BankClerk.cpp Customer.cpp UI.cpp MoneyExchange.cpp Statement.cpp

  all: 
	$(CC) $(FILEMAIN) $(CLASS) $(CFLAGS) -o $(TARGET)

  clean:
	rm $(TARGET)