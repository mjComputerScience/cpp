.SUFFIXES : .cpp .o

OBJECTS = MyList.o\
		  UserData.o\
		  UserInterface.o\
		  AddressBook_OOP.o
SRCS = $(OBJECTS:.o=.cpp)

CXXFLAGS = -g -c -std=c++11

TARGET = lab

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS); ./$(TARGET)

.cpp.o :
	$(CXX) $(CXXFLAGS) $<

clean : 
	rm $(OBJECTS)

# CMyString.o : CMyString.h CMyString.cpp
# StringCtrlSample.o : CMyString.h StringCtrlSample.cpp


dep : 
	g++ -M $(SRCS)
