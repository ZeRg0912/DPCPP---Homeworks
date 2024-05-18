#include <iostream>
#include "sql_query_builder.h"
#include "advanced_sql_query_builder.h"

int main() {
    std::vector<std::string> columns = { "name", "phone" };
    std::map<std::string, std::string> where = {
        {"id","42"},
        {"name","John"}
    };

    AdvancedSqlSelectQueryBuilder query_builder;
    query_builder.AddColumns(columns);
    query_builder.AddFrom("students");
    query_builder.AddWhereGreaterThan("id", "42");

    std::string query = query_builder.BuildQuery();
    std::string example = "SELECT name, phone FROM students WHERE id>42;";

    if (query == example) {
        std::cout << "Query is:\n" << query << "\n" << "All ok!" << std::endl;
    }
    else {
        std::cout << "Anything go wrong! True query is:\n" << example << std::endl;
    }

    return 0;
}