#include <string> 
#include <iostream>
#include <map>
#include <vector>

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

void print_map(std::map<std::string, std::vector<std::string>> map){
    std::cout << "start of map: " << std::endl;
    for(const auto& kv : map ){
        std::cout << kv.first << " : ";
        for(const auto& e : kv.second){
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "end of map" << std::endl;
}

int main() {
    int number_of_phrases;
    //std::getline(std::cin, pattern1);
    std::cin >> number_of_phrases;
    std::cin.ignore();
    std::vector<std::string> words1;
    std::vector<std::string> words2;

    for(int i = 0; i < number_of_phrases; i++){
        std::string pattern1;
        std::getline(std::cin, pattern1);
        std::string pattern2;
        std::getline(std::cin, pattern2);
        
        //-------------------------------------------TEST INPUT
        //pattern1 = "how now brown <animal>";
        //pattern2 = "<foo> now <color> cow";

        //Cancer test cases

        pattern1 = "a b <a> c <a> d <a> e <a> f";
        pattern2 = "<a> b <a> c <y> d <z> e <q> f";
        //-------------------------------------------
        std::string delimiter = " ";
        
        

        //std::multimap<std::string, std::string> pattern_map; 
        
        //std::cout << pattern1 << std::endl;
        //std::cout << pattern2 << std::endl;

        std::map<std::string, std::vector<std::string>> pattern_map1;
        std::map<std::string, std::vector<std::string>> pattern_map2;
        bool swap = true;

        while(swap){
            words1 = split_string_on(pattern1, delimiter);
            words2 = split_string_on(pattern2, delimiter);
            swap = false;

            for(int i = 0; i < words1.size(); i++){
                //std::cout << i << std::endl;
                //std::cout << words1[i][0] << std::endl;
                if(words1[i].find("<") != std::string::npos){
                    //std::cout << i << std::endl;
                    if(pattern_map1.find(words1[i]) != pattern_map1.end()){
                        
                        for(auto& word: words1){
                            if(word.find("<") == std::string::npos){
                                std::cout << "-" << std::endl;
                                goto next_pattern;
                            }
                        }

                        pattern_map1.at(words1[i]).push_back(words2[i]);
                    } else {
                        std::vector<std::string> new_key;
                        pattern_map1.insert(std::pair(words1[i], new_key)); 
                        pattern_map1.at(words1[i]).push_back(words2[i]);
                    }
                    
                }
                if(words2[i].find("<") != std::string::npos){
                    if(pattern_map2.find(words2[i]) != pattern_map2.end()){

                        for(auto& word: words1){
                            if(word.find("<") == std::string::npos){
                                std::cout << "-" << std::endl;
                                goto next_pattern;
                            }
                        }

                        pattern_map2.at(words2[i]).push_back(words1[i]);
                    } else {
                        std::vector<std::string> new_key;
                        pattern_map2.insert(std::pair(words2[i], new_key)); 
                        pattern_map2.at(words2[i]).push_back(words1[i]);
                    }
                }
                //std::cout << std::to_string(i) << std::endl;
                //std::cout << words1[i] << std::endl;
            }

            /*
            for(auto& kv : pattern_map1){
                if(kv.first.find("<") != std::string::npos && kv.second.find("<") != std::string::npos){
                    if(pattern_map2.find(kv.second) != pattern_map2.end())
                    pattern_map1.swap()
                }
            }  
            */

            

            for(auto& word: words1){
                if(word.find("<") != std::string::npos){
                    auto it = pattern_map1.find(word);
                    if(it != pattern_map1.end() && !it->second.empty()){
                        word = it->second[0];
                        swap = true;
                    }
                    
                }
            }

            for(auto& word: words2){
                if(word.find("<") != std::string::npos){
                    auto it = pattern_map2.find(word);
                    if(it != pattern_map2.end() && !it->second.empty()){
                        word = it->second[0];
                        swap = true;
                    }
                    
                }
            }

            pattern1 = words1[0];
            pattern2 = words2[0];
            for(int i = 1; i < words1.size(); i++){
                pattern1 += " " + words1[i];
                pattern2 += " " + words2[i];
            }

        }
        //print_map(pattern_map1);
        //print_map(pattern_map2);
        
        std::cout << pattern1 << std::endl;
        //std::cout << pattern2 << std::endl;
        next_pattern: ;

    }

    return 0;
}

 

