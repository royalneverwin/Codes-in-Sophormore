#include <iostream>
#include <list>
using namespace std;
class Monomial{
public:
    int c;
    int e;
    Monomial(int C, int E):c(C), e(E){}
    bool operator < (Monomial b) const{
        return this->e > b.e;
    }
};
int main(){
    int n;
    int E, C;
    cin >> n;
    list<Monomial> DXS1;
    list<Monomial> DXS2;
    list<Monomial> DXS3;
    list<Monomial>::iterator dxs1;
    list<Monomial>::iterator dxs2;
    list<Monomial>::iterator dxs3;
    for (int i = 0; i < n; i++){
        cin >> C  >> E;
        while(E >= 0){
            DXS1.emplace_back(Monomial(C, E));
            cin >> C >> E;
        }
        cin >> C >> E;
        while(E >= 0){
            DXS2.emplace_back(Monomial(C, E));
            cin >> C >> E;
        }
        DXS1.sort();
        DXS2.sort();
        dxs1 = DXS1.begin();
        dxs2 = DXS2.begin();
        while(dxs1 != DXS1.end() && dxs2 != DXS2.end()){
            if(dxs1->e > dxs2->e){
                if (DXS3.empty()) {
                    DXS3.emplace_back(*dxs1);
                }
                else{
                    if(dxs3->e == dxs1->e){
                        dxs3->c += dxs1 ->c;
                    }
                    else{
                        DXS3.emplace_back(*dxs1);
                    }
                }
                dxs1++;
            }
            else if(dxs1->e < dxs2->e){
                if (DXS3.empty()) {
                    DXS3.emplace_back(*dxs2);
                }
                else{
                    if(dxs3->e == dxs2->e){
                        dxs3->c += dxs2->c;
                    }
                    else{
                        DXS3.emplace_back(*dxs2);
                    }
                }
                dxs2++;
            }
            else{
                if (DXS3.empty()) {
                    DXS3.emplace_back(Monomial(dxs1->c+dxs2->c, dxs1->e));
                }
                else{
                    if(dxs3->e == dxs1->e){
                        dxs3->c += dxs1->c;
                        dxs3->c += dxs2->c;
                    }
                    else{
                        DXS3.emplace_back(Monomial(dxs1->c+dxs2->c, dxs1->e));
                    }
                }
                dxs1++;
                dxs2++;
            }
            dxs3 = DXS3.end();
            dxs3--;
        }
        if(dxs1 != DXS1.end()){
            while(dxs1 != DXS1.end()){
                if (DXS3.empty()) {
                    DXS3.emplace_back(*dxs1);
                }
                else{
                    if(dxs3->e == dxs1->e){
                        dxs3->c += dxs1 ->c;
                    }
                    else{
                        DXS3.emplace_back(*dxs1);
                    }
                }
                dxs1++;
                dxs3 = DXS3.end();
                dxs3--;
            }
        }
        else if(dxs2 != DXS2.end()){
            while(dxs2 != DXS2.end()){
                if (DXS3.empty()) {
                    DXS3.emplace_back(*dxs2);
                }
                else{
                    if(dxs3->e == dxs2->e){
                        dxs3->c += dxs2 ->c;
                    }
                    else{
                        DXS3.emplace_back(*dxs2);
                    }
                }
                dxs2++;
                dxs3 = DXS3.end();
                dxs3--;
            }
        }
        DXS3.sort();
        for(dxs3 = DXS3.begin(); dxs3 != DXS3.end(); dxs3++){
            if(dxs3->c != 0){
                cout << "[ " << dxs3->c << ' ' << dxs3->e << " ] ";
            }
        }
        cout << '\n';
        DXS1.clear();
        DXS2.clear();
        DXS3.clear();
    }
    return 0;
}