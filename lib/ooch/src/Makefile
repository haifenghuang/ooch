SHELL = /bin/sh

SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)
DEP := $(SRC:.c=.d)
INC := $(SRC:.c=.h) 

MAKE    :=  /usr/bin/make
CC      :=  /usr/bin/gcc
CP      :=  cp
MV      :=  mv
MKDIR   :=  mkdir -p

LDFLAGS :=  -L/usr/local/lib
CCFLAGS :=  $(DEBUG) -Wall -W

OBJDIR = ../build

#LIBS    :=  -lssl -ldl -lrt -lz -lc -lm -lcrypto

OBJPROG = $(addprefix $(OBJDIR)/, $(OBJ))
DEPPROG = $(addprefix $(OBJDIR)/, $(DEP))

.PHONY: directories

all: directories $(DEPPROG) $(OBJPROG)

directories: $(OBJDIR)

$(OBJDIR):
	$(MKDIR) $(OBJDIR) 

$(DEPPROG): $(SRC)
	# 
	# ========= START $< TO $@ =========
	$(CC) -M $(CPPFLAGS) $< > $@.$$$$;                      \
    sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@;     \
    rm -f $@.$$$$
	# ========= END $< TO $@ =========

$(OBJPROG): $(SRC) $(DEPPROG)
	# 
	# ========= START $< TO $@ =========
	$(CC) $(CCFLAGS) -c $< -o $@ -I. 
	# ========= END $< TO $@ =========
	# 

clean: .
	# ========== start clean activities ==========
	rm -f $(OBJDIR)/*.o
	rm -f $(name).map
	rm -f $(name)
	rm -f $(OBJDIR)/*.d
	# ========== end clean activities ==========
