#include "advanced_sql_query_builder.h"

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddWhereGreaterThan(std::string _column, std::string _condition) {
    if (where.empty()) {
        where += " WHERE " + _column + ">" + _condition;
    }
    else {
        where += " AND " + _column + ">" + _condition;
    }
    return *this;
}

AdvancedSqlSelectQueryBuilder& AdvancedSqlSelectQueryBuilder::AddWhereLessThan(std::string _column, std::string _condition) {
    if (where.empty()) {
        where += " WHERE " + _column + "<" + _condition;
    }
    else {
        where += " AND " + _column + "<" + _condition;
    }
    return *this;
}