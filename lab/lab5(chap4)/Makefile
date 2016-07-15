.SUFFIXES : .cpp .o

OBJECTS = MyString.o\
		  StringCtrlSample.o
SRCS = $(OBJECTS:.o=.cpp)

CXXFLAGS = -g -c -std=c++11

TARGET = lab

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS); ./$(TARGET)

.cpp.o :
	$(CXX) $(CXXFLAGS) $<

clean : 
	rm $(OBJECTS)

# MyString.o : MyString.h MyString.cpp
# StringCtrlSample.o : MyString.h StringCtrlSample.cpp


dep : 
	g++ -M $(SRCS)
