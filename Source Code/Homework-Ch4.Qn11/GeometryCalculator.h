class GeometryCalculator {

public:
    // Constants
    enum MENU_ITEMS {
        CIRCLE = 1,
        RECTANGLE = 2,
        TRIANGLE = 3,
        EXIT = 4
    };
    const double PI = 3.14159;
    const int AREA_PRECISION = 1;

    void runZeCalculator();
    int getMenuFeedback();
    void goNuts();
    void sayBye();

    bool isMeasureValid(double input);

    void doCircleMethod();
    double getCircleArea(double radius);

    void doRectangleMethod();
    double getRectArea(double length, double width);

    void doTriangleMethod();
    double getTriangleArea(double base, double height);

};