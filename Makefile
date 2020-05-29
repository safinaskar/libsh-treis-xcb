export

CXX ?= c++
AR ?= ar
CPPFLAGS ?= -DNDEBUG
CXXFLAGS ?= -O3 -g -Wall -Wextra -pedantic
LDFLAGS ?=

all: lib.a

.DELETE_ON_ERROR:

FORCE:

libsh-treis/%: FORCE
	T='$@'; $(MAKE) -C "$${T%%/*}" "$${T#*/}"

libsh-treis-xcb.hpp: libsh-treis-xcb.cpp
	grep '//@' $< | sed 's~ *//@\( \|\)~~' > $@

libsh-treis-xcb.o: libsh-treis-xcb.cpp FORCE
	libsh-treis/compile $< $(CXX) $(CPPFLAGS) $(CXXFLAGS) -std=c++2a

lib.a: libsh-treis-xcb.o libsh-treis/lib.a
	cp libsh-treis/lib.a $@ && $(AR) rsD $@ libsh-treis-xcb.o
