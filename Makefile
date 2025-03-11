CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
SRCDIR1 = src
SRCDIR2 = src/Projects
INCDIR = inc/Projects
BINDIR = bin
OBJDIR = obj
SOURCES1 = $(filter-out $(SRCDIR1)/Instance.cpp, $(wildcard $(SRCDIR1)/*.cpp))
SOURCES2 = $(wildcard $(SRCDIR2)/*.cpp)
SOURCES = $(SOURCES1) $(SOURCES2)
OBJECTS = $(SOURCES1:$(SRCDIR1)/%.cpp=$(OBJDIR)/%.o)
OBJECTS += $(SOURCES2:$(SRCDIR2)/%.cpp=$(OBJDIR)/%.o)
LIBRARY = $(BINDIR)/libmanager.dylib

$(LIBRARY): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -dynamiclib -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR1)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR2)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(BINDIR)/* $(OBJDIR)/*

.PHONY: clean