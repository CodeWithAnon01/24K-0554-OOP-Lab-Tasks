#include <iostream>
using namespace std;

class Student {
    int id;
    string name;
    int* scores;
    int numScores;
public:
    Student(int id, string name, int scores[], int num) : id(id), name(name), numScores(num) {
        this->scores = new int[num];
        for (int i = 0; i < num; i++) 
            this->scores[i] = scores[i];
    }

    // Deep copy constructor
    Student(const Student& other) : id(other.id), name(other.name), numScores(other.numScores) {
        scores = new int[numScores];
        for (int i = 0; i < numScores; i++) 
            scores[i] = other.scores[i];
    }

    void display() {
        cout << "ID: " << id << "\nName: " << name << "\nScores: ";
        for (int i = 0; i < numScores; i++) 
            cout << scores[i] << " ";
        cout << endl;
    }

    ~Student() {
        delete[] scores;
    }
};

int main() {
    int scores[] = {90, 85, 88};
    Student s1(1, "Alice", scores, 3);
    Student s2 = s1;

    cout << "Original Student:\n";
    s1.display();
    cout << "\nCopied Student:\n";
    s2.display();
    return 0;
}