# Compiler settings
CC = g++
CFLAGS = -std=c++11 -Wall

# Directories
SRCDIR = src
OBJDIR = obj
INCDIR = include
BINDIR = bin
TESTDIR = tests

# Source files and object files
SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

# Test source files and object files
TEST_SRCS := $(wildcard $(TESTDIR)/*.cpp)
TEST_OBJS := $(patsubst $(TESTDIR)/%.cpp,$(OBJDIR)/%.o,$(TEST_SRCS))

# Main executable file and test executable file
MAIN = main
TEST_MAIN = test

# Targets
all: $(BINDIR)/$(MAIN)

$(BINDIR)/$(MAIN): $(OBJS) $(MAIN).cpp
	$(CC) $(CFLAGS) -I $(INCDIR) $^ -o $@

$(BINDIR)/$(TEST_MAIN): $(OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) -I $(INCDIR) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

$(OBJDIR)/%.o: $(TESTDIR)/%.cpp
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

test: $(BINDIR)/$(TEST_MAIN)
	./$(BINDIR)/$(TEST_MAIN)

clean:
	rm -f $(OBJS) $(TEST_OBJS) $(BINDIR)/$(MAIN) $(BINDIR)/$(TEST_MAIN)

.PHONY: all test clean
