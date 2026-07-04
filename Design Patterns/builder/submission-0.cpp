class Meal {
private:
    double cost;
    bool takeOut;
    string main;
    string drink;

public:
    double getCost() {
        return cost;
    }

    bool getTakeOut() {
        return takeOut;
    }

    string getMain() {
        return main;
    }

    string getDrink() {
        return drink;
    }

    void setCost(double cost) {
        this->cost = cost;
    }

    void setTakeOut(bool takeOut) {
        this->takeOut = takeOut;
    }

    void setMain(string main) {
        this->main = main;
    }

    void setDrink(string drink) {
        this->drink = drink;
    }
};

class MealBuilder {
private:
    double cost;
    bool takeOut;
    string main;
    string drink;

public:
    MealBuilder() {

    }

    MealBuilder& addCost(double cost) {
        this->cost = cost;
        return *this;
    }

    MealBuilder& addTakeOut(bool takeOut) {
        this->takeOut = takeOut;
        return *this;
    }

    MealBuilder& addMainCourse(string main) {
        this->main = main;
        return *this;
    }

    MealBuilder& addDrink(string drink) {
        this->drink = drink;
        return *this;
    }

    Meal build() {
        Meal m = Meal();
        m.setCost(this->cost);
        m.setTakeOut(this->takeOut);
        m.setMain(this->main);
        m.setDrink(this->drink);
        return m;
    }
};
