#include "class_spec.h"

TestScore::TestScore(){ studentScore = 0; }

TestScore::TestScore(string name, int score){
    studentName = name;
    studentScore = score;
}

string TestScore::GetName() const{
    return studentName;
}

int TestScore::GetScore() const{
    return studentScore;
}

IDScore::IDScore(){ studentID = 0; }

IDScore::IDScore(string name, int score, int idNum)
    :TestScore(name, score){
    studentID = idNum;
}

int IDScore::GetID() const{
    return studentID;
}

Exam::Exam(){}

void Exam::SetScoreObj(IDScore scoreObj, int pos){
    scores[pos - 1] = scoreObj;
}

IDScore Exam::GetScoreObj(int pos) const{
    return scores[pos - 1];
}