output: main.o tree.o
	g++ main.o tree.o -o output

main.o : main.cc
	g++ -c main.cc

tree.o:
	g++ -c tree.cc

clean:
	rm *o

a: main.cc tree.cc
	g++ -g main.cc tree.cc -o a.out
