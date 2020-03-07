export

CXX ?= c++
CPPFLAGS ?= -DNDEBUG
CXXFLAGS ?= -O3 -g -Wall -Wextra -pedantic
LDFLAGS ?=

all: libsh-treis-xcb.o FORCE
	rm -f libsh-treis/stamp
	$(MAKE) -C libsh-treis
	[ -f libsh-treis/stamp ] && touch stamp || :

FORCE:

libsh-treis/libsh-treis.hpp: FORCE
	$(MAKE) -C libsh-treis libsh-treis.hpp

libsh-treis-xcb.hpp: libsh-treis-xcb.cpp
	grep '//@' $< | sed 's~ *//@\( \|\)~~' > $@ || { rm -f $@; exit 1; }

libsh-treis-xcb.o: libsh-treis-xcb.cpp libsh-treis-xcb.hpp libsh-treis/libsh-treis.hpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -std=c++2a -c $<
	touch stamp
