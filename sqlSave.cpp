#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <windows.h>

using namespace std;

const char* HOST = "localhost";
const char* USER = "root";
const char* PW = "eofori123...";

int connectsql() {
    MYSQL* conn;
    
    char PlayerName[13];
	int play_ID;
	int Pmatches, Pwins, Pdraws, Ploss, goalsfor, goalsAgainst, goalDiff, Points;
	float winRate, avegoals;
	
	bool sqlOpened = true;
	int answer;
	
	char* consult;
	char* sentence;
	string sentence_aux;
	
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, HOST, USER, PW, NULL, 3306, NULL, 0)) {
        cout << endl << endl;
        cout << "\t\t Error: " << mysql_error(conn) << endl;
    } else {
        cout << endl << endl;
        cout << "\t\t Connected to MySQL server!" << endl;

        // Create database
        const char* create_db_query = "CREATE DATABASE IF NOT EXISTS mydb";
        if (mysql_query(conn, create_db_query)) {
            cout << "\t\t Error: " << mysql_error(conn) << endl;
        } else {
            cout << "\t\t Database created successfully!" << endl;
        }

        // Select the database
        if (mysql_select_db(conn, "mydb")) {
            cout << "\t\t Error: " << mysql_error(conn) << endl;
        } else {
            cout << "\t\t Database selected successfully!" << endl;
        }

        // You can now proceed with other operations on the database
        // such as creating tables, inserting data, etc.

        mysql_close(conn);
    }
    return 0;
}


