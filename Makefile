OBJECT_FILES = Multigraph.o Unitarize.o

Unitarize: $(OBJECT_FILES)
	g++ $(OBJECT_FILES) -o Unitarize

Multigraph.o: Multigraph.cpp Multigraph.hh 
	g++ -c Multigraph.cpp

Unitarize.o: Unitarize.cpp Multigraph.hh
	g++ -c Unitarize.cpp 