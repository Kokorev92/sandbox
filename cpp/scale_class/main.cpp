#include <gtest/gtest.h>
#include <utility>

#include "scale.h"

using namespace std;

pair<float, float> scale_degrees(0, 180);
pair<float, float> scale_adc(0, 1024);

Scale my_scale(scale_degrees, scale_adc);

int eq_degrees_val[5] = {0, 45, 90, 135, 180};
int test_adc_val[5]   = {0, 256, 512, 768, 1024};

TEST(scale_class_test, rescale_adc_to_degrees) {
    for (int i = 0; i < 5; ++i) {
        auto val = my_scale.get_on_scale_a(test_adc_val[i]);
        ASSERT_EQ(val, eq_degrees_val[i]);
    }
}

TEST(scale_class_test, rescale_degrees_to_adc) {
    for (int i = 0; i < 5; ++i) {
        auto val = my_scale.get_on_scale_b(eq_degrees_val[i]);
        ASSERT_EQ(val, test_adc_val[i]);
    }
}

TEST(scale_class_test, boundary_values) {
    auto val = my_scale.get_on_scale_b(181);
    ASSERT_EQ(val, scale_adc.second);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
