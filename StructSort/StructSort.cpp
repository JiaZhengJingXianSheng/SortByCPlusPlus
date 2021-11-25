#include <iostream>
#include <algorithm>

using namespace std;
struct stu{
    string name;
    int age;
    int score;
};

bool compare(stu a, stu b )
{
    // 成绩相同用年龄从小往大排序
    if(a.score == b.score)
        return a.age<b.age;
    //成绩不同，直接根据成绩好坏排序
    return a.score > b.score;
}
int main() {
    stu STU[3];
    STU[0] = {"first",10,95};
    STU[1] = {"second", 20,95};
    STU[2] = {"third", 10,98};

    sort(STU,STU+3,compare);
    for(stu s : STU)
    {
        cout<<"name:"<<s.name <<"  age:"<<s.age<<"  score"<<s.score<<endl;
    }
    return 0;
}
