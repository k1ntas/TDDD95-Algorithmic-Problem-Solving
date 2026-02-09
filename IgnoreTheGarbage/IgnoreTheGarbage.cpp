#include <vector>
#include <iostream>
#include <string>



std::vector<char> base7{'0','1','2','5','6','8','9'};


std::string convert7(int number){
    std::string new_number;
    
    while(number > 0){
        auto div = std::div(number, 7);
        new_number += base7[div.rem];
        number = div.quot;
    }
    return new_number;
}



std::string flip(std::string number){
    std::string fliped;
    for(int i = 0; i < number.size(); i++){
        switch (number[i]) {
            case '0' :
                fliped += '0';
                break;
            case '1' :
                fliped += '1';
                break;
            case '2' :
                fliped += '2';
                break;
            case '5' :
                fliped += '5';
                break;
            case '6' :
                fliped += '9';
                break;
            case '8' :
                fliped += '8';
                break;
            case '9' :
                fliped += '6';
                break;
        }
    }
    return fliped;
}

int main(){
    int input;

    while(scanf("%d", &input) == 1){
        std::string tmp = convert7(input);
        tmp = flip(tmp);

        std::cout << tmp << '\n';
    }

}





