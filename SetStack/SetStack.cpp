#include <vector>
#include <iostream>
#include <stack>
#include <set>
#include <map>
#include <algorithm>


// represent all the sets as a number instead to not have to use recursive data structures
std::map<std::set<int>, int> unique_set;
std::vector<std::set<int>> sets;
std::stack<int> stack;


int get_set_id(std::set<int> set){
    if(unique_set.count(set)){
        return unique_set[set];
    }
    sets.push_back(set);
    unique_set[set] = sets.size() - 1;
    return sets.size() - 1;

}


int main(){
    int n;

    while(scanf("%d", &n) == 1){
        
        for(int i = 0; i < n; i++){

            std::string op;
            int number_of_op;
            scanf("%d", &number_of_op);
            for(int j = 0; j < number_of_op; j++){
                std::cin >> op;
                if(op == "PUSH"){
                    std::set<int> new_set;
                    stack.push(get_set_id(new_set));

                }else if(op == "DUP"){
                    int id = stack.top();
                    stack.pop();
                    stack.push(id);
                    stack.push(id);
                }else if(op == "UNION"){
                    int id1 = stack.top();
                    stack.pop();
                    int id2 = stack.top();
                    stack.pop();

                    std::set<int> new_set; 
                    std::set_union(sets[id1].begin(), sets[id1].end(), sets[id2].begin(), sets[id2].end(), std::inserter(new_set, new_set.begin()));
                    stack.push(get_set_id(new_set));


                }else if(op == "INTERSECT"){
                    int id1 = stack.top();
                    stack.pop();
                    int id2 = stack.top();
                    stack.pop();

                    std::set<int> new_set; 
                    std::set_intersection(sets[id1].begin(), sets[id1].end(), sets[id2].begin(), sets[id2].end(), std::inserter(new_set, new_set.begin()));
                    stack.push(get_set_id(new_set));

                }else if(op == "ADD"){
                    int id1 = stack.top();
                    stack.pop();
                    int id2 = stack.top();
                    stack.pop();

                    std::set<int> set2 = sets[id2];
                    set2.insert(id1);
                    stack.push(get_set_id(set2));
                }
                std::set<int> top_set = sets[stack.top()];
                printf("%lld \n", top_set.size());
            } 
            printf("***");
            printf("\n");
        }

    }

}