#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <array>
#include <algorithm>


int main(){


    int number_of_children;
    long long candies;
    unsigned long long total_deficit = 0;

    std::cin >> candies;
    std::cin >> number_of_children;
    
    std::vector<int> kids;
    int tmp;
    for(int i = 0; i < number_of_children; i++){
        std::cin >> tmp;
        total_deficit += tmp;
        kids.push_back(tmp);
    }
    
    total_deficit -= candies;
    std::sort(kids.begin(), kids.end());
    unsigned long long sum = 0;
    for(auto& want : kids){
        unsigned long long average_deficit = total_deficit/number_of_children;
        unsigned long long current = std::min((unsigned long long) want, average_deficit);
        
        sum += (current)*(current);
        total_deficit -= current;
        number_of_children--;
    }

        


    std::cout << sum; 

}