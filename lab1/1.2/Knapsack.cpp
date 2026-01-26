#include <vector>
#include <iostream>

std::vector<int> knapsack(int capacity, std::vector<std::pair<int,int>> &items);

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

        for (size_t i = 0; i < result.size(); i++)
        {
            std::cout << result[i] << std::endl;
        }
        

    }

}


std::vector<int> knapsack(int capacity, std::vector<std::pair<int,int>> &items){
    std::vector<int> result(capacity + 1, 0);

    for (size_t i = 1; i <= items.size(); i++)
    {
        for(size_t j = capacity; j >= items[i-1].second; j--){
            result[j] = std::max(result[j], result[j - items[i - 1].second] + items[i - 1].first);
        }
    }
    return result;
}
