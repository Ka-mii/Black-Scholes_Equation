# Error if path conains whitespace
ifneq (1,$(words $(CURDIR)))
$(error Containing path cannot contain whitespace: '$(CURDIR)')
endif

# ================================= Variables ================================ #
# -------------------------------- Directories ------------------------------- #
export ROOTDIR    = $(PWD)
export SRCDIR     = $(ROOTDIR)/src
export TESTSDIR   = $(ROOTDIR)/test
export INCLUDEDIR = $(ROOTDIR)/headers
export OBJDIR     = $(ROOTDIR)/obj
export BINDIR     = $(ROOTDIR)/bin
export DOCDIR     = $(ROOTDIR)/doc

#--------------------------------- Compiler --------------------------------- #

export CC     = g++
export CFLAGS = -I$(INCLUDEDIR) -Wall -Wextra

#------------------------------------ Test ----------------------------------- #

export CXXTESTGEN = cxxtestgen 
export CXXTESTFLAGS = --error-printer

export OBJSTEST = 

# -------------------------------- Libraries --------------------------------- #

export LIBS 	= 

# ---------------------------------- Linker ---------------------------------- #
export LD      = g++
export LDFLAGS =

# ----------------------------------- Files ---------------------------------- #
export TARGET = $(BINDIR)/main.out

# ============================= Targets and rules ============================ #
# ------------------------------ Default target ------------------------------ #
all: $(TARGET)

.PHONY: all

# ------------------------------ Directory rules ----------------------------- #
$(OBJDIR):
	mkdir -p $@

$(BINDIR):
	mkdir -p $@

# -------------------------------- Main rules -------------------------------- #
$(TARGET): $(OBJDIR)\
	$(BINDIR)
	$(MAKE) -C $(SRCDIR) $(LIBS)

test: $(TARGET)
	$(MAKE) -C $(TESTSDIR)

run: $(TARGET)
	$<

doc:
	doxygen Doxyfile

.PHONY: $(TARGET) \
        test \
        run \
        doc

# -------------------------------- Clean rules ------------------------------- #
clean: clean-obj \
       clean-bin \
       clean-doc

clean-obj:
	rm -rf $(OBJDIR)

clean-bin:
	rm -rf $(BINDIR)

clean-doc:
	rm -rf $(DOCDIR)

.PHONY: clean \
        clean-obj \
        clean-bin \
        clean-doc