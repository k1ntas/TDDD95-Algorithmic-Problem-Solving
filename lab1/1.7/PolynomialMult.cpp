#include <vector>
#include <iostream>
#include <complex> 
#include <cmath>


//Author:   Simha158 Simon Hansson

//Problem:  Polynomial multiplication 2 (https://liu.kattis.com/courses/AAPS/AAPS26/assignments/wunfda/problems/polymul2) 
//          We want to multiply 2 polynomials in less time then O(n) which would be 2 trivial loops.

//Sources:  I used (https://cp-algorithms.com/algebra/fft.html) as an insperation
//          for the implementation of the fft and polynomial multiplication.


//Algorithm:    To do this we take the polynomials and use fft to convert them to a point value representation
//              and in this domain we can multiply the polynomials in O(n) time. To achive O(n log n) time for the fft 
//              algorithm we use a divide and conquer aproach. (divide the array down to pairs compute those then add them up)


//Time complex: O(n log n) 

//Practical instructions: I can only hadle polynomials up to about 10^5 due to floating point precision 



template <typename T>
std::vector<T> polymult(std::vector<std::complex<T>> const& p1, std::vector<std::complex<T>> const& p2);

template <typename T>
void fft(std::vector<std::complex<T>> & values, bool invert);

int main(){
    int n;

    while(scanf("%d", &n) == 1){
        int degree1;         
        int degree2;
        std::vector<std::complex<long double>> poly1;
        std::vector<std::complex<long double>> poly2;
        int x;
        scanf("%d", &degree1);
        for(int i = 0; i <= degree1; i++){                 //Faster to allocate degree the add with index?
            scanf("%d", &x);
            poly1.push_back(x);
        }
        scanf("%d", &degree2);
        for(int i = 0; i <= degree2; i++){
            scanf("%d", &x);
            poly2.push_back(x);
        }
        std::vector<long double> result = polymult(poly1,poly2);

        int res_degree = degree1 + degree2;
        printf("%lld \n", res_degree);
        for(int i = 0; i <= res_degree; i++){
            printf("%lld%c ", (long long)std::round(result[i]), ' ');
        }
        

    }

}


template <typename T>
std::vector<T> polymult(std::vector<std::complex<T>> const& p1, std::vector<std::complex<T>> const& p2){
    std::vector<std::complex<T>> fp1(p1.begin(), p1.end());
    std::vector<std::complex<T>> fp2(p2.begin(), p2.end());

    int n = 1;
    while(n < fp1.size() + fp2.size()){ //Next power of 2 greater than fp1.size() + fp2.size()
        n <<= 1;
    }
    fp1.resize(n);
    fp2.resize(n);

    fft(fp1, false);
    fft(fp2, false);

    for(int i = 0; i < n; i++){
        fp1[i] *= fp2[i];
    }
    fft(fp1, true);
    std::vector<T> result(n);
    for(int i = 0; i < n; i++){
        result[i] = std::round(fp1[i].real());
    }
    return result;
    

}

template <typename T>
void fft(std::vector<std::complex<T>> & values, bool invert){
    int n = values.size();

    for(int i = 1, j = 0; i < n; i++){
        int bit = n >> 1;       //bit = n rightshifted once
        for(; j & bit; bit >>= 1){      // >>= shift and assignment
            j ^= bit;                   //XOR
        }
        j ^= bit;
        if(i < j){
            swap(values[i], values[j]);
        }
    }

    for(int len = 2; len <= n; len <<= 1){
        T angle = 2*std::acos(-1)/len;
        if(invert){
            angle *= -1;
        }
        std::complex<T>  wlen(std::cos(angle), std::sin(angle));
        for(int i = 0; i < n; i += len ){
            std::complex<T> w(1);
            for(int j = 0; j < len/2; j++){
                std::complex<T> u = values[i+j];
                std::complex<T> v = values[i+j+len/2] * w;
                values[i+j] = u + v;
                values[i+j+len/2] = u - v;
                w *= wlen;
            }

        }

    }

    if(invert){
        for(std::complex<T> & value : values){
            value /= (T)n;
        }
    }
}
