#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "sqlite3/sqlite3.h"

namespace Tower
{
    class DatabaseManager;
    typedef shared_ptr<DatabaseManager> p_DatabaseManager;

    class DatabaseManager
    {
    public:
        ~DatabaseManager(void);

        static p_DatabaseManager Instance(void);

        void OpenDatabase(const string& path);

    private:
        static p_DatabaseManager _instance;
        sqlite3* _db;

        DatabaseManager(void);

        DatabaseManager(const DatabaseManager& copy);

        DatabaseManager& operator=(const DatabaseManager& copy);
    };
}