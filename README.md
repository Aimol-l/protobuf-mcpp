# protobuf (mcpp)

Protocol Buffers 3.19.1 packaged as a **C++23 named module** for the
[mcpp](https://github.com/mcpp-community/mcpp) build tool.

The library itself is the classic protobuf source (sourced from OpenCV's
`3rdparty` tree) compiled as a normal `libprotobuf`. On top of it,
[src/protobuf.cppm](src/protobuf.cppm) wraps the public headers into a
single `protobuf` module so downstream code can write `import protobuf;`
instead of pulling in dozens of headers.

## Layout

```text
mcpp.toml              package + build manifest
src/
  protobuf.cppm        module interface — global module fragment + re-exports
  google/protobuf/**   the actual .cc / .h units (118 files)
tests/
  test.cpp             round-trip: import, arena, generated descriptor pool
target/                build output (gitignored)
LICENSE                Google protobuf license
```

## Build

Requires mcpp and the toolchain declared in `mcpp.toml` (`gcc@16.1.0`):

```bash
mcpp build            # build the protobuf lib target
mcpp test             # build + run tests/test.cpp
mcpp pack             # produce target/dist/protobuf-3.19.1.tar.gz
mcpp emit xpkg        # regenerate target/dist/protobuf.lua
```

`mcpp.toml` carries the warning suppressions protobuf 3.19 needs under a
modern GCC — `-Wno-deprecated-declarations`, `-Wno-class-memaccess`,
`-Wno-stringop-overflow`, etc. — plus `HAVE_PTHREAD=1` and `-lpthread`.

## Usage

```cpp
import std;
import protobuf;

int main() {
    google::protobuf::Arena arena;
    auto pool = google::protobuf::DescriptorPool::generated_pool();
    std::println("generated pool addr: {}", static_cast<void const*>(pool));
}
```

`import protobuf` brings in the `google::protobuf`, `google::protobuf::io`,
and (the small) `google::protobuf::util` namespaces — the re-export list is
in [src/protobuf.cppm](src/protobuf.cppm). Symbols not listed there can
still be reached the old-fashioned way by `#include`-ing the relevant
header, since the headers live in the global module fragment.

## Module wrapping pattern

C++23 modules can't `export` names pulled in through textual includes
without an explicit `export using`. The wrapper does two things:

1. **Global module fragment** (`module;` … `export module protobuf;`) —
   textually includes every public protobuf header. Those declarations
   stay attached to the global module.
2. **Module purview** — `export using ::google::protobuf::Message;` (and
   ~50 siblings) re-exports the names downstream code consumes.

## Toolchain & platform

- Standard: **C++23**
- Default toolchain: **gcc 16.1.0**
- Platform-specific flags live under `[target.linux.build]` in
  `mcpp.toml`; Linux is the primary target.

## License

BSD-3-Clause — see [LICENSE](LICENSE). The same license is declared in
`mcpp.toml` and the generated `target/dist/protobuf.lua`.
