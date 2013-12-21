
all:
	clang++ -c $(CXXFLAGS) accurate-stack-trace.cpp
	clang++ -c $(CXXFLAGS) support.cpp
	clang accurate-stack-trace.o support.o

clean:
	rm -f support.o accurate-stack-trace.o a.out
