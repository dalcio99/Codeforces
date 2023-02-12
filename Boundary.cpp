#include<bits/stdc++.h>
 
using namespace std;
 
#define pp pair<int, int>
#define mp make_pair
 
int main(){
 
    int T;
    cin >> T;
 
    while(T > 0){
        int L, S;
        cin >> L >> S;
 
        int gcd1 = gcd(L-1,S-1);
        int gcd2 = gcd(L, S-2);
        int gcd3 = gcd(L-2, S);
        int gcd4 = gcd(gcd(L, S-1), L-2);
        int gcd5 = gcd(gcd(S-2, L-1), S);
 
        set<int> ss;
        ss.clear();
 
        for(int i = 2; i <= sqrt(gcd1); i++){
            if(gcd1 % i == 0) { 
                ss.insert(i); 
                ss.insert(gcd1/i);
            }
        }
        ss.insert(gcd1);
        for(int i = 2; i <= sqrt(gcd2); i++){
            if(gcd2 % i == 0) { 
                ss.insert(i); 
                ss.insert(gcd2/i);
            }
        }
        ss.insert(gcd2);
        for(int i = 2; i <= sqrt(gcd3); i++){
            if(gcd3 % i == 0) { 
                ss.insert(i); 
                ss.insert(gcd3/i);
            }
        }
        ss.insert(gcd3);
        for(int i = 2; i <= sqrt(gcd4); i++){
            if(gcd4 % i == 0) { 
                ss.insert(i); 
                ss.insert(gcd4/i);
            }
        }
        ss.insert(gcd4);
        for(int i = 2; i <= sqrt(gcd5); i++){
            if(gcd5 % i == 0) { 
                ss.insert(i);
                ss.insert(gcd5/i);
            }
        }
        ss.insert(gcd5);
 
        ss.insert(1);
 
        int s = ss.size();
 
        printf("%d ", s);
 
        set<int>::iterator itr = ss.begin();
 
        while(itr != ss.end()){
            cout << *itr <<" ";
            itr++;
        }
 
        cout<<endl;
 
        T--;
    }
 
}