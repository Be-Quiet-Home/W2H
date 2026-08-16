CXX := g++

TARGET := build/W2H

SOURCES := \
	src/main.cpp \
	src/W2HApplication.cpp \
	src/W2HWindow.cpp \
	src/W2HView.cpp

OBJECTS := $(SOURCES:src/%.cpp=build/%.o)
DEPENDS := $(OBJECTS:.o=.d)

CPPFLAGS := -Isrc
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -Wpedantic -Werror -MMD -MP
LDLIBS := -lbe


.PHONY: all clean help

all: $(TARGET)


$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDLIBS)


build/%.o: src/%.cpp
	@mkdir -p build
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@


clean:
	rm -rf build


help:
	@echo "make        Build W2H"
	@echo "make clean  Remove build products"
	@echo "make help   Show available targets"


-include $(DEPENDS)
