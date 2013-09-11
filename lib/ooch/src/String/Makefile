SHELL = /bin/sh

SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)
DEP := $(SRC:.c=.d)
INC := $(SRC:.c=.h) 

LDFLAGS :=  -L/usr/local/lib
CCFLAGS :=  $(DEBUG) -Wall -W

### Borrowed heavily from: http://stackoverflow.com/questions/714100/os-detecting-makefile
$(info ************  OS                     - $(OS) )
ifeq ($(OS),Windows_NT)

    MAKE    :=  /bin/make.exe
    CC      :=  /mingw/bin/gcc.exe
    CP      :=  cp
    MV      :=  mv
    MKDIR   :=  mkdir -p
	
    OBJDIR = ../build

    $(info ************  PROCESSOR_ARCHITECTURE - $(PROCESSOR_ARCHITECTURE) )
    CCFLAGS += -D WIN32
    ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
        CCFLAGS += -D AMD64
    endif
    ifeq ($(PROCESSOR_ARCHITECTURE),x86)
        CCFLAGS += -D IA32
    endif
else

    MAKE    :=  /usr/bin/make
    CC      :=  /usr/bin/gcc
    CP      :=  cp
    MV      :=  mv
    MKDIR   :=  mkdir -p

    OBJDIR = ../../build
	
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        CCFLAGS += -D LINUX
### got from: http://www.linuxquestions.org/questions/programming-9/how-can-make-makefile-detect-64-bit-os-679513/
        LBITS := $(shell getconf LONG_BIT)
        ifeq ($(LBITS),64)
           # do 64 bit stuff here, like set some CFLAGS
           OBJDIR = ../../build/linux_i386-64
        else
           # do 32 bit stuff here
           OBJDIR = ../../build/linux_i386
        endif
    endif
    ifeq ($(UNAME_S),Darwin)
        CCFLAGS += -D OSX
    endif
    UNAME_P := $(shell uname -p)
    ifeq ($(UNAME_P),x86_64)
        CCFLAGS += -D AMD64
    endif
    ifneq ($(filter %86,$(UNAME_P)),)
        CCFLAGS += -D IA32
    endif
    ifneq ($(filter arm%,$(UNAME_P)),)
        CCFLAGS += -D ARM
    endif
endif

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
	$(CC) -ggdb -M $(CPPFLAGS) $< > $@.$$$$;                      \
    sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@;     \
    rm -f $@.$$$$
	# ========= END $< TO $@ =========

$(OBJPROG): $(SRC) $(DEPPROG)
	# 
	# ========= START $< TO $@ =========
	$(CC) -ggdb $(CCFLAGS) -c $< -o $@ -I. 
	# ========= END $< TO $@ =========
	# 

clean: .
	# ========== start clean activities ==========
	rm -f $(OBJDIR)/*.o
	rm -f $(name).map
	rm -f $(name)
	rm -f $(OBJDIR)/*.d
	# ========== end clean activities ==========
