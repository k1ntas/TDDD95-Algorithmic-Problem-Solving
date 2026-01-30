#include <vector>
#include <iostream>

//Author:   Simha158 Simon Hansson

//Problem:  Union-find (https://liu.kattis.com/courses/AAPS/AAPS26/assignments/wunfda/problems/unionfind) 
//          There are 2 operations:
//          Check if 2 numbers belong to the same set
//          Link 2 sets together

//Sources:  I used (https://cp-algorithms.com/data_structures/disjoint_set_union.html) as an insperation
//          for the implementation of the union find algorithm.


//Algorithm:    We have an vector where each index represents a sub set. All sets start separate
//              and with the union operation we link them together by setting the value at thier
//              index to thier new parent.


//Time complex: O(log n) for both Union() and same()

//Practical instructions:

int find(int a);

void Union(int a, int b);

bool same(int a, int b);

std::vector<int> parent;

int main(){
    int n;
    int q;

    while(scanf("%d %d", &n, &q) == 2){
        parent.clear();
        for(int i = 0; i <= n; i++){
            parent.push_back(i);
        }
        
        char op;
        int a;
        int b;
        
        for(int i = 0; i < q; i++){
            
            if(scanf(" %c %d %d", &op, &a, &b) == 3){
                if(op == '='){
                    Union(a, b);
                }else if(op == '?'){
                    if(same(a, b)){
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

//Recursive search to the "root" node and also compresses the tree structure
int find(int a){
    if(parent[a] == a){
        return a;
    }
    return parent[a] = find(parent[a]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        parent[b] = a;
    }
}

bool same(int a, int b){
    return find(a) == find(b);
}

