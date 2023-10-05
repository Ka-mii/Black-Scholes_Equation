# ================================= Variables ================================ #

# ----------------------------------- Files ---------------------------------- #
OBJ1 = $(OBJDIR)/main.o
# OBJ2 = $(OBJDIR)/psi.o
# OBJ3 = $(OBJDIR)/outils.o
# OBJ4 = $(OBJDIR)/quadrature.o

LIBR = 

# ============================= Targets and rules ============================ #
# ------------------------------ Default target ------------------------------ #
all: $(TARGET)

.PHONY: all

# -------------------------------- Main rules -------------------------------- #
$(TARGET): $(OBJ1)
	$(LD) $(LDFLAGS) -o $@ $^ $(LIBR)

# $(TARGET): $(OBJ2)
# 	$(LD) $(LDFLAGS) -o $@ $^ $(LIBR)

# $(TARGET): $(OBJ3)
# 	$(LD) $(LDFLAGS) -o $@ $^ $(LIBR)

# $(TARGET): $(OBJ4)
# 	$(LD) $(LDFLAGS) -o $@ $^ $(LIBR)

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	$(CC) $(CFLAGS) -o $@ -c $< $(LIBR)

# $(OBJDIR)/psi.o: $(SRCDIR)/psi.cpp
# 	$(CC) $(CFLAGS) -o $@ -c $< $(LIBR)
 
# $(OBJDIR)/outils.o: $(SRCDIR)/outils.cpp
# 	$(CC) $(CFLAGS) -o $@ -c $< $(LIBR)
  
# $(OBJDIR)/quadrature.o: $(SRCDIR)/quadrature.cpp
# 	$(CC) $(CFLAGS) -o $@ -c $< $(LIBR)
