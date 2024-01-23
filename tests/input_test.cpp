#include <gtest/gtest.h>
#include "BFApp/Input.h"

TEST(InputTest, Basic) {
    Input i = Input();
    ASSERT_EQ(i.getSize(), 0);
    Input j = Input(5);
    ASSERT_EQ(j.getSize(), 0);
}

