#include <algorithm>
#include <compare>
#include <iostream>
#include <vector>

struct Space {
  bool operator==(auto pos) const { return *pos == ' '; }
};

struct NegativeNumber {
  bool operator==(auto num) const { return *num < 0; }
};

struct Sum {
  void operator()(auto n) { sum += n; }

  int sum{0};
};

int main() {

  const char *codingriji =
      "subscribed to my wechat official account codingriji";

  std::ranges::for_each(codingriji, Space{}, [](char c) { std::cout << c; });
  std::cout << '\n';
  for (auto c : std::ranges::subrange{codingriji, Space{}})
    std::cout << c;
  std::cout << '\n';

  std::ranges::subrange rainer{codingriji, Space{}};
  std::ranges::for_each(rainer, [](char c) { std::cout << c << ' '; });
  std::cout << '\n';
  for (auto c : rainer)
    std::cout << c << ' ';
  std::cout << '\n';

  std::cout << "\n";

  std::vector<int> myVec{5, 10, 33, -5, 10, 10086, 10010};

  for (auto v : myVec)
    std::cout << v << " ";
  std::cout << '\n';

  auto [tmp1, sum] = std::ranges::for_each(myVec, Sum{});
  std::cout << "Sum: " << sum.sum << '\n';

  auto [tmp2, sum2] =
      std::ranges::for_each(std::begin(myVec), NegativeNumber{}, Sum{});
  std::cout << "Sum: " << sum2.sum << '\n';

  std::ranges::transform(std::begin(myVec), NegativeNumber{},

                         std::begin(myVec), [](auto num) { return num * num; });
  std::ranges::for_each(std::begin(myVec), NegativeNumber{},
                        [](int num) { std::cout << num << " "; });
  std::cout << '\n';
  for (auto v : std::ranges::subrange{std::begin(myVec), NegativeNumber{}}) {
    std::cout << v << " ";
  }

  std::cout << "\n\n";
}
