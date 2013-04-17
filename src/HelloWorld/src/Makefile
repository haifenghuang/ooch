#PLATFORM DETECTION
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
    EXENAME := HelloWorld.exe

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
    CCFLAGS += -D WIN32
    ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
        CCFLAGS += -D AMD64
    endif
    ifeq ($(PROCESSOR_ARCHITECTURE),x86)
        CCFLAGS += -D IA32
    endif
else
    EXENAME := HelloWorld

    MAKE    :=  /usr/bin/make
    CC      :=  /usr/bin/gcc
    CP      :=  cp
    MV      :=  mv
    MKDIR   :=  mkdir -p
	
    BINDIR  :=  ../../../bin/linux_i386
    LIBR    :=  ../../../lib/ooch/build/*.o
    OBJDIR  :=  ../build
	
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        CCFLAGS += -D LINUX
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

SHELL = /bin/sh

SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)
DEP := $(SRC:.c=.d)
INC := $(SRC:.c=.h) 

#LIBS    :=  -lssl -ldl -lrt -lz -lc -lm -lcrypto

OBJPROG = $(addprefix $(OBJDIR)/, $(OBJ))
DEPPROG = $(addprefix $(OBJDIR)/, $(DEP))
EXEPROG = $(BINDIR)/$(EXENAME)

all: $(EXEPROG)

$(OBJPROG): | $(OBJDIR)

$(OBJDIR):
	$(MKDIR) -p $(OBJDIR) 
	
$(EXEPROG): | $(BINDIR)

$(BINDIR):
	$(MKDIR) $(BINDIR) 

$(DEPPROG): $(SRC)
	# 
	# ========= START $< TO $@ =========
	$(CC) -M $(CPPFLAGS) $< > $@.$$$$;                      \
    sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@;     \
    rm -f $@.$$$$
	# ========= END $< TO $@ =========

$(EXEPROG): $(SRC) $(DEPPROG)
	# 
	# ========= START $< TO $@ =========
	$(CC) $< $(LIBR) -o $@
	# ========= END $< TO $@ =========
	# 

clean: 
	# ========== start clean activities ==========
	rm -f $(OBJDIR)/*.o
	rm -f $(BINDIR)/$(EXENAME)
	rm -f $(OBJDIR)/*.d
	# ========== end clean activities ==========
