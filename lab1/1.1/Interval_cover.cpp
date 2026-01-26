#include <vector>
#include <iostream>

//Author:   Simha158 Simon Hansson

//Problem:  Interval cover (https://liu.kattis.com/courses/AAPS/AAPS26/assignments/wunfda/problems/intervalcover) 
//          Find the smallest subset of intervals that cover the given interval.

//Algorithm:    First sort all the intervals in ascending order by startpoint (if equal sort descending by endpoint)
//              Then iterate over the intervals and keep track of a current best pick and the start of the 
//              reference interval. If the current intervals startpoint is later than reference intervals startpoint
//              we save the current best pick in a result list. If the algorithm detect any gaps it exits or exits
//              when the whole reference interval is covered.

//Time complex: O(n log n)

//Practiacal instructions:  Expects an non empty input of the types interval_t and std::vector<interval_t> 



struct interval_t{
    double start,end;
    int index;
};

std::vector<int> cover(interval_t interval, std::vector<interval_t> intervals);


//Comparator for interval_t
bool sort_interval(interval_t a, interval_t b){
    if(a.start != b.start){
        return a.start < b.start;
    } else {
        return a.end > b.end;
    }


}

/*
A main function for the interval cover algorithm that handels the 
input and output from the terminal and calls the solver
*/
int main(){

    double A, B;

    int number_of_intervals;
    while(std::cin >> A >> B){
       
        if(!(std::cin >> number_of_intervals)){
            break;
        }
        interval_t reference_interval;
        reference_interval.start = A;
        reference_interval.end = B;
        double start, end;
        std::vector<interval_t> intervals;

        for(int i = 0; i < number_of_intervals; i++){
            std::cin >> start;
            std::cin >> end;
            interval_t interval;
            interval.start = start;
            interval.end = end;
            interval.index = i;
            intervals.push_back(interval);
        }

        std::vector<int> result = cover(reference_interval, intervals); 
        //-1 indicates no interval was found
        if(result[0] == -1){
            std::cout << "impossible" << std::endl;
        } else{
            std::cout << result.size() << std::endl;
            for(auto& index : result){
                std::cout << index << " ";
            }
            std::cout << std::endl;
        }
    }

}

/*
A solver for the interval coverage problem
Output  :   A list of the covering intervals or [-1] if it was not solveble
*/

std::vector<int> cover(interval_t reference_interval, std::vector<interval_t> intervals){ 
    //std::sort O(n log n)   
    std::sort(intervals.begin(), intervals.end(), sort_interval);

    std::vector<interval_t> locked_intervals;
    double start {reference_interval.start};
    double end {reference_interval.end};

    interval_t best_intervel;
    best_intervel.index = -1; //placeholder to keep track of first iteration
    best_intervel.end = -std::numeric_limits<double>::infinity();

    bool done = false;
    //Loop over all intervals O(n)
    for(interval_t& current : intervals){
        
        if(current.end < reference_interval.start){
            //The interval is to the left
            continue;
        }
        if(current.start > reference_interval.end){
            //The rest of the intervals are to the right
            break;
        }
        
        if(current.start > start){
            if(current.start > best_intervel.end || best_intervel.index == -1){
                //There is a gap and thus impossible
                return std::vector<int>{-1};
            }
            locked_intervals.push_back(best_intervel);
            start = best_intervel.end;  
            best_intervel = current;
            if(start >= reference_interval.end){
                done = true;
                break;
            }
        }
        if(current.end > best_intervel.end){
            best_intervel = current;
        }
    }


    if(best_intervel.end >= reference_interval.end){
        if(!done){
            if(locked_intervals.empty() || locked_intervals[locked_intervals.size() -1].index != best_intervel.index){
                locked_intervals.push_back(best_intervel);
            }
        }
    } else{
        if(locked_intervals.empty() || locked_intervals[locked_intervals.size() - 1].end < reference_interval.end){
            return std::vector<int>{-1};
        }
        //we could not cover the whole inteval
    }
    

    std::vector<int> result;
    for(interval_t& interval : locked_intervals){
        result.push_back(interval.index);
    }

    return result;

}
