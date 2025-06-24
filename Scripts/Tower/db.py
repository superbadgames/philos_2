"""
- Connect to the sqlite3 database
- Create all the tables that the Tower engine is going to assume are there, and
populate it with the needed default values, that can be changes later per project


"""
import sys
import sqlite3

# Update this path to the actual database for the project
db_path = "./Assets/philos.db"


def _run_query(query):
    try:
        db_connection = sqlite3.connect(db_path)
        cursor = db_connection.cursor()
        print("Successfully connected to the database\n")

        cursor.execute(query)

        cursor.close()
    except sqlite3.Error as error:
        print('Error! ', error)
    finally:
        if db_connection:
            db_connection.close()
# end _run_query


def _run_query_with_values(query, values):
    try:
        db_connection = sqlite3.connect(db_path)
        cursor = db_connection.cursor()
        print("Successfully connected to the database\n")

        cursor.executemany(query, values)
        db_connection.commit()

        cursor.close()
    except sqlite3.Error as error:
        print('Error! ', error)
    finally:
        if db_connection:
            db_connection.close()
# end _run_query


def _display_table(table):
    try:
        db_connection = sqlite3.connect(db_path)
        cursor = db_connection.cursor()
        print("Successfully connected to the database\n")

        cursor.execute('Select * from ' + table + ';')

        for row in cursor:
            print(row)

        cursor.close()
    except sqlite3.Error as error:
        print('Error! ', error)
    finally:
        if db_connection:
            db_connection.close()
# end _run_query


def create_default_tables():
    # Create Tower_Config table
    query = '''Create Table if not exists Tower_Config(
                    id int primary key not null,
                    name text null,
                    type text null,
                    value blob null
                );
                '''
    _run_query(query)

    # Insert default values
    configs = [
        ('1', 'window_width', 'U32', '1200'),
        ('2', 'window_height', 'U32', '800'),
        ('3', 'max_entities', 'U32', '2000'),
        ('4', 'field_of_view', 'F32', '45'),
        ('5', 'view_distance', 'F32', '5000'),
        ('6', 'project_name', 'string', 'Project_Philos')
    ]

    query = '''Insert Into Tower_Config(id, name, type, value) Values(?,?,?,?)'''

    _run_query_with_values(query, configs)

    _display_table("Tower_Config")
# end create_default_tables


def create_map():
    table_name = sys.argv[2]
    print(f"table name = {table_name}")

    query = (f"Create Table if not exists {table_name}("
             "id int not null,"
             "type text not null,"
             "parent_type text not null,"
             "name text not null,"
             "position_x real not null,"
             "position_y real not null,"
             "position_z real not null,"
             "scale_x real not null,"
             "scale_y real not null,"
             "scale_z real not null,"
             "rotation_angle real not null,"
             "rotation_axis_x real not null,"
             "rotation_axis_y real not null,"
             "rotation_axis_z real not null);"
            )

    _run_query(query)
    _display_table(table_name)
    print("Finished creating new Map table\n\n")
# end create_map_tablele


# This exports the modules, which allows the functions to be called.
if __name__ == '__main__':
    globals()[sys.argv[1]]()