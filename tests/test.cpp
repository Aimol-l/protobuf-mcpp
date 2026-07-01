// Round-trip test for the protobuf module.
//
// Exercises:
//   * `import protobuf` brings names from the named module.
//   * The classic .cc units are linked into a working libprotobuf
//     (arena allocation + generated-pool query).

import std;
import protobuf;

int main() {
    google::protobuf::Arena arena;

    google::protobuf::DescriptorPool const* pool =
        google::protobuf::DescriptorPool::generated_pool();
    if (pool == nullptr) {
        std::println("FAIL: generated_pool() returned nullptr");
        return 1;
    }

    std::println("arena space allocated: {} bytes", arena.SpaceAllocated());
    std::println("generated pool addr: {}", static_cast<void const*>(pool));
    std::println("OK: protobuf module imports and libprotobuf links.");
    return 0;
}
