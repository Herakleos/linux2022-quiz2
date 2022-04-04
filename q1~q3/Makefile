CC = gcc

# g: debug info compiled
# Wall: more warning message while compile
CFLAGS = -O1 -g -Wall -Werror

# Control the build verbosity
ifeq ("$(VERBOSE)","1")
    Q :=
    VECHO = @true
else
    Q := @
    VECHO = @printf
endif

OBJS := test.o \
        average.o min_max.o gcd.o

deps := $(OBJS:%.o=.%.o.d)

%.o: %.c
	$(VECHO) "  CC\t$@\n"
	$(Q)$(CC) -o $@ $(CFLAGS) -c -MMD -MF .$@.d $<

all: test

test: $(OBJS)
	$(VECHO) "  LD\t$@\n"
	$(Q)$(CC) -o $@ $^ -lm

clean:
	@echo "Clean..."
	rm -f $(OBJS) $(deps) test

-include $(deps)