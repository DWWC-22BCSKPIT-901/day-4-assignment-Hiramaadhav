#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> studentQueue;
    for (int student : students) {
        studentQueue.push(student);
    }

    int sandwichIndex = 0; // Index to track the top of the sandwich stack
    int attempts = 0; // Tracks the number of consecutive unsuccessful attempts

    while (!studentQueue.empty() && attempts < studentQueue.size()) {
        if (studentQueue.front() == sandwiches[sandwichIndex]) {
            // The student takes the sandwich
            studentQueue.pop();
            sandwichIndex++;
            attempts = 0; // Reset unsuccessful attempts
        } else {
            // Move the student to the back of the queue
            studentQueue.push(studentQueue.front());
            studentQueue.pop();
            attempts++;
        }
    }

    // Remaining students in the queue cannot eat
    return studentQueue.size();
}

int main() {
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};

    int result = countStudents(students, sandwiches);
    cout << "Number of students unable to eat: " << result << endl;

    return 0;
}
