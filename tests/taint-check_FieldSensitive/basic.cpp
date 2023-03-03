struct basic_st {
    int a;
    double b;
};

struct pointer_st {
    int *a;
    double *b;
};

void testBasic(int taint) {
    basic_st basic;
    basic.a = taint;
}

void testBasicPointer(int taint) {
    int pointee = 1;
    pointer_st basic_1;
    basic_1.a = &pointee;
    pointee = taint;
}

void testStructPointer(int taint) {
    basic_st *basic_1 = new basic_st();
    basic_st *basic_2 = new basic_st();
    basic_1->a = taint;
    basic_2 = basic_1;
}