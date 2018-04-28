CC = gcc
OPT = -o
USGSRC = examples/getrusage.c
USGOUT = getrusage
UNMSRC = examples/uname.c
UNMOUT = uname
UIDSRC = examples/getuid.c
UIDOUT = getuid
PIDSRC = examples/getpid.c
PIDOUT = getpid

uname:
	$(CC) $(UNMSRC) $(OPT) $(UNMOUT)

getrusage:
	$(CC) $(USGSRC) $(OPT) $(USGOUT)

getuid:
	$(CC) $(UIDSRC) $(OPT) $(UIDOUT)

getpid:
	$(CC) $(PIDSRC) $(OPT) $(PIDOUT)

all: uname getrusage getuid getpid 

.PHONY: clean

clean:
	rm ./$(UNMOUT) ./$(USGOUT) ./$(UIDOUT) ./$(PIDOUT)
