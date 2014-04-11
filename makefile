SRC="src/"
HEADERS="headers/"
LIB="lib/"
BIN="bin/"
OBJECT="objects/"


prog: libmatrix++.a $(SRC)/main.cpp
	g++ -o $(BIN)prog -lmatrix++ main.cpp -L $(LIB) -I $(HEADERS)
	
libmatrix++.a: converter.o interpreter.o matrixManager.o sparseMatrix.o
	AR rv libmatrix++.a $(OBJECT)converter.o $(OBJECT)interpreter.o $(OBJECT)matrixManager.o $(OBJECT)sparseMatrix.o

converter.o: $(SRC)matrix++/converter.cpp $(HEADERS)converter.h
	g++ -o $(OBJECT)converter.o -c $(SRC)matrix++/converter.cpp -I $(HEADERS)
	
interpreter.o: $(SRC)matrix++/interpreter.cpp $(HEADERS)interpreter.h
	g++ -o $(OBJECT)interpreter.o -c $(SRC)matrix++/interpreter.cpp -I $(HEADERS)
	
matrixManager.o: $(SRC)matrix++/matrixManager.cpp $(HEADERS)matrixManager.h
	g++ -o $(OBJECT)interpreter.o -c $(SRC)matrix++/interpreter.cpp -I $(HEADERS)
	
sparseMatrix.o: $(SRC)matrix++/sparseMatrix.cpp $(HEADERS)sparseMatrix.h
	g++ -o $(OBJECT)sparseMatrix.o -c $(SRC)matrix++/sparseMatrix.cpp -I $(HEADERS)
	

clean:
	rm $(OBJECT)*.o
	
superClean:
	rm $(OBJECT)*.o $(LIB)*.a $(BIN)prog