#include <vector>
#include <iostream>


int main(){
    int n;

    while(scanf("%d", &n) == 1){
        std::vector<int> items;
        int item;
        for(int i = 0; i < n; i++){
            scanf("%d", &item);
            items.push_back(item);
        }

        std::vector<int> result = solver(items);

        for(auto& item : result){
            printf("%d ", item);           
        }
        printf("\n");

    }

}

std::vector<int> solver(std::vector<int> &input){
    std::vector<int> result = input;
    return result;
}
