#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <numeric>




int find_power(int input){
    //std::cout << "in: " << input << std::endl;
    long long value = input;
    bool negative{false};
    if(input < 0){
        negative = true;
        value = std::abs(value);
    }
    
    for(int i{32}; i >= 1; i--){
        double x = std::pow(value, 1.0/i);
        int a = floor(x);
        int b = ceil(x);

        //std::cout << "i: " << i << " a: " << a << " b: " << b << " x: " << x << std::endl;
        
        if(std::pow(a, i) == value){
            if(!negative){
                return i;
            }else if(i%2 == 1){
                return i;
            }
            
        }else if(std::pow(b, i) == value){
            if(!negative){
                return i;
            }else if(i%2 == 1){
                return i;
            }
        }
    }
    return 0;

}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int input;

    while(std::cin >> input){
        if(input == 0) return 0;
        
        std::cout << find_power(input) << '\n';

    }

}



