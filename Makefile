CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -fPIC -Os
CXXFLAGS2 = -Wl,-rpath=lib/ -L ./bin -lmanager -lm -I inc/
SRCDIR1 = src
SRCDIR2 = src/Projects
INCDIR = inc/Projects
BINDIR = bin
OBJDIR = obj
SOURCES1 = $(filter-out $(SRCDIR1)/Manager/Instance.cpp, $(wildcard $(SRCDIR1)/*.cpp))
SOURCES2 = $(wildcard $(SRCDIR2)/*.cpp)
SOURCES = $(SOURCES1) $(SOURCES2)
OBJECTS = $(SOURCES1:$(SRCDIR1)/%.cpp=$(OBJDIR)/%.o)
OBJECTS += $(SOURCES2:$(SRCDIR2)/%.cpp=$(OBJDIR)/%.o)
LIBRARY = $(BINDIR)/libmanager.so
EXECUTABLE = $(BINDIR)/Manager

$(EXECUTABLE): $(LIBRARY)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $(CXXFLAGS2) -o $@ $(SRCDIR1)/Manager/Instance.cpp

$(LIBRARY): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -shared -o $@ $^
	@mkdir -p lib
	@cp $(BINDIR)/libmanager.so lib/
	@rm -rf $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR1)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR2)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(BINDIR)/* $(OBJDIR)/*.o lib/*

.PHONY: clean