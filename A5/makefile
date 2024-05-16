
all: td

htd: hashFunctionTestDriver.o Dictionary.o Profile.o UnableToInsertException.o ElementAlreadyExistsException.o EmptyDataCollectionException.o ElementDoesNotExistException.o
	g++ -o htd -Wall hashFunctionTestDriver.o Dictionary.o Profile.o UnableToInsertException.o ElementAlreadyExistsException.o EmptyDataCollectionException.o ElementDoesNotExistException.o


td: Tester.o Dictionary.o Profile.o UnableToInsertException.o ElementAlreadyExistsException.o EmptyDataCollectionException.o ElementDoesNotExistException.o
	g++ -o td -Wall Tester.o Dictionary.o Profile.o UnableToInsertException.o ElementAlreadyExistsException.o EmptyDataCollectionException.o ElementDoesNotExistException.o

hashFunctionTestDriver.o: hashFunctionTestDriver.cpp
	g++ -c -Wall hashFunctionTestDriver.cpp

Tester.o: Tester.cpp 
	g++ -c -Wall Tester.cpp

Dictionary.o: Dictionary.cpp Dictionary.h
	g++ -c -Wall Dictionary.cpp

Profile.o: Profile.cpp Profile.h
	g++ -c -Wall Profile.cpp

ElementAlreadyExistsException.o: ElementAlreadyExistsException.cpp ElementAlreadyExistsException.h
	g++ -c -Wall ElementAlreadyExistsException.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h
	g++ -c -Wall EmptyDataCollectionException.cpp

ElementDoesNotExistException.o: ElementDoesNotExistException.cpp ElementDoesNotExistException.h 
	g++ -c -Wall ElementDoesNotExistException.cpp


UnableToInsertException.o: UnableToInsertException.cpp UnableToInsertException.h 
	g++ -c -Wall UnableToInsertException.cpp

clean: 
	rm -f td *.o