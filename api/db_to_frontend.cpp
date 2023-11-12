#include <stdio.h>
#include <string>

#include <iostream>
#include "sqlite/sqlite3.h"

using namespace std;

int main(int argc, char *argv[])
{
    sqlite3 *db;
    int rc;
    rc = sqlite3_open("test.db", &db);
    if (rc != SQLITE_OK)
        cout << "file failed to open" << endl;
    else
        cout << "file opened" << endl;

    return 0;
}