#include "sql_query_builder.h"

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(std::string _column) {
    if (column.empty()) {
        column += "SELECT " + _column;
    }
    else {
        column += ", " + _column;
    }
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumns(const std::vector<std::string>& _columns) noexcept {
    for (auto& _column : _columns) {
        if (column.empty()) {
            column += "SELECT " + _column;
        }
        else {
            column += ", " + _column;
        }
    }
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(std::string _table) {
    if (from.empty()) {
        from += " FROM " + _table;
    }
    else {
        std::cout << "the table has already been selected.\n";
    }
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(std::string _column, std::string condition) {
    if (where.empty()) {
        where += " WHERE " + _column + "=" + condition;
    }
    else {
        where += " AND " + _column + "=" + condition;
    }
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::map<std::string, std::string>& _kv) noexcept
{
    for (const auto _k : _kv) {
        if (where.empty()) {
            where += " WHERE " + _k.first + "=" + _k.second;
        }
        else {
            where += " AND " + _k.first + "=" + _k.second;
        }
    }

    return *this;
}

std::string SqlSelectQueryBuilder::BuildQuery() {
    if (!query.empty()) {
        query.clear();
    }
    query = column + from + where + ";";
    return query;
}