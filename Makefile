CC=g++ -std=c++11
EXE_FILE=run_wizard

all: $(EXE_FILE)

$(EXE_FILE): run_wizard.cpp catalog.o
	$(CC) run_wizard.cpp catalog.o -o $(EXE_FILE)

catalog.o: catalog.cpp catalog.h
	$(CC) -c catalog.cpp

clean:
	rm -f *.o $(EXE_FILE)
