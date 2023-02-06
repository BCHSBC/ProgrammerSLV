#include <iostream>
using namespace std;
int check[10001];
void checkSelf(int number) {
    if(number > 10000) return;
    
        check[number]++;
        int sum = 0;
        int newNumber = number;
        while(newNumber / 10 >= 1) {
            sum += newNumber %10;
            newNumber /= 10;
        }
        sum += newNumber;
        checkSelf(sum + number);
    
}
int main() {
    for(int i = 1;i <= 10000;i++){
        checkSelf(i);
    }    
    for(int i = 1;i<= 10000;i++) {
        if(check[i] == 1){
            cout << i << "\n";
        }
    }
}
