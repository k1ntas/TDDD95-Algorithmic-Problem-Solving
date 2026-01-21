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

std::map<std::string, std::string> parent;
std::map<std::string, std::string> root;

std::string recursive_solve(std::string s){
    if(parent.find(s) == parent.end()){
        return parent[s] = s;
    }
    if(parent[s] == s){
        return s;
    }
    return parent[s] = recursive_solve(parent[s]);
}

bool resolve(std::string s1, std::string s2){
    
    //check if actual word
    bool p1 = (s1.find("<") != std::string::npos);
    bool p2 = (s2.find("<") != std::string::npos);

    //2 actual words
    if (!p1 && !p2) {
        //check if same word
        return s1 == s2;
    }
        

    //1 is actual word
    if(p1 && !p2){
        std::string first_word = recursive_solve(s1);
        if (root.count(first_word) && root[first_word] != s2){
            return false;
        }
        root[first_word] = s2;
        return true;
    } 


    if(!p1 && p2){
        std::string second_word = recursive_solve(s2);
        if (root.count(second_word) && root[second_word] != s1){
            return false;
        }
        root[second_word] = s1;
        return true;
    }
    
    //2 temps 
    std::string first_word = recursive_solve(s1);
    std::string second_word = recursive_solve(s2);

    //they are the same
    if( first_word == second_word){
        return true;  
    } 
    
    if(root.count(first_word) && root.count(second_word) && root[first_word] != root[second_word]){
        return false;
    }

    parent[second_word] = first_word;

    if(root.count(second_word)){
        root[first_word] = root[second_word];
    }

    return true;

    
}

int main() {
    int number_of_phrases;
    //std::getline(std::cin, pattern1);
    std::cin >> number_of_phrases;
    std::cin.ignore();
    std::vector<std::string> words1;
    std::vector<std::string> words2;

    for(int x = 0; x < number_of_phrases; x++){
        std::string pattern1;
        std::getline(std::cin, pattern1);
        std::string pattern2;
        std::getline(std::cin, pattern2);
        parent.clear();
        root.clear();
        //-------------------------------------------TEST INPUT
        //pattern1 = "how now brown <animal>";
        //pattern2 = "<foo> now <color> cow";

        //Test cases

        //pattern1 = "a b <a> c <a> d <a> e <a> f";
        //pattern2 = "<a> b <a> c <y> d <z> e <q> f";

        
        //pattern1 = "<a> b";
        //pattern2 = "c <a>";

        //pattern1 = "a b c";
        //pattern2 = "<a> <c> <a>";
        //-------------------------------------------
        std::string delimiter = " ";
        
        
            words1 = split_string_on(pattern1, delimiter);
            words2 = split_string_on(pattern2, delimiter);
            bool possible = true;
            if(words1.size() != words2.size()){
                std::cout << "-" << std::endl;
                continue;
            }

            for(auto& word : words1){
                if(word.find("<") != std::string::npos){
                    word = "1_" + word;
                }
            }
            for(auto& word : words2){
                if(word.find("<") != std::string::npos){
                    word = "2_" + word;
                }
            }


            for(int i = 0; i < words1.size(); i++){
                std::string tmp1 = words1[i];
                std::string tmp2 = words2[i];

                if(!resolve(tmp1, tmp2)){
                    possible = false;
                }
            }
            
            
            if(!possible){
                std::cout << "-" << std::endl;
                continue;
            }else{
                for(int i = 0; i < words1.size(); i++){
                    
                    
                    if(words1[i].find("<") != std::string::npos){
                        std::string tmp = recursive_solve(words1[i]);
                        if(root.count(tmp)){
                            words1[i] = root[tmp];
                        } else{
                            words1[i] = "temp";
                        }
                    }
                }
            }   

            
            pattern1 = words1[0];
            pattern2 = words2[0];
            for(int i = 1; i < words1.size(); i++){
                pattern1 += " " + words1[i];
                pattern2 += " " + words2[i];
            }
            
        std::cout << pattern1 << std::endl;
    }
    return 0;
}

 

