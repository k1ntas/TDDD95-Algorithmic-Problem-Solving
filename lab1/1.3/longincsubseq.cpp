#include <vector>
#include <iostream>

std::vector<int> lis(std::vector<int> &object);


int main(){
    int n;
    
    while(scanf("%d", &n) == 1){
        std::vector<int> items;
        int item;
        for(int i = 0; i < n; i++){
            scanf("%d", &item);
            items.push_back(item);
        }

    }

}

//https://cp-algorithms.com/dynamic_programming/longest_increasing_subsequence.html
std::vector<int> lis(std::vector<int> &object){
    std::vector<std::vector<int>> buckets;
    int n {object.size()};
    for(int i = 0; i < n; i++){
        if(object[i] > buckets[n - 1][0]){


        }
    }
}




