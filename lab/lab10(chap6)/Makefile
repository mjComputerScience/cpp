.SUFFIXES : .cpp .o

OBJECTS = CMyString.o\
		  StringCtrlSample.o\
		  CMyStringEx.o
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
