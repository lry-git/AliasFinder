struct inside{
    int a;
    double *b;
};

struct outside_single{
    inside in;
    int b;
};

struct outside_mul{
    inside in_1;
    inside *in_2;
};

// void test_single_member(outside_single out) {
//     out.in.a = 1;
// }

// void test_single_father(outside_single taint) {
//     outside_single untaint;
//     untaint.in = taint.in;
// }

// void test_multi_member_untaint(outside_mul taint) {
//     taint.in_1.a = 1;
// } 

// void test_multi_member_taint(int taint) {
//     outside_mul untaint;
//     untaint.in_1.a = taint;
// }

void test_member_pointer(outside_mul taint) {
    outside_mul untaint;
    untaint.in_2 = taint.in_2;
    //taint.in_2->a = 1;
}

// void updateNestingField(outside_mul out) {
//     //out.in_1.a = 1;
//     out.in_2->a = 2;
// }


