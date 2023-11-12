default:

all:

SQLiteShell:
	gcc -o sqlite api/sqlite/sqlite3.c api/sqlite/shell.c	

testDbCpp: api/db_to_frontend.cpp
	g++ -o testDbCpp api/db_to_frontend.cpp -lsqlite3

clean:
	rm -f *.o *.exe