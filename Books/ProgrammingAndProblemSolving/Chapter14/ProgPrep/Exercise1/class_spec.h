#include <string>
using std::string;

class TestScore{
    public:
        TestScore();
        TestScore(string name, int score);
        string GetName() const;
        int GetScore() const;
    private:
        string studentName;
        int studentScore;
};

class IDScore : public TestScore{
    public:
        IDScore();
        IDScore(string name, int score, int idNum);
        int GetID() const;
    private:
        int studentID;
};

class Exam{
    public:
        Exam();
        void SetScoreObj(IDScore scoreObj, int pos);
        IDScore GetScoreObj(int pos) const;
    private:
        IDScore scores[100];
};