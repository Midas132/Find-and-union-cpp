#include<iostream>
using namespace std;

const int MAX = 1e6+3;
int iqmin[MAX];
int iqmax[MAX];
int masa[MAX];
int rep[MAX];

int znajdz(int a){
    if(rep[a] == a) return a;
    rep[a] = znajdz(rep[a]);
    return rep[a];
}

void polacz(int a, int b){
    a = znajdz(a);
    b = znajdz(b);
    if(a == b) return;
    rep[b] = a;
    iqmax[a] = max(iqmax[a], iqmax[b]);
    iqmin[a] = min(iqmin[a], iqmin[b]);
    masa[a] += masa[b];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        rep[i] = i;
    }
    int a, b;
    for(int i = 1; i <= n; ++i){
        cin >> a >> b; //a - masa, b - iq
        masa[i] = a;
        iqmax[i] = b;
        iqmin[i] = b;
    }
    string s;
    while(cin >> s){
        if(s == "JOIN"){
            cin >> a >> b;
            polacz(a, b);
        }else if(s == "MASA"){
            cin >> a;
            cout << masa[znajdz(a)] << "\n";
        }else if(s == "IQ_MIN"){
            cin >> a;
            cout << iqmin[znajdz(a)] << "\n";
        }else if(s == "IQ_MAX"){
            cin >> a;
            cout << iqmax[znajdz(a)] << "\n";
        }
    }
}