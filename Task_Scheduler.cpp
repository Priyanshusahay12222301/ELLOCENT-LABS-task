// ...existing code...
using namespace std;

int leastInterval(vector<char>& tasks, int n) {

    unordered_map<char, int> taskcount;

    // Count frequency of each task
    for (char task : tasks) {
        taskcount[task]++;
    }

    int freq = 0;

    // Find maximum frequency
    for (auto it : taskcount) {
        freq = max(freq, it.second);
    }

    int count = 0;

    // Count how many tasks have maximum frequency
    for (auto it : taskcount) {
        if (it.second == freq) {
            count++;
        }
    }

    int partcount = freq - 1;
    int partlength = n - (count - 1);
    int empty = partcount * partlength;
    int availabletasks = tasks.size() - (freq * count);
    int time = max(0, empty - availabletasks);

    return tasks.size() + time;
}

int main() {

    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;

    cout << "Minimum Time Required: "
         << leastInterval(tasks, n) << endl;

    return 0;
}
