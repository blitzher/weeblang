# setup variables
CC = gcc
CFLAGS = -ansi -pedantic -Wall
COMP = $(CC) $(CFLAGS)

INC = include
LIB = lib
LOG = logs

BIN = bin
SRC = src


# all object files, in the compiled 
# temporary directory
OBJS = $(LIB)/utility.o

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

# compile with debug flag, and run gdb
debug : $(SRC)/main.c $(OBJS)
	$(COMP) -g $(OBJS) $(SRC)/main.c -o $(BIN)/main_debug
	

# remove all items in temporary folders
clear :
	@rm -rf $(LIB)
	@rm -rf $(BIN)
	@rm -rf $(LOG)
	@echo cleared temporary files

# clear, then make
clean : clear $(BIN)/main.exe

# compile and run main
run : $(BIN)/main.exe
	@mkdir -p $(LOG)
	@./$(BIN)/main.exe
	
