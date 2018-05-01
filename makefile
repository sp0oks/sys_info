CC = gcc
OPT = -m32 -static
USGSRC = examples/getrusage.c
USGOUT = getrusage
UNMSRC = examples/uname.c
UNMOUT = uname
UIDSRC = examples/getuid.c
UIDOUT = getuid
PIDSRC = examples/getpid.c
PIDOUT = getpid
TESTSRC = examples/test_info.c
TESTOUT = test_info

uname:
	$(CC) $(UNMSRC) -o $(UNMOUT)

getrusage:
	$(CC) $(USGSRC) -o $(USGOUT)

getuid:
	$(CC) $(UIDSRC) -o $(UIDOUT)

getpid:
	$(CC) $(PIDSRC) -o $(PIDOUT)

test:
	$(CC) $(OPT) $(TESTSRC) -o $(TESTOUT)

examples: uname getrusage getuid getpid 

.PHONY: clean

clean:
	rm ./$(UNMOUT) ./$(USGOUT) ./$(UIDOUT) ./$(PIDOUT) ./$(TESTOUT)
