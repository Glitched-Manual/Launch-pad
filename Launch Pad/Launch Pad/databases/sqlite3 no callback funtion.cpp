

int RunSqlNoCallback(sqlite3 * db, const char * zSql)
{
    sqlite3_stmt *stmt = NULL;
    int rc = sqlite3_prepare_v2(db, zSql, -1, &stmt, NULL);
    if (rc != SQLITE_OK)
        return rc;

    int rowCount = 0;
    rc = sqlite3_step(stmt);
    while (rc != SQLITE_DONE && rc != SQLITE_OK)
    {
        rowCount++;
        int colCount = sqlite3_column_count(stmt);
        for (int colIndex = 0; colIndex < colCount; colIndex++)
        {
            int type = sqlite3_column_type(stmt, colIndex);
            const char * columnName = sqlite3_column_name(stmt, colIndex);
            if (type == SQLITE_INTEGER)
            {
                int valInt = sqlite3_column_int(stmt, colIndex);
                printf("columnName = %s, Integer val = %d", columnName, valInt);
            }
            else if (type == SQLITE_FLOAT)
            {
                double valDouble = sqlite3_column_double(stmt, colIndex);
                printf("columnName = %s,Double val = %f", columnName, valDouble);
            }
            else if (type == SQLITE_TEXT)
            {
                const unsigned char * valChar = sqlite3_column_text(stmt, colIndex);
                printf("columnName = %s,Text val = %s", columnName, valChar);
                free(valChar);
            }
            else if (type == SQLITE_BLOB)
            {
                printf("columnName = %s,BLOB", columnName);
            }
            else if (type == SQLITE_NULL)
            {
                printf("columnName = %s,NULL", columnName);
            }
        }
        printf("Line %d, rowCount = %d", rowCount, colCount);

        rc = sqlite3_step(stmt);
    }

    rc = sqlite3_finalize(stmt);

    return rc;
}


//open

//no callback method

//close