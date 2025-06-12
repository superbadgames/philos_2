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

        inline void SetDB(const string& path) { _dbPath = path; }

        void LoadConfigurations(int(*callback)(void* inputObj, int argCount, char** argValues, char** colName));

    private:
        static p_DatabaseManager _instance;
        string _dbPath;
        sqlite3* _db;

        bool _Open(void);

        void _Close(void);

        DatabaseManager(void);

        DatabaseManager(const DatabaseManager& copy);

        DatabaseManager& operator=(const DatabaseManager& copy);
    };
}