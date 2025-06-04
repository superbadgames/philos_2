"""
- Connect to the sqlite3 database
- Create all the tables that the Tower engine is going to assume are there, and
populate it with the needed default values, that can be changes later per project
"""
import sys
import sqlite3

db_path = "./Assets/philos.db"


def create_tables():
    try:
        db_connection = sqlite3.connect(db_path)
        cursor = db_connection.cursor()
        print("Successfully connected to the database\n")

        query = """ CREATE TABLE IF NOT EXISTS Tower_Config (
                        ID INT PRIMARY KEY NOT NULL,
                        WINDOW_NAME TEXT NOT NULL,
                        WINDOW_WIDTH INT NOT NULL,
                        WINDOW_HEIGHT INT NOT NULL,
                        FIELD_OF_VIEW REAL NULL,
                        VIEW_DISTANCE REAL NULL,
                        MAX_RENDERS INT NOT NULL
                    );"""

        cursor.execute(query)
        cursor.close()
    except sqlite3.Error as error:
        print('Error! Unable to execute the query:\n', error)
    finally:
        if db_connection:
            db_connection.close()
# end create_default_tables


# This exports the modules, which allows the functions to be called.
if __name__ == '__main__':
    globals()[sys.argv[1]]()