CC = gcc
CFLAGS = -m32 -static
TESTINFO = test_info
RUSAGE = getrusage
UNAME = uname
GETUID = getuid
GETPID = getpid

examples: $(UNAME) $(RUSAGE) $(GETUID) $(GETPID) 

test:	$(TESTINFO)

.PHONY: clean

clean:
	rm -f *.o *~ $(UNAME) $(RUSAGE) $(GETUID) $(GETPID) $(TESTINFO)

