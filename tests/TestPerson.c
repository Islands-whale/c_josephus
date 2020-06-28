#include "CuTest.h"

#include "../src/person.h"

void TestPersonInit(CuTest *tc) {
    Person *person = person_new(2);

    for (int i = 0; i < 2; i++){
        char str[20] = "Jorn,25";
        person_init(person[i], str);
        CuAssertStrEquals(tc, person_get_name(person[i]), "Jorn");
        CuAssertIntEquals(tc, person_get_age(person[i]), 25);
    }
    person_destroy(person, 2);
}

CuSuite* PersonGetSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestPersonInit);
    return suite;
}