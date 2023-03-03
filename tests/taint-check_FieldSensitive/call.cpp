struct student{
    int id;
    //double *grade;
};

struct classroom{
    student stu;
    int num;
};

class school{
public:
    void setClassroom1ID(int taint) {
        classroom1.stu.id = taint;
    }
    int getStudentID() {
        return classroom1.stu.id;
    }
    classroom *getClassroom() {
        return classroom2;
    }
private:
    classroom classroom1;
    classroom *classroom2;
};

void changeReference(int &input) {
    input = 1;
}

void testBasic(int taint) {
    school sch;
    sch.setClassroom1ID(taint);
}

void testReturn(int taint) {
    school sch;
    sch.setClassroom1ID(taint);
    int untaint;
    untaint = sch.getStudentID();
}

void testReference(int taint) {
    changeReference(taint);
}
