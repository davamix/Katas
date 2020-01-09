#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <vector>

class Calculator{
    private:
    std::vector<std::string> Split(const std::string &value, const std::string &delimiters);
    std::string GetDelimiters(const std::string &value);
    bool HasCustomDelimiters(const std::string &value);
    std::string RemoveDelimiterSection(const std::string &value);
    std::vector<int> SanitizeValues(std::vector<std::string> &values);

    public:
    int Calculate(const std::string &value);
};

#endif
