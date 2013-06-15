#PLATFORM DETECTION
SHELL = /bin/sh

SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)
DEP := $(SRC:.c=.d)
INC := $(SRC:.c=.h) 

LDFLAGS :=  -L/usr/local/lib -g
CCFLAGS :=  $(DEBUG) -Wall -W -g

### Borrowed heavily from: http://stackoverflow.com/questions/714100/os-detecting-makefile
$(info ************  OS                     - $(OS) )
ifeq ($(OS),Windows_NT)
    EXENAME := IOHello.exe

    MAKE    :=  /bin/make.exe
    CC      :=  /mingw/bin/gcc.exe
    CP      :=  cp
    MV      :=  mv
    MKDIR   :=  mkdir -p

    BINDIR  :=  ../../../bin/win32
    CC      :=  /mingw/bin/gcc
    LIBR    :=  ../../../lib/ooch/build/*.o
    OBJDIR  :=  ../build
	
    $(info ************  PROCESSOR_ARCHITECTURE - $(PROCESSOR_ARCHITECTURE) )
    CCFLAGS += -D WIN32 -g
    ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
        CCFLAGS += -D AMD64 -g
    endif
    ifeq ($(PROCESSOR_ARCHITECTURE),x86)
        CCFLAGS += -D IA32 -g
    endif
else
    EXENAME := IOHello

    MAKE    :=  /usr/bin/make
    CC      :=  /usr/bin/gcc
    CP      :=  cp
    MV      :=  mv
    MKDIR   :=  mkdir -p
	
    BINDIR  :=  ../../../bin
    LIBR    :=  ../../../lib/ooch/build/*.o
    OBJDIR  :=  ../build
	
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        CCFLAGS += -D LINUX -g
### got from: http://www.linuxquestions.org/questions/programming-9/how-can-make-makefile-detect-64-bit-os-679513/
        LBITS := $(shell getconf LONG_BIT)
        ifeq ($(LBITS),64)
           # do 64 bit stuff here, like set some CFLAGS
           LIBR    := ../../../lib/ooch/build/linux_i386-64/*.o
           OBJDIR  := ../build/linux_i386-64
           BINDIR  := ../../../bin/linux_i386-64
        else
           # do 32 bit stuff here
           LIBR    := ../../../lib/ooch/build/linux_i386/*.o
           OBJDIR  := ../build/linux_i386
           BINDIR  := ../../../bin/linux_i386
        endif
    endif
    ifeq ($(UNAME_S),Darwin)
        BINDIR  :=  ../../../bin/mac_i386
        CCFLAGS += -D OSX -g
    endif
    UNAME_P := $(shell uname -p)
    ifeq ($(UNAME_P),x86_64)
        CCFLAGS += -D AMD64 -g
    endif
    ifneq ($(filter %86,$(UNAME_P)),)
        CCFLAGS += -D IA32 -g
    endif
    ifneq ($(filter arm%,$(UNAME_P)),)
        CCFLAGS += -D ARM -g
    endif
endif

SHELL = /bin/sh

SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)
DEP := $(SRC:.c=.d)
INC := $(SRC:.c=.h) 

#LIBS    :=  -lssl -ldl -lrt -lz -lc -lm -lcrypto

OBJPROG = $(addprefix $(OBJDIR)/, $(OBJ))
DEPPROG = $(addprefix $(OBJDIR)/, $(DEP))
EXEPROG = $(BINDIR)/$(EXENAME)\

.PHONY: directories

all: directories $(EXEPROG)

$(OBJPROG): | $(OBJDIR)

directories: $(OBJDIR)

$(OBJDIR):
	$(MKDIR) -p $(OBJDIR) 
	
$(EXEPROG): | $(BINDIR)

$(BINDIR):
	$(MKDIR) $(BINDIR) 

$(DEPPROG): $(SRC)
	# 
	# ========= START $< TO $@ =========
	$(CC) -ggdb -M $(CPPFLAGS) $< > $@.$$$$;                      \
    sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@;     \
    rm -f $@.$$$$
	# ========= END $< TO $@ =========

$(EXEPROG): $(SRC) $(DEPPROG)
	# 
	# ========= START $< TO $@ =========
	$(CC) -ggdb $< $(LIBR) -o $@
	# ========= END $< TO $@ =========
	# 

clean: 
	# ========== start clean activities ==========
	rm -f $(OBJDIR)/*.o
	rm -f $(BINDIR)/$(EXENAME)
	rm -f $(OBJDIR)/*.d
	# ========== end clean activities ==========
