#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <set>

std::vector<int> data;
std::map<int, std::queue<int>> cache_map;
std::map<int, int> in_cache;
//std::priority_queue<int> cache;


int main(){
    int c;
    int n;
    int a;

    while(scanf("%d %d %d", &c, &n, &a) == 3){
        data.clear();
        int x;
        for(int i = 0; i < n; i++){
            scanf(" %d", &x);
            data.push_back(x);
            cache_map[x].push(i);
        }
        
        int accesses {0};
        std::priority_queue<std::pair<int ,int>> prio;
        //std::set<std::pair<int, int>> cache;
        for(int i = 0; i < data.size(); i++){
            int d = data[i];

            if(in_cache[d] != 0){ //Cache hit
                
                prio.push({cache_map.at(d).front(),d});
                cache_map.at(d).pop();
                in_cache[d]++;

            } else{
                if(in_cache.size() < c){//Not full
                    prio.push({i,d});
                    in_cache[i]++;      
                }else{
                    accesses++;
                    if(in_cache[prio.top().second] == 1){ //only one istance of the first element
                        
                    }
                    

                }

            }
        }

    }

}