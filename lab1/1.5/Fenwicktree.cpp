#include <vector>
#include <iostream>

void add(int index, int delta);
long long sum(int end);

std::vector<long long> data;
int main(){
    int n;
    int q;

    while(scanf("%d %d", &n, &q) == 2){

        //data.resize(n);
        //std::fill(data.begin(), data.end(), 0);
        data.assign(n ,0);
        
        char op;
        int a;
        int b;
        
        for(int i = 0; i < q; i++){
            
            if(scanf(" %c", &op) == 1){
                if(op == '+'){
                    scanf(" %d %d", &a, &b);
                    add(a, b);
                }else if(op == '?'){
                    scanf(" %d", &a);
                    if(a == 0){
                        printf("%d", 0);
                    }else {
                        printf("%lld",sum(a - 1));    //Do not include the actual index
                    }
                    
                    printf("%c", '\n');
                }
            } else {
                return -1;
            }

        }

    }

}




//Use the bitwise and operator to loop add upp the correct elements
//in the fenwick tree to calculate the sum of the elements
long long sum(int end){
    long long sum = 0;
    for(; end >= 0; end = (end & (end + 1)) - 1){
        sum += data[end];
    }
    return sum;
}

//Uses the bitwise or operator to navigate the fenwick tree (increasing index)
void add(int index, int delta){
    for(; index < data.size(); index = index | index + 1){
        data[index] += delta;
    }
}