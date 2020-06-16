#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here

    int numberOfFuling = 0;
    int fuleRemaining = tank;
    int current_position = 0;
    int i = 0;

    for(int i =0; i<stops.size(); i++){
        if(stops[i] - current_position <= tank){
            if(fuleRemaining >= stops[i] - current_position){
                fuleRemaining -= stops[i] - current_position;
            }else{
                fuleRemaining = tank- (stops[i] - current_position);
                numberOfFuling++;
            }
            current_position = stops[i];
        }else
        {
            return -1;
        }
    }

    if(dist - current_position <= fuleRemaining){
        return numberOfFuling;
    }else if(dist - current_position <= tank){
        return numberOfFuling + 1;
    }

    return -1;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
