#include <string> 
#include <iostream>
#include <map>

std::vector<std::string> split_string_on(std::string s, std::string delimiter){
    size_t pos = 0;
    std::string word;
    std::vector<std::string> words;
    while( (pos = s.find(delimiter)) != std::string::npos){
        word = s.substr(0, pos);
        words.push_back(word);
        s.erase(0, pos + delimiter.length());
    }
    word = s.substr(0, pos);
    words.push_back(word);
    return words;
}

int main() {
    int number_of_phrases;
    //std::getline(std::cin, pattern1);
    std::cin >> number_of_phrases;
    std::cin.ignore();
    std::vector<std::string> words1;
    std::vector<std::string> words2;


    std::string pattern1;
    std::getline(std::cin, pattern1);
    std::string pattern2;
    std::getline(std::cin, pattern2);
    

    std::string delimiter = " ";
    
    words1 = split_string_on(pattern1, delimiter);
    words2 = split_string_on(pattern2, delimiter);

    std::map<std::string, std::string> pattern_map; 
    
    std::cout << pattern1 << std::endl;
    std::cout << pattern2 << std::endl;
    for(int i = 0; i < words1.size(); i++){
        std::cout << std::to_string(i) << std::endl;
        std::cout << words1[i] << std::endl;
    }
     

    return 0;
}

