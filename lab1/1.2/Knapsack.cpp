#include <vector>
#include <iostream>

//Author:   Simha158 Simon Hansson

//Problem:  Knacpsack (https://liu.kattis.com/courses/AAPS/AAPS26/assignments/wunfda/problems/knapsack) 
//          Fill a sack with as much value as possible. It has a certain capacity and
//          you need to find the best subset of items to put in it. Each item has a 
//          weight and value associated with it.

//Sources:  I used (https://www.geeksforgeeks.org/dsa/0-1-knapsack-problem-dp-10/) as an insperation
//          for the implementation of the knapsack algorithm.


//Algorithm:    You go through all items and make the choice to either add them to
//              the sack or leave them out. The decision is based on if including the 
//              current item gives more value at the current value than all other options.

//Time complex: O(n*c)    c=capacity

//Practiacal instructions:  Can handle about 16 000 * 16 000 input before memory exceeds 1 GB
//                          Expect an input of vector<pair<value, weight>>

std::vector<int> knapsack(int capacity, std::vector<std::pair<int,int>> &items);

//Handles input and output to the terminal and calls the solver
int main(){

    double C, n;

    while(std::cin >> C >> n){
       
        int value;
        int weight;

        std::vector<std::pair<int,int>> items;

        for(int i = 0; i < n; i++){
            std::cin >> value;
            std::cin >> weight;
            std::pair<int,int> item = {value,weight};

            
            items.push_back(item);
        }
        std::vector<int> result = knapsack(C, items);

        std::cout << result.size() << std::endl;
        for (int i = result.size() - 1; i >= 0; i--)
        {
            std::cout << result[i] << " ";
        }
        
         std::cout << std::endl;
    }

}


//The solver for the knapsack algorithm
//Returns the indexes of the choosen values not the values.
std::vector<int> knapsack(int capacity, std::vector<std::pair<int,int>> &items){
    int n {items.size()};
    std::vector<std::vector<int>> result(n + 1, std::vector<int>(capacity + 1, 0));

    for (size_t i {1}; i <= n; i++)
    {
        for(size_t j = 0; j <= capacity; j++){

            if(i == 0 || j == 0){ //no items or capacity = 0
                result[i][j];
            } else{
                int pick {0};

                
                if(items[i - 1].second <= j){
                    pick = items[i - 1].first + result[i - 1][j - items[i - 1].second];
                }
                int notPick = result[i - 1][j];
                //Decide if we should pick the item or not
                result[i][j] = std::max(pick, notPick);
            }
            
        }
    }


    //Go through the 2D table and find what indexes where used
    //An index was used if the value changed from the previous row
    std::vector<int> indexes;
    int c {capacity};
    for(int i = n; i > 0; i--){
        if(result[i][c] != result[i - 1][c]){
            indexes.push_back(i -  1);
            c -= items[i - 1].second;
        }

    }

    return indexes;
}