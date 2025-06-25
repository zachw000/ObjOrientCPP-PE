# Detect OS and set shared library extension and flags
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	SHLIB_EXT := so
	SHLIB_FLAGS := -shared -fPIC
	SHLIB_NAME := libmanager.$(SHLIB_EXT)
	SHLIB_TARGET := lib/$(SHLIB_NAME)
else ifeq ($(UNAME_S),Darwin)
	SHLIB_EXT := dylib
	SHLIB_FLAGS := -dynamiclib -fPIC
	SHLIB_NAME := libmanager.$(SHLIB_EXT)
	SHLIB_TARGET := lib/$(SHLIB_NAME)
else
	# Assume Windows (MinGW or similar)
	SHLIB_EXT := dll
	SHLIB_FLAGS := -shared
	SHLIB_NAME := Manager.$(SHLIB_EXT)
	SHLIB_TARGET := lib/$(SHLIB_NAME)
endif

CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -O2 -g -fPIC
INCLUDES := -Iinc -Iinc/Projects
SRC_DIRS := src src/Projects
OBJDIR := obj
BINDIR := bin
LIBDIR := lib
TARGET := $(BINDIR)/Manager

# Find all .cpp files except Instance.cpp
SRCS := $(filter-out src/Manager/Instance.cpp, $(wildcard src/*.cpp)) $(wildcard src/Projects/*.cpp)
OBJS := $(patsubst src/%.cpp,$(OBJDIR)/%.o,$(filter src/%.cpp,$(SRCS))) \
		$(patsubst src/Projects/%.cpp,$(OBJDIR)/Projects/%.o,$(filter src/Projects/%.cpp,$(SRCS)))

# Default target
all: $(BINDIR) $(LIBDIR) $(TARGET)

# Build the shared library
$(SHLIB_TARGET): $(OBJS) | $(LIBDIR)
	$(CXX) $(CXXFLAGS) $(SHLIB_FLAGS) -o $@ $^

# Build the application binary
$(TARGET): $(SHLIB_TARGET) src/Manager/Instance.cpp | $(BINDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ src/Manager/Instance.cpp -L$(LIBDIR) -lmanager

# Object file rules
$(OBJDIR)/%.o: src/%.cpp | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/Projects/%.o: src/Projects/%.cpp | $(OBJDIR)/Projects
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Directory creation
$(BINDIR):
	mkdir -p $@

$(LIBDIR):
	mkdir -p $@

$(OBJDIR):
	mkdir -p $@

$(OBJDIR)/Projects:
	mkdir -p $@

# Clean rule
clean:
	rm -rf $(OBJDIR) $(BINDIR) $(LIBDIR)

.PHONY: all clean