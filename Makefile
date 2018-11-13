C=gcc
CXX=g++
RM=rm -f
CPPFLAGS= -std=c++11
LDFLAGS=
LDLIBS= -lm

SRCS=main.cpp Polynomial.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: polynomial
debug: CPPFLAGS+=-g
debug: LDFLAGS+=-g
debug: polynomial

polynomial: $(OBJS)
	$(CXX) $(LDFLAGS)  $(OBJS) -o polynomial  $(LDLIBS)

main.o: main.cpp Polynomial.hpp

wielomiany.o: Polynomial.cpp Polynomial.hpp

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) polynomial
