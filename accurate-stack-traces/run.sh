set -e
set -x
export CXXFLAGS=-O0
make
gdb -x gdb-input ./a.out | tail -n +11 > O0-results.txt
export CXXFLAGS=-O1
make
gdb -x gdb-input ./a.out | tail -n +11 > O1-results.txt
export CXXFLAGS=-O2
make
gdb -x gdb-input ./a.out | tail -n +11 > O2-results.txt
export CXXFLAGS=-O3
make
gdb -x gdb-input ./a.out | tail -n +11 > O3-results.txt
