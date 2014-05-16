SRC=src/
HEADERS=headers/
LIB=lib/
BIN=bin/
OBJECT=objects/

REPLIB=matrix++/

#prog: libmatrix++.a $(SRC)/main.cpp
#	g++ -o $(BIN)prog -lmatrix++ main.cpp -L $(LIB) -I $(HEADERS)
	
interpreter: $(SRC)mainInterpreter.cpp $(LIB)libmatrix++.a
	g++ -o $(BIN)interpreter $(SRC)mainInterpreter.cpp -L$(LIB) -lmatrix++ -I $(HEADERS)$(REPLIB)
	
converter: $(SRC)mainConverter.cpp $(LIB)libmatrix++.a
	g++ -o $(BIN)converter $(SRC)mainConverter.cpp -L$(LIB) -lmatrix++ -I $(HEADERS)$(REPLIB)


$(LIB)libmatrix++.a: converter.o interpreter.o matrixManager.o sparseMatrix.o matrixCase.o
	ar rv $(LIB)libmatrix++.a $(OBJECT)converter.o $(OBJECT)interpreter.o $(OBJECT)matrixManager.o $(OBJECT)sparseMatrix.o $(OBJECT)matrixCase.o

converter.o: $(SRC)$(REPLIB)converter.cpp $(HEADERS)$(REPLIB)converter.h
	g++ -o $(OBJECT)converter.o -c $(SRC)$(REPLIB)converter.cpp -I $(HEADERS)$(REPLIB)
	
interpreter.o: $(SRC)$(REPLIB)interpreter.cpp $(HEADERS)$(REPLIB)interpreter.h
	g++ -o $(OBJECT)interpreter.o -c $(SRC)$(REPLIB)interpreter.cpp -I $(HEADERS)$(REPLIB)
	
matrixManager.o: $(SRC)$(REPLIB)matrixManager.cpp $(HEADERS)$(REPLIB)matrixManager.h
	g++ -o $(OBJECT)matrixManager.o -c $(SRC)$(REPLIB)matrixManager.cpp -I $(HEADERS)$(REPLIB)

matrixCase.o: $(SRC)$(REPLIB)matrixCase.cpp $(HEADERS)$(REPLIB)matrixCase.h
	g++ -o $(OBJECT)matrixCase.o -c $(SRC)$(REPLIB)matrixCase.cpp -I $(HEADERS)$(REPLIB)

sparseMatrix.o: $(SRC)$(REPLIB)sparseMatrix.cpp $(HEADERS)$(REPLIB)sparseMatrix.h
	g++ -o $(OBJECT)sparseMatrix.o -c $(SRC)$(REPLIB)sparseMatrix.cpp -I $(HEADERS)$(REPLIB)
	

clean:
	rm $(OBJECT)*.o
	
superClean:
	rm $(OBJECT)*.o $(LIB)*.a $(BIN)prog
