#include <bits/stdc++.h>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {

    
    unordered_map<char, int> taskcount;
    for (char task : tasks) {
        taskcount[task]++;
    }

    
    int freq = 0;
    for (auto it : taskcount) {
        freq = max(freq, it.second);
    }

    
    int count = 0;
    for (auto it : taskcount) {
        if (it.second == freq) {
            count++;
        }
    }

    
    int partcount = freq - 1;
    int partlength = max(0, n - (count - 1));  
    int empty = partcount * partlength;
    int availabletasks = tasks.size() - (freq * count);
    int time = max(0, empty - availabletasks);

    
    return tasks.size() + time;
}

int main() {

    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;

    int result = leastInterval(tasks, n);

    cout << "Minimum Time Required: " << result << endl;

    return 0;
}
