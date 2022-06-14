#include <array>
#include <iostream>
#include <msgpack.hpp>

struct TestData {
  std::array<float, 3> vec1;
  std::array<float, 3> vec2;
  float field;
  uint64_t time_us;
  MSGPACK_DEFINE_MAP(vec1, vec2, field, time_us);
};

int main() {
  TestData input;
  input.field = 123.456;

  // Pack data
  std::stringstream buffer;
  msgpack::pack(buffer, input);

  // Unpack data
  msgpack::object_handle oh;
  msgpack::unpack(oh, buffer.str().data(), buffer.str().size());
  auto output = oh.get().as<TestData>();

  std::cout << "Field: " << output.field << std::endl;
}