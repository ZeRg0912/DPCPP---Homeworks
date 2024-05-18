#pragma once
#include "sql_query_builder.h"

class AdvancedSqlSelectQueryBuilder : public SqlSelectQueryBuilder {
public:
    AdvancedSqlSelectQueryBuilder& AddWhereGreaterThan(std::string _column, std::string condition);
    AdvancedSqlSelectQueryBuilder& AddWhereLessThan(std::string _column, std::string condition);
};