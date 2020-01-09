#include <iostream>
#include <vector>
#include <numeric>
#include "calculator.h"

int Calculator::Calculate(const std::string &value){
    int result = 0;
    
    if(value.empty())
        return 0;

    std::string delimiters = GetDelimiters(value);
    
    std::vector<std::string> numbers;
    if(HasCustomDelimiters(value)){
        std::string newValue = RemoveDelimiterSection(value);
        std::cout << "[DEBUG] New Value: "<< newValue << std::endl;
        numbers = Split(newValue, delimiters);
    }else{
        numbers = Split(value, delimiters);
    }
    
    
    // for(std::string s : numbers){
    //     std::cout << "[DEBUG] numbers: " << s << std::endl;
    // }
    
    std::vector<int> sanitized = SanitizeValues(numbers);
    for(int v : sanitized)
        result += v;
    
    //std::cout << "[DEBUG] result: " << std::endl;
    
    return result;
}

std::vector<std::string> Calculator::Split(const std::string &value, const std::string &delimiters){
    std::cout << "[DEBUG] #### SPLIT ####" << std::endl;
    std::vector<std::string> numbers;
    std::size_t start = 0;
    std::size_t end = 0;

    std::cout << "[DEBUG] Delimiter: " << delimiters << std::endl;
    std::cout << "[DEBUG] Value: " << value << std::endl;

    while((end = value.find_first_of(delimiters, start)) != std::string::npos){
        std::cout << "[DEBUG] pushing...: " << value.substr(start, end - start) << std::endl;
        numbers.push_back(value.substr(start, end - start));
        start = end + 1;
    }

    numbers.push_back(value.substr(start));

    // for(std::string s : numbers){
    //     std::cout << "[DEBUG] numbers: " << s << std::endl;
    // }

    return numbers;
}

std::string Calculator::GetDelimiters(const std::string &value){
    std::string newDelimiter;

    //std::cout << "[DEBUG] value: " << value << std::endl;

    if(HasCustomDelimiters(value)){
        int start = value.find("[", 0) + 1;
        int end = value.find("]", 0);

        newDelimiter = value.substr(start, end - start);

        return newDelimiter;
    }

    return ",\n"; // default delimiters. the \n is one character not two (\ followed by n)
}

bool Calculator::HasCustomDelimiters(const std::string &value){
    std::string customDelimiter = "//";

    if(value.compare(0, customDelimiter.size(), customDelimiter) == 0)
        return true;

    return false;
}

std::string Calculator::RemoveDelimiterSection(const std::string &value){

    std::cout << "[DEBUG] Remove value: " << value << std::endl;
    int start = value.find("]", 0) + 1;

    std::string newValue = value.substr(start, value.size() - start);

    std::cout << "[DEBUG] Remove new value: " << newValue << std::endl;

    return newValue;
}

std::vector<int> Calculator::SanitizeValues(std::vector<std::string> &values){
    std::vector<int> validValues;
    std::vector<int> invalidValues;

    for(std::string s : values){
        int value = std::stoi(s);

        // Apply rules to sanitize values
        // Rule for Negative values
        // Rule for numbers bigger than 1000
        // Input all values -- Output valid values + error message to show, if any.


        if(value < 0)
            invalidValues.push_back(value);
        else
            validValues.push_back(value);
    }

    if(invalidValues.size() > 0){
        std::string errorValues;
        for(int e : invalidValues)
            errorValues += " " + std::to_string(e);

        std::string errorMessage = "Negative values not allowed:" + errorValues;
        throw std::invalid_argument(errorMessage);
    }
        
    return validValues;
}

