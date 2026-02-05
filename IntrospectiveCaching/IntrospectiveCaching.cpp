#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <set>

std::vector<int> data;
std::map<int, std::queue<int>> cache_map;
std::vector<bool> in_cache;
std::vector<int> valid_index;


int main(){
    int c;
    int n;
    int a;

    while(scanf("%d %d %d", &c, &n, &a) == 3){
        data.clear();
        int x;
        valid_index.assign(n, -1);
        in_cache.assign(n, false);
        for(int i = 0; i < a; i++){
            scanf(" %d", &x);
            data.push_back(x);
            if(cache_map.count(x)){
                cache_map[x].push(i);
            } else{
                std::queue<int> q;
                q.push(i);
                cache_map.insert({x, q});
            }
        }
        
        int accesses {0};
        int size {0};
        std::priority_queue<std::pair<int ,int>> prio;      //{next index, data}
        for(int i = 0; i < data.size(); i++){
            int d = data[i];
            cache_map[d].pop(); //Remove current element
            int next_index = cache_map[d].empty() ?  100001 : cache_map[d].front(); //no next index is represented with a big number so it will be first out

            if(in_cache[d]){ //Cache hit

                valid_index[d] = next_index;
                prio.push({next_index, d});
                
            } else{
                accesses++;
                if(size == c){//Full
                    
                    while(!prio.empty()){
                        std::pair<int, int> top = prio.top();
                        prio.pop();

                        if(in_cache[top.second] && valid_index[top.second] == top.first){
                            in_cache[top.second] = false;      //The valid index is removed 
                            size--;
                            break;
                        }
                    }  
                }
                in_cache[d] = true;
                prio.push({next_index,d});
                valid_index[d] = next_index;
                size++;
                
            }
        }
        printf("%d", accesses);
    }
}