out		= test
CC		= tcc
CXX		= clang++
DC		= dmd
F95		= gfortran
GCC		= gcc
JC		= javac
LIBS	= -lc -lm
CFLAGS	= -Wno-implicit -ggdb
DFLAGS	= -od/tmp/ -of$(out)
LDFLAGS	= 
CXXFLAGS= -std=c++11
F95FLAGS= -std=f95 -w
GCCFLAGS= -lstdc++
JFLAGS	= 
SRC		= $(app)
APP		= $(out)
ARGS	= $(args)
EXEC	= $(LIBS) $(LDFLAGS) -o $(APP)
RUNCMD	= ./$(APP) $(ARGS)

.PHONY: *
all:
	@echo "No file specified!"
	@exit 1
clean:
	-rm a.out $(APP) {$(APP),*}.{o,so,s,pre} *.class

*.c:
	$(CC) $(CFLAGS) $(EXEC) $@
	$(RUNCMD)
*.cpp:
	$(CXX) $(CXXFLAGS) $(EXEC) $@
	$(RUNCMD)
*.d:
	@echo $(DC) $(DFLAGS) -run $@ $(ARGS)
	@CC=gcc $(DC) $(DFLAGS) -run $@ $(ARGS)
*.f *.f??:
	$(F95) $(F95FLAGS) $(EXEC) $@
	$(RUNCMD)
*.java:
	$(JC) $(JFLAGS) $@
	@echo "Running $@ ..."
	@java `basename $@ .java` $(ARGS)

debug:
	$(GCC) $(CFLAGS) $(GCCFLAGS) $(EXEC) -Wall -ggdb $(SRC)
	gdb $(APP)
test:
	$(GCC) $(CFLAGS) $(GCCFLAGS) $(LIBS) -ggdb $(SRC)
	gdb a.out -ex run
	-rm a.out
wall:
	$(CC) $(EXEC) $(ARGS) -Wall $(SRC)
obj:
	$(CC) $(EXEC).o $(ARGS) -c $(SRC)
so:
	$(CC) $(EXEC).so $(ARGS) -shared $(SRC)
	mv $(APP).so lib$(APP).so
asm:
	$(CC) $(EXEC).s $(ARGS) -S -masm=intel $(SRC)
prep:
	$(CC) $(EXEC).pre $(ARGS) -E $(SRC)
