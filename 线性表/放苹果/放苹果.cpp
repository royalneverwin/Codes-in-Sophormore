#include <iostream>
using namespace std;
//int Factorial(int n){
//    if(n == 0 || n == 1){
//        return 1;
//    }
//    else{
//        return n*Factorial(n-1);
//    }
//}
//int Distribute(int interval, int cut){
//    if(cut == 0){
//        return 1;
//    }
//    else{
//        return Factorial(interval)/(Factorial(cut) * Factorial(interval-cut));
//    }
//}
//int Put_Apple(int M, int N){
//    int interval = M - 1;
//    int way = 0;
//    int use_plate;
//    int cut;
//    for(use_plate = 1; use_plate <= min(M, N); use_plate++){
//        cut = use_plate - 1;
//        way += Distribute(interval, cut)/use_plate;
//    }
//    return way;
//}
int sum(int M, int N, int min){
    int way = 0;
    if(N >= 1 && M >= min) {
        for (int i = min; i <= M; i++) {
            way += sum(M-i, N-1, i);
        }
        return way;
    }
    else if(N == 0 && M == 0){
        return 1;
    }
    else{
        return 0;
    }
}
int Put_Apple(int M, int N){
    int way = 0;
    int use_plate;
    for(use_plate = 1; use_plate <= min(M, N); use_plate++){
        way += sum(M, use_plate, 1);
    }
    return way;
}
int main(){
    int t;
    int M, N;
    cin >> t;
    for(size_t i = 0; i < t; i++){
        cin >> M >> N;
        cout << Put_Apple(M, N) << endl;
    }
    return 0;
}