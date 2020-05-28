export

CXX ?= c++
AR ?= ar
CPPFLAGS ?= -DNDEBUG
CXXFLAGS ?= -O3 -g -Wall -Wextra -pedantic
LDFLAGS ?=

all: lib.a

FORCE:

libsh-treis/libsh-treis.hpp: FORCE
	$(MAKE) -C libsh-treis libsh-treis.hpp

libsh-treis-xcb.hpp: libsh-treis-xcb.cpp
	grep '//@' $< | sed 's~ *//@\( \|\)~~' > $@ || { rm -f $@; exit 1; }

libsh-treis-xcb.o: libsh-treis-xcb.cpp libsh-treis-xcb.hpp libsh-treis/libsh-treis.hpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -std=c++2a -c $<

libsh-treis/lib.a: FORCE
	$(MAKE) -C libsh-treis lib.a

lib.a: libsh-treis-xcb.o libsh-treis/lib.a
	cp libsh-treis/lib.a $@ && $(AR) rsD $@ libsh-treis-xcb.o || { rm -f $@; exit 1; }
