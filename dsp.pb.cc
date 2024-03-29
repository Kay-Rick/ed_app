// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: dsp.proto

#include "dsp.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
constexpr DSPControllerRequest::DSPControllerRequest(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized){}
struct DSPControllerRequestDefaultTypeInternal {
  constexpr DSPControllerRequestDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~DSPControllerRequestDefaultTypeInternal() {}
  union {
    DSPControllerRequest _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT DSPControllerRequestDefaultTypeInternal _DSPControllerRequest_default_instance_;
constexpr DSPControllerResponse::DSPControllerResponse(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized){}
struct DSPControllerResponseDefaultTypeInternal {
  constexpr DSPControllerResponseDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~DSPControllerResponseDefaultTypeInternal() {}
  union {
    DSPControllerResponse _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT DSPControllerResponseDefaultTypeInternal _DSPControllerResponse_default_instance_;
constexpr ReconstructTimeResponse::ReconstructTimeResponse(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : time_(0){}
struct ReconstructTimeResponseDefaultTypeInternal {
  constexpr ReconstructTimeResponseDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~ReconstructTimeResponseDefaultTypeInternal() {}
  union {
    ReconstructTimeResponse _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT ReconstructTimeResponseDefaultTypeInternal _ReconstructTimeResponse_default_instance_;
constexpr CommuRequest::CommuRequest(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : mode_(0){}
struct CommuRequestDefaultTypeInternal {
  constexpr CommuRequestDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~CommuRequestDefaultTypeInternal() {}
  union {
    CommuRequest _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT CommuRequestDefaultTypeInternal _CommuRequest_default_instance_;
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_dsp_2eproto[4];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_dsp_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_dsp_2eproto = nullptr;

const uint32_t TableStruct_dsp_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::DSPControllerRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::DSPControllerResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ReconstructTimeResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::ReconstructTimeResponse, time_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::CommuRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::CommuRequest, mode_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::DSPControllerRequest)},
  { 6, -1, -1, sizeof(::DSPControllerResponse)},
  { 12, -1, -1, sizeof(::ReconstructTimeResponse)},
  { 19, -1, -1, sizeof(::CommuRequest)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_DSPControllerRequest_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_DSPControllerResponse_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_ReconstructTimeResponse_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_CommuRequest_default_instance_),
};

const char descriptor_table_protodef_dsp_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\tdsp.proto\"\026\n\024DSPControllerRequest\"\027\n\025D"
  "SPControllerResponse\"\'\n\027ReconstructTimeR"
  "esponse\022\014\n\004time\030\001 \001(\002\"\034\n\014CommuRequest\022\014\n"
  "\004mode\030\001 \001(\0052\225\010\n\rDSPController\022;\n\nLoadSar"
  "App\022\025.DSPControllerRequest\032\026.DSPControll"
  "erResponse\022<\n\013StartSarApp\022\025.DSPControlle"
  "rRequest\032\026.DSPControllerResponse\022;\n\nStop"
  "SarApp\022\025.DSPControllerRequest\032\026.DSPContr"
  "ollerResponse\022=\n\014SwitchSarApp\022\025.DSPContr"
  "ollerRequest\032\026.DSPControllerResponse\022=\n\014"
  "LoadElecReco\022\025.DSPControllerRequest\032\026.DS"
  "PControllerResponse\022>\n\rStartElecReco\022\025.D"
  "SPControllerRequest\032\026.DSPControllerRespo"
  "nse\022=\n\014StopElecReco\022\025.DSPControllerReque"
  "st\032\026.DSPControllerResponse\022\?\n\016SwitchElec"
  "Reco\022\025.DSPControllerRequest\032\026.DSPControl"
  "lerResponse\022:\n\021LoadCommunication\022\r.Commu"
  "Request\032\026.DSPControllerResponse\022;\n\022Start"
  "Communication\022\r.CommuRequest\032\026.DSPContro"
  "llerResponse\022:\n\021StopCommunication\022\r.Comm"
  "uRequest\032\026.DSPControllerResponse\022<\n\023Swit"
  "chCommunication\022\r.CommuRequest\032\026.DSPCont"
  "rollerResponse\022<\n\023ConfigCommunication\022\r."
  "CommuRequest\032\026.DSPControllerResponse\022H\n\025"
  "GetComReconstructTime\022\025.DSPControllerReq"
  "uest\032\030.ReconstructTimeResponse\022H\n\025GetSar"
  "ReconstructTime\022\025.DSPControllerRequest\032\030"
  ".ReconstructTimeResponse\022I\n\026GetElecRecon"
  "structTime\022\025.DSPControllerRequest\032\030.Reco"
  "nstructTimeResponseb\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_dsp_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_dsp_2eproto = {
  false, false, 1187, descriptor_table_protodef_dsp_2eproto, "dsp.proto", 
  &descriptor_table_dsp_2eproto_once, nullptr, 0, 4,
  schemas, file_default_instances, TableStruct_dsp_2eproto::offsets,
  file_level_metadata_dsp_2eproto, file_level_enum_descriptors_dsp_2eproto, file_level_service_descriptors_dsp_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_dsp_2eproto_getter() {
  return &descriptor_table_dsp_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_dsp_2eproto(&descriptor_table_dsp_2eproto);

// ===================================================================

class DSPControllerRequest::_Internal {
 public:
};

DSPControllerRequest::DSPControllerRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase(arena, is_message_owned) {
  // @@protoc_insertion_point(arena_constructor:DSPControllerRequest)
}
DSPControllerRequest::DSPControllerRequest(const DSPControllerRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:DSPControllerRequest)
}





const ::PROTOBUF_NAMESPACE_ID::Message::ClassData DSPControllerRequest::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::CopyImpl,
    ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::MergeImpl,
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*DSPControllerRequest::GetClassData() const { return &_class_data_; }







::PROTOBUF_NAMESPACE_ID::Metadata DSPControllerRequest::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_dsp_2eproto_getter, &descriptor_table_dsp_2eproto_once,
      file_level_metadata_dsp_2eproto[0]);
}

// ===================================================================

class DSPControllerResponse::_Internal {
 public:
};

DSPControllerResponse::DSPControllerResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase(arena, is_message_owned) {
  // @@protoc_insertion_point(arena_constructor:DSPControllerResponse)
}
DSPControllerResponse::DSPControllerResponse(const DSPControllerResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:DSPControllerResponse)
}





const ::PROTOBUF_NAMESPACE_ID::Message::ClassData DSPControllerResponse::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::CopyImpl,
    ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::MergeImpl,
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*DSPControllerResponse::GetClassData() const { return &_class_data_; }







::PROTOBUF_NAMESPACE_ID::Metadata DSPControllerResponse::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_dsp_2eproto_getter, &descriptor_table_dsp_2eproto_once,
      file_level_metadata_dsp_2eproto[1]);
}

// ===================================================================

class ReconstructTimeResponse::_Internal {
 public:
};

ReconstructTimeResponse::ReconstructTimeResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:ReconstructTimeResponse)
}
ReconstructTimeResponse::ReconstructTimeResponse(const ReconstructTimeResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  time_ = from.time_;
  // @@protoc_insertion_point(copy_constructor:ReconstructTimeResponse)
}

inline void ReconstructTimeResponse::SharedCtor() {
time_ = 0;
}

ReconstructTimeResponse::~ReconstructTimeResponse() {
  // @@protoc_insertion_point(destructor:ReconstructTimeResponse)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void ReconstructTimeResponse::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void ReconstructTimeResponse::ArenaDtor(void* object) {
  ReconstructTimeResponse* _this = reinterpret_cast< ReconstructTimeResponse* >(object);
  (void)_this;
}
void ReconstructTimeResponse::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void ReconstructTimeResponse::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void ReconstructTimeResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:ReconstructTimeResponse)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  time_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ReconstructTimeResponse::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // float time = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 13)) {
          time_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* ReconstructTimeResponse::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ReconstructTimeResponse)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // float time = 1;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_time = this->_internal_time();
  uint32_t raw_time;
  memcpy(&raw_time, &tmp_time, sizeof(tmp_time));
  if (raw_time != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(1, this->_internal_time(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ReconstructTimeResponse)
  return target;
}

size_t ReconstructTimeResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ReconstructTimeResponse)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // float time = 1;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_time = this->_internal_time();
  uint32_t raw_time;
  memcpy(&raw_time, &tmp_time, sizeof(tmp_time));
  if (raw_time != 0) {
    total_size += 1 + 4;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ReconstructTimeResponse::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    ReconstructTimeResponse::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ReconstructTimeResponse::GetClassData() const { return &_class_data_; }

void ReconstructTimeResponse::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<ReconstructTimeResponse *>(to)->MergeFrom(
      static_cast<const ReconstructTimeResponse &>(from));
}


void ReconstructTimeResponse::MergeFrom(const ReconstructTimeResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ReconstructTimeResponse)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_time = from._internal_time();
  uint32_t raw_time;
  memcpy(&raw_time, &tmp_time, sizeof(tmp_time));
  if (raw_time != 0) {
    _internal_set_time(from._internal_time());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ReconstructTimeResponse::CopyFrom(const ReconstructTimeResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ReconstructTimeResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ReconstructTimeResponse::IsInitialized() const {
  return true;
}

void ReconstructTimeResponse::InternalSwap(ReconstructTimeResponse* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(time_, other->time_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ReconstructTimeResponse::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_dsp_2eproto_getter, &descriptor_table_dsp_2eproto_once,
      file_level_metadata_dsp_2eproto[2]);
}

// ===================================================================

class CommuRequest::_Internal {
 public:
};

CommuRequest::CommuRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:CommuRequest)
}
CommuRequest::CommuRequest(const CommuRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  mode_ = from.mode_;
  // @@protoc_insertion_point(copy_constructor:CommuRequest)
}

inline void CommuRequest::SharedCtor() {
mode_ = 0;
}

CommuRequest::~CommuRequest() {
  // @@protoc_insertion_point(destructor:CommuRequest)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void CommuRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void CommuRequest::ArenaDtor(void* object) {
  CommuRequest* _this = reinterpret_cast< CommuRequest* >(object);
  (void)_this;
}
void CommuRequest::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void CommuRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void CommuRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:CommuRequest)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  mode_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* CommuRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 mode = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          mode_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* CommuRequest::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:CommuRequest)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 mode = 1;
  if (this->_internal_mode() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_mode(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:CommuRequest)
  return target;
}

size_t CommuRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:CommuRequest)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int32 mode = 1;
  if (this->_internal_mode() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_mode());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData CommuRequest::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    CommuRequest::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*CommuRequest::GetClassData() const { return &_class_data_; }

void CommuRequest::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<CommuRequest *>(to)->MergeFrom(
      static_cast<const CommuRequest &>(from));
}


void CommuRequest::MergeFrom(const CommuRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:CommuRequest)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_mode() != 0) {
    _internal_set_mode(from._internal_mode());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void CommuRequest::CopyFrom(const CommuRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:CommuRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CommuRequest::IsInitialized() const {
  return true;
}

void CommuRequest::InternalSwap(CommuRequest* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(mode_, other->mode_);
}

::PROTOBUF_NAMESPACE_ID::Metadata CommuRequest::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_dsp_2eproto_getter, &descriptor_table_dsp_2eproto_once,
      file_level_metadata_dsp_2eproto[3]);
}

// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::DSPControllerRequest* Arena::CreateMaybeMessage< ::DSPControllerRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::DSPControllerRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::DSPControllerResponse* Arena::CreateMaybeMessage< ::DSPControllerResponse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::DSPControllerResponse >(arena);
}
template<> PROTOBUF_NOINLINE ::ReconstructTimeResponse* Arena::CreateMaybeMessage< ::ReconstructTimeResponse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ReconstructTimeResponse >(arena);
}
template<> PROTOBUF_NOINLINE ::CommuRequest* Arena::CreateMaybeMessage< ::CommuRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::CommuRequest >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
