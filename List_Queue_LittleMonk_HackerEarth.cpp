#include <list>
#include <iostream>
#include <queue>

using namespace std;

typedef queue<int> QI;

class School {
public:
    int id;
    QI students;
    School(int id) : id(id) {}
};

void push(int school, int rn, list<School*>& v){
    for(list<School*>::iterator it = v.begin(); it != v.end(); ++it){
        School& s = *(*it);
        if(s.id == school){
            s.students.push(rn);
            return;
        }
    }

    School* s = new School(school);
    s->students.push(rn);
    v.push_back(s);
}

pair<int, int> pop(list<School*>& v){
    School* s = v.front();

    int school = s->id;
    int student = s->students.front();
    s->students.pop();

    if(s->students.empty()){
        v.pop_front();
        delete(s);
    }

    return make_pair(school, student);
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);

    int n;
    cin >> n;

    list<School*> v;

    for(int i = 0; i < n; ++i){
        char c;
        cin >> c;

        if (c == 'E'){
            int school, roll_number;
            cin >> school >> roll_number;
            push(school, roll_number, v);
        }
        else {
            pair<int, int> top = pop(v);
            cout << top.first << " " << top.second << "\n";
        }
    }
}
