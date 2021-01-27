# setup variables
CC = gcc
CFLAGS = -ansi -pedantic -Wall
COMP = $(CC) $(CFLAGS)
INC = include
LIB = lib
BIN = bin
SRC = src

# all object files, in the compiled 
# temporary directory
OBJS = $(LIB)/utility.o \
	   $(LIB)/routes.o \
	   $(LIB)/colours.o \
	   $(LIB)/vector.o \
	   $(LIB)/simulation.o

$(BIN)/%.exe : $(SRC)/%.c $(OBJS)
		
	@mkdir -p $(LIB) $(BIN)
	@echo Compiling $<...

	@$(COMP) $(OBJS) $< -o $@
	@echo
	@echo Compilation successful

# general rule for compiling any library files
$(LIB)/%.o : $(INC)/%.c $(INC)/%.h
	@mkdir -p $(LIB) $(BIN)
	@echo Compiling $<...
	@$(COMP) -c $< -o $@

# don't remove objs when compiling by
# implicit rules
.PRECIOUS : $(OBJS)

# remove all items in temporary folders
clear :
	@rm -rf $(LIB)
	@rm -rf $(BIN)
	@rm -f *.exe
	@rm -f *.o
	@rm -f .output
	@rm -f .visuals
	@echo cleared temporary files

# clear, then make
clean : clear $(BIN)/main.exe

# compile and run main
run : $(BIN)/main.exe
	@./$(BIN)/main.exe
	
