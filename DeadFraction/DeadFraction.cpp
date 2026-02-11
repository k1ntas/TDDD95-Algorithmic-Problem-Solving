#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <numeric>




std::pair<long long,long long> find_fraction(long long decimal, int decimal_size, long long recurring, int reacurring_size){
    long long numerator {0};
    long long denominator {0};

    
    
    for(int i{0}; i < reacurring_size; i++){
        denominator *= 10;
        denominator += 9;
    }

    for(int i{0}; i < decimal_size; i++){
        denominator *= 10;
    }

    long long p = std::pow(10, reacurring_size);

    numerator = decimal * p + recurring;
    numerator -= decimal;

    //std::cout << "D: " << denominator << " N: " << numerator << '\n';
    int i = std::gcd(denominator, numerator);
    denominator /= i;
    numerator /= i;
    return {numerator, denominator};

}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string input;

    while(getline(std::cin, input)){
        if(input.size() == 1){
            break;
        }
        size_t i {input.find("...")};             //Find second .
        std::string s = input.substr(2 , i - 2);
        //long long decimal {std::stoll(input.substr(2, i - 2))};
        //long long recurring = input[i - 1] - '0';             //Convert to char
        int l = s.length();
        std::pair<long long,long long> best{std::numeric_limits<long long>::max(),std::numeric_limits<long long>::max()};

        for(int j{1}; j <= l; j++){
            //keep track of sizes
            int r{j};                
            int d{l - j};
            long long decimal;
            long long recurring;
            if(d == 0){
                decimal = 0;
                recurring = std::stoll(s.substr(d));
            } else{
                decimal = std::stoll(s.substr(0, d));
                recurring = std::stoll(s.substr(d));
            }
            std::pair<long long,long long> result = find_fraction(decimal, d, recurring , r);
            if(result.second < best.second){
                best = result;
            }

        }


        /*
        std::cout << "D: " << decimal << " R: " << recurring << std::endl;
        
        
        int recurring_size{2};
        int new_r = decimal %10;
        decimal /= 10;
        while(decimal){
            
            recurring *= 10;
            recurring += new_r;
            std::cout << "D: " << decimal << " R: " << recurring <<" Rs: " << recurring_size << std::endl;
            td::pair<long long,long long> result = find_fraction(decimal, recurring , recurring_size);
            if(result.first < best.first){
                best = result;
            }
            new_r = decimal %10;
            decimal /= 10;
            rsecurring_size ++;
        }
        */

        std::cout << best.first << "/" << best.second << '\n';

    }

}



