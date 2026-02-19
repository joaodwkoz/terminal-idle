#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    /* Loop temporário para testar execução */
    
    int timer = 0;

    while (true) {
        cout << "O programa esta rodando por " << timer << " segundos!" << endl; 
        timer++;
        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}
