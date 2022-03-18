#pragma once

#include <utility>

class Scale {
  public:
   Scale(const std::pair<float, float>& scale_a,const std::pair<float, float>& scale_b):
        scale_a_(scale_a),
        scale_b_(scale_b),
        a_scale_ratio_((scale_a.second - scale_a.first) / (scale_b.second - scale_b.first)), 
        b_scale_ratio_((scale_b.second - scale_b.first) / (scale_a.second - scale_a.first)) {}

    int get_on_scale_a(int x_b) {
      return (x_b - scale_b_.first) * a_scale_ratio_ + scale_a_.first;
    }

    int get_on_scale_b(int x_a) {
      return (x_a - scale_a_.first) * b_scale_ratio_ + scale_b_.first;
    }   

  private:
    const std::pair<float, float>& scale_a_;
    const std::pair<float, float>& scale_b_;
    const float a_scale_ratio_;
    const float b_scale_ratio_;
};
