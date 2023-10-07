# ================================= Variables ================================
# -------------------------------- Directories -------------------------------
ROOTDIR    := $(PWD)
SRCDIR     := $(ROOTDIR)/src
TESTSDIR   := $(ROOTDIR)/tests
INCLUDEDIR := $(ROOTDIR)/headers
OBJDIR     := $(ROOTDIR)/obj
BINDIR     := $(ROOTDIR)/bin
DOCDIR     := $(ROOTDIR)/doc

# ---------------------------------- Files ----------------------------------
TARGET     := $(BINDIR)/black_scholes.out

# -------------------------------- Compiler ---------------------------------
CC     := g++
FLAGS  := -Wall -Wextra -std=c++2a
LDFLAGS := $(pkg-config --cflags --libs sdl2)

# ============================= Targets and rules ============================
# ------------------------------ Default target ------------------------------
all: $(TARGET)

.PHONY: all test coverage

# ------------------------------ Test target ---------------------------------
test: $(TARGET) $(BINDIR)/test_call.out $(BINDIR)/test_put.out 
	@echo "Running tests..."

$(BINDIR)/test_put.out : obj/test_put.o obj/payoff.o obj/put.o
	@echo "Linking tests for Put..."
	$(CC) $(FLAGS) -o $@ $^ $(LDFLAGS)

obj/test_put.o : $(TESTSDIR)/test_put.cpp headers/put.hpp headers/payoff.hpp
	@echo "Compiling test_put $<..."
	$(CC) $(FLAGS) -c $< -o $@

$(BINDIR)/test_call.out: obj/test_call.o obj/payoff.o obj/call.o
	@echo "Linking tests for Call..."
	$(CC) $(FLAGS) -o $@ $^ $(LDFLAGS)

obj/test_call.o: $(TESTSDIR)/test_call.cpp headers/call.hpp headers/payoff.hpp
	@echo "Compiling test_call $<..."
	$(CC) $(FLAGS) -c $< -o $@

# -------------------------------- Main rules --------------------------------
$(TARGET): obj/main.o obj/payoff.o obj/put.o obj/call.o obj/interface.o
	@echo "Linking $@"
	$(CC) $(FLAGS) -o $(TARGET) $^ $(LDFLAGS)

obj/main.o : $(SRCDIR)/main.cpp 
	@echo "Compiling $@"
	$(CC) $(FLAGS) -c $< -o $@

obj/payoff.o : $(SRCDIR)/payoff.cpp headers/payoff.hpp
	@echo "Compiling $@"
	$(CC) $(FLAGS) -c $< -o $@

obj/call.o : $(SRCDIR)/call.cpp headers/call.hpp headers/payoff.hpp
	@echo "Compiling $@"
	$(CC) $(FLAGS) -c $< -o $@

obj/put.o : $(SRCDIR)/put.cpp headers/put.hpp headers/payoff.hpp
	@echo "Compiling $@"
	$(CC) $(FLAGS) -c $< -o $@

obj/interface.o : $(SRCDIR)/interface.cpp headers/call.hpp headers/put.hpp headers/payoff.hpp
	@echo "Compiling $@"
	$(CC) $(FLAGS) -c $< -o $@

# -------------------------------- Clean rules -------------------------------
clean: clean-obj clean-bin

clean-obj:
	rm -f -v $(OBJDIR)/*.o

clean-bin:
	rm -f -v $(BINDIR)/*.out $(TEST_TARGET)

# -------------------------------- Documentation ----------------------------
doc: Doxyfile
	doxygen -g $<
	@rm -f Doxyfile.bak 

doc-run: Doxyfile
	doxygen $<