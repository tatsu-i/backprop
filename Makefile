CC            = gcc
CFLAGS        = -g #-O4 -Wall -I/usr/local/include
LDFLAGS       = #-L/usr/local/lib
LIBS          = -lm
OBJS          = main.o connectionist.o
PROGRAM       = run

all:            $(PROGRAM)

$(PROGRAM):     $(OBJS)
	                $(CC) $(OBJS) $(LDFLAGS) $(LIBS) -o $(PROGRAM)

clean:;         rm -f *.o *~ $(PROGRAM)
