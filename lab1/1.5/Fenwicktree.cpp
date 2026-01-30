#include <vector>
#include <iostream>

void add(int index, int delta);
int sum(int end);

std::vector<int> data;
int main(){
    int n;
    int q;

    while(scanf("%d %d", &n, &q) == 2){
        data.clear();
        for(int i = 0; i <= n; i++){
            data.push_back(i);
        }
        
        char op;
        int a;
        int b;
        
        for(int i = 0; i < q; i++){
            
            if(scanf(" %c %d %d", &op, &a, &b) == 3){
                if(op == '='){
                }else if(op == '?'){
                    if(true){
                        printf("yes\n");
                    } else{
                        printf("no\n");
                    }
                }
            } else {
                return -1;
            }

        }

    }

}


void add(int index, int delta);

int sum(int end);