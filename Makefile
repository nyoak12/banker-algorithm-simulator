# file to build
sources = bankerAlgo.cpp

# file to output
target = banker

compiler = clang++

# compiler flags
flags = -std=c++17

# build file
build:
	$(compiler) $(flags) $(sources) -o $(target)

# run both tests
run: build
	./$(target)

# "clean" and "test" are not produced by make
.PHONY: clean test

# delete built file
clean:
	rm -f $(target)