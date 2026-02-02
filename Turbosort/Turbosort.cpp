#include <vector>
#include <iostream>

void add(int index, int delta);
long long sum(int end);


std::vector<int> data;
std::vector<int> ftree;


int main(){
    int n;

    while(scanf("%d", &n) == 1){
        data.clear();
        data.assign(n + 1, 0);
        ftree.assign(n, 0);
        int a;

        
        for(int i = 0; i < n; i++){
            scanf(" %d", &a);
            data[a] = i;
            add(i ,1 );
        }
        
        
        
        int odd = n;
        int even = 1;
        
        for(int i = 1; i <= n; i++){
            
            if(i % 2 != 0){
                printf("%lld", sum(data[even] - 1));
                add(data[even], -1);
                even++;
            } else{
                printf("%lld",  sum(n - 1) - sum(data[odd]));
                add(data[odd], -1);
                odd--;
            }

            printf("%c",'\n');
        }

    }

}



//Use the bitwise and operator to loop add upp the correct elements
//in the fenwick tree to calculate the sum of the elements
long long sum(int end){
    long long sum = 0;
    for(; end >= 0; end = (end & (end + 1)) - 1){
        sum += ftree[end];
    }
    return sum;
}

//Uses the bitwise or operator to navigate the fenwick tree (increasing index)
void add(int index, int delta){
    for(; index < ftree.size(); index = index | index + 1){
        ftree[index] += delta;
    }
}