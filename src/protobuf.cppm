// Protocol Buffers module wrapper.
//
// The actual library is compiled from the classic .cc units under
// src/google/protobuf/**. This module interface aggregates the public headers
// into a named C++23 module so downstreams can `import protobuf` instead of
// pulling in dozens of headers.
//
// The pattern: place every public header in the global module fragment
// (between `module;` and `export module protobuf;`). The declarations there
// are textually included and remain attached to the global module. We then
// re-export the names downstream code actually uses via `export using`
// declarations in the module purview.

module;

#include <google/protobuf/any.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/descriptor.pb.h>
#include <google/protobuf/descriptor_database.h>
#include <google/protobuf/dynamic_message.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/map.h>
#include <google/protobuf/map_field.h>
#include <google/protobuf/message.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/repeated_ptr_field.h>
#include <google/protobuf/text_format.h>
#include <google/protobuf/unknown_field_set.h>
#include <google/protobuf/wire_format.h>
#include <google/protobuf/wire_format_lite.h>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/tokenizer.h>
#include <google/protobuf/io/zero_copy_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>

#include <google/protobuf/stubs/bytestream.h>
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/int128.h>
#include <google/protobuf/stubs/status.h>
#include <google/protobuf/stubs/stringpiece.h>
#include <google/protobuf/stubs/stringprintf.h>
#include <google/protobuf/stubs/strutil.h>
#include <google/protobuf/stubs/substitute.h>

export module protobuf;

namespace google::protobuf {

export using ::google::protobuf::Message;
export using ::google::protobuf::MessageLite;
export using ::google::protobuf::MessageFactory;
export using ::google::protobuf::Descriptor;
export using ::google::protobuf::FileDescriptor;
export using ::google::protobuf::FileDescriptorSet;
export using ::google::protobuf::ServiceDescriptor;
export using ::google::protobuf::MethodDescriptor;
export using ::google::protobuf::EnumDescriptor;
export using ::google::protobuf::EnumValueDescriptor;
export using ::google::protobuf::FieldDescriptor;
export using ::google::protobuf::OneofDescriptor;
export using ::google::protobuf::Reflection;
export using ::google::protobuf::DescriptorPool;
export using ::google::protobuf::DynamicMessageFactory;
export using ::google::protobuf::Arena;
export using ::google::protobuf::ArenaOptions;
export using ::google::protobuf::UnknownField;
export using ::google::protobuf::UnknownFieldSet;
export using ::google::protobuf::TextFormat;
export using ::google::protobuf::DescriptorDatabase;
export using ::google::protobuf::MapKey;
export using ::google::protobuf::MapValueRef;
export using ::google::protobuf::MapIterator;
export using ::google::protobuf::MapPair;
export using ::google::protobuf::RepeatedField;
export using ::google::protobuf::RepeatedPtrField;

}  // namespace google::protobuf

namespace google::protobuf::io {

export using ::google::protobuf::io::CodedInputStream;
export using ::google::protobuf::io::CodedOutputStream;
export using ::google::protobuf::io::ZeroCopyInputStream;
export using ::google::protobuf::io::ZeroCopyOutputStream;
export using ::google::protobuf::io::ArrayInputStream;
export using ::google::protobuf::io::ArrayOutputStream;
export using ::google::protobuf::io::CopyingInputStream;
export using ::google::protobuf::io::CopyingInputStreamAdaptor;
export using ::google::protobuf::io::CopyingOutputStream;
export using ::google::protobuf::io::CopyingOutputStreamAdaptor;
export using ::google::protobuf::io::Tokenizer;

}  // namespace google::protobuf::io

namespace google::protobuf::util {
export using ::google::protobuf::util::StatusCode;
}  // namespace google::protobuf::util
