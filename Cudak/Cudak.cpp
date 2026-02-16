#include <vector>
#include <iostream>
#include <cstring>

long long r_solver(int digit, int S, int current_sum, bool restraint);
long long count(long long limit, int S);

long long table[16][2][136];      //3D array 
std::string upper_bound;              


int main(){
    long long A;
    long long B;
    long long S;

    
    scanf("%lld %lld %lld", &A, &B, &S);
    long long resultA{count(A - 1, S)};

    long long resultB{count(B, S)};

    long long number_of_integers{resultB - resultA};

    long long min{A};
    long long max{B};
    long long smallest{B};

    while(min <= max){
        long long mid{min + (max - min)/2};
        if(count(mid, S) - resultA >=1){
            smallest = mid;
            max = mid - 1;
        }else{
            min = mid + 1;
        }
    } 
    printf("%lld \n", number_of_integers);   
    printf("%lld ", smallest);        
}

long long r_solver(int digit, int S, int current_sum, bool restraint){
    if(S < current_sum) {
        return 0;
    }

    if(digit == upper_bound.size()){
        return (current_sum == S);
    }
    if(table[digit][restraint][current_sum] != -1){
        return table[digit][restraint][current_sum];
    }

    long long answer{0};
    int max_digit{9};
    if(restraint){
        max_digit = upper_bound[digit] - '0';
    }

    for(int i{0}; i <= max_digit; i++){
        answer += r_solver(digit + 1, S, current_sum + i, restraint && (i == max_digit));
    }


    return table[digit][restraint][current_sum] = answer;
}

long long count(long long limit, int S){
    if(limit < 0){
        return 0;
    }
    std::memset(table, -1, sizeof(table));
    upper_bound = std::to_string(limit);
    return r_solver(0, S, 0, true);
}
