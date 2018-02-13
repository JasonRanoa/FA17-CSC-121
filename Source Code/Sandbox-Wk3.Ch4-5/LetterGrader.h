class LetterGrader {

public:
    const int MIN_A_SCORE = 90,
              MIN_B_SCORE = 80,
              MIN_C_SCORE = 70,
              MIN_D_SCORE = 60;
    int testScore;
    char letterGrade;

    void getTestScore();
    void assignGrade();
    void printGrade();

    void executeMe();
};