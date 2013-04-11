#PLATFORM DETECTION

UNAME := $(shell uname)

$(info ************  UNAME - $(UNAME)  ************)

ifeq ($(UNAME), MINGW32_NT-5.1)
$(info ************  TARGET WINDOWS 32bit  ************)
BINDIR  :=  ..\..\..\bin\win32
CC      :=  \mingw\bin\gcc
LIBR    :=  ..\..\..\lib\ooch\build\*.o
OBJDIR = ..\build
else
$(info ************  TARGET LINUX i386  ************)
BINDIR  :=  ../../../bin/linux_i386
CC      :=  /usr/bin/gcc
LIBR    :=  ../../../lib/ooch/build/*.o
OBJDIR = ../build
endif

EXENAME := HelloWorld

SHELL = /bin/sh

SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)
DEP := $(SRC:.c=.d)
INC := $(SRC:.c=.h) 

MAKE    :=  /usr/bin/make
CP      :=  cp
MV      :=  mv
MKDIR   :=  mkdir

LDFLAGS :=  -L$(LIBR)
CCFLAGS :=  $(DEBUG) -Wall -W


#LIBS    :=  -lssl -ldl -lrt -lz -lc -lm -lcrypto

OBJPROG = $(addprefix $(OBJDIR)/, $(OBJ))
DEPPROG = $(addprefix $(OBJDIR)/, $(DEP))
EXEPROG = $(BINDIR)/$(EXENAME)

all: $(EXEPROG)

$(OBJPROG): | $(OBJDIR)

$(OBJDIR):
	$(MKDIR) -p $(OBJDIR) 

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
