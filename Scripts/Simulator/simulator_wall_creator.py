
import sys
import sqlite3

# Update this path to the actual database for the project
db_path = "./Assets/philos.db"

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

def create_simulator_map_walls_v1():
    num_walls = int(sys.argv[2])
    print(f"Creating {num_walls} walls, in a straight line, 300 apart...")

    query = '''insert into Simulator_Map(id, type, name,
                                         position_x, position_y, position_z,
                                         scale_x, scale_y, scale_z,
                                         rotation_angle,
                                         rotation_axis_x, rotation_axis_y, rotation_axis_z)
                                         Values(?,?,?,
                                                ?,?,?,
                                                ?,?,?,
                                                ?,
                                                ?,?,?)'''
    distance_between_walls = 300
    id_val = 0
    type_val = "simulator_wall"
    name_val = "wall_" + str(id_val)
    left_position_x = str(distance_between_walls)
    right_position_x = str(-distance_between_walls)
    position_y = "0"
    position_z = distance_between_walls
    scale_x = "100"
    scale_y = "420"
    scale_z = "75"
    rotation_angle = "90"
    rotation_axis_x = "0"
    rotation_axis_y = "0"
    rotation_axis_z = "1"
    left_walls = []
    right_walls = []

    print("Making the walls...")
    for i in range(0, num_walls):
        left_walls.append((str(id_val), type_val, name_val,
                           left_position_x, position_y, str(position_z),
                           scale_x, scale_y, scale_z,
                           rotation_angle,
                           rotation_axis_x, rotation_axis_y, rotation_axis_z))

        right_walls.append((str(id_val), type_val, name_val,
                           right_position_x, position_y, str(position_z),
                           scale_x, scale_y, scale_z,
                           rotation_angle,
                           rotation_axis_x, rotation_axis_y, rotation_axis_z))

        id_val += 1
        name_val = "wall_" + str(id_val)
        position_z = position_z + distance_between_walls

    print("inserting into the db...:")
    _run_query_with_values(query, left_walls)
    _run_query_with_values(query, right_walls)
    print("finished! verify...")
# end create_simulator_map_walls_v1




# This exports the modules, which allows the functions to be called.
if __name__ == '__main__':
    create_simulator_map_walls_v1()
