#include <vector>
#include <iostream>
//Author:   Simha158 Simon Hansson

//Problem:  Longest increasing subsequence (https://liu.kattis.com/courses/AAPS/AAPS26/assignments/wunfda/problems/longincsubseq) 
//          Find the longest increasing subsequence from a sequence of numbers.

//Sources:  I used (https://cp-algorithms.com/dynamic_programming/longest_increasing_subsequence.html) as an insperation
//          for the implementation of the longest increasing subsequence algorithm.


//Algorithm:    We have a vector of piles which each represent a subsequence. We iterate 
//              the original sequence and if the current element is bigger than all elements
//              the piles we create a new one other wise we replace the smallest pile 
//              that is larger than the current.

//Time complex: O(n log n)  

//Practiacal instructions: Will return the indexes and not the actual sequence

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

        std::vector<int> result = lis(items);

        printf("%d \n",result.size());
        for(auto& item : result){
            printf("%d ", item);           
        }
        printf("\n");


    }



}


std::vector<int> lis(std::vector<int> &object){
    size_t n {object.size()};
    if(n == 0){
        return {};
    }
    std::vector<int> piles;
    std::vector<int> parent(n, -1);

    piles.push_back(0); //First index
    for(size_t i = 1; i < n; i++){

        //Find the index of the biggest smaller pile //Binary search O(n log n)
        int left_most_piles = std::lower_bound(piles.begin(), piles.end(), object[i], [&](int index, int current){
            return object[index] < current;
        }) - piles.begin();

        //Set the parent
        if(left_most_piles > 0){
            parent[i] = piles[left_most_piles - 1];
        }

        //Check if it is the largest element found
        if(left_most_piles == piles.size()){
            piles.push_back(i);
        }else {
            piles[left_most_piles] = i;
        }

    }

    //Reconstruct the indexes
    std::vector<int> result;
    int current = piles.back();
    while(current != -1){
        result.push_back(current);
        current = parent[current];
    }

    std::reverse(result.begin(), result.end());

    return result;
}




