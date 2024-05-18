#pragma once
#include <iostream>
#include <map>
#include <vector>

class SqlSelectQueryBuilder {
protected:
	std::string query;
	std::string column = "";
	std::string from = "";
	std::string where = "";

public:
	SqlSelectQueryBuilder& AddColumn(std::string _column);
	SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& _columns) noexcept;
	SqlSelectQueryBuilder& AddFrom(std::string _from);
	SqlSelectQueryBuilder& AddWhere(std::string _column, std::string _condition);
	SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& _kv) noexcept;
	std::string BuildQuery();
};