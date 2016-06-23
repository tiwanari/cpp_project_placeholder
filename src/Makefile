h_files  := $(wildcard *.h)
cc_files := $(wildcard *.cc)
opts :=
opts += -O3
opts += -std=c++11
opts += -Wall

debug := -g

LIBRARY_DIR = ../lib/gen

GTEST_DIR = ../googletest
TEST_INCLUDE_DIR = $(GTEST_DIR)/include
TEST_STATIC_LIBRARY = $(LIBRARY_DIR)/libgtest.a

test_cc_files := $(filter-out main.cc, $(cc_files))
test_cc_files += $(wildcard unittest/*.cc)
UNAME = ${shell uname}
ifeq ($(UNAME),Linux)
	test_opts := -lpthread
endif

CXX = g++
CXXFLAGS := $(opts)
INCLUDES = -I.
INCLUDES += -I$(TEST_INCLUDE_DIR)
TEST_INCLUDES = $(INCLUDES)
# LIBS =
TEST_LIBS = $(LIBS)
TEST_LIBS += $(TEST_STATIC_LIBRARY)

OBJDIR = ./obj
objs = $(addprefix $(OBJDIR)/, $(cc_files:.cc=.o))
test_objs = $(addprefix $(OBJDIR)/, $(test_cc_files:.cc=.o))

main : $(objs) $(h_files)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $(objs)

$(OBJDIR)/%.o : %.cc
	@mkdir -p $(OBJDIR)/unittest
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ -c $<

.PHONY: run
run:
	./main

debug: $(objs) $(h_files)
	$(CXX) $(debug) $(CXXFLAGS) $(INCLUDES) -o $@ $(objs)
	gdb ./$@

$(TEST_STATIC_LIBRARY):
	git submodule init; git submodule update
	$(CXX) -c -I$(TEST_INCLUDE_DIR) -I$(GTEST_DIR) $(GTEST_DIR)/src/gtest-all.cc -o $(GTEST_DIR)/gtest-all.o
	mkdir -p $(LIBRARY_DIR)
	ar -rv $(TEST_STATIC_LIBRARY) $(GTEST_DIR)/gtest-all.o

test: $(TEST_LIBS) $(test_objs) $(h_files)
	$(CXX) $(CXXFLAGS) $(test_opts) $(TEST_INCLUDES) -o $@ $(test_objs) $(TEST_LIBS)
	./$@


.PHONY: clean
clean :
	-rm -f ./obj/*.o
	-rm -f ./obj/unittest/*.o
	-rm -f main
	-rm -f t
	-rm -f debug
	-rm -rf unittest/out/*
	-rm -r *.dSYM
