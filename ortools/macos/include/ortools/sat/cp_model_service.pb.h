// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ortools/sat/cp_model_service.proto
// Protobuf C++ Version: 5.26.1

#ifndef GOOGLE_PROTOBUF_INCLUDED_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION != 5026001
#error "Protobuf C++ gencode is built with an incompatible version of"
#error "Protobuf C++ headers/runtime. See"
#error "https://protobuf.dev/support/cross-version-runtime-guarantee/#cpp"
#endif
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
#include "ortools/sat/cp_model.pb.h"
#include "ortools/sat/sat_parameters.pb.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto;
namespace operations_research {
namespace sat {
namespace v1 {
class CpSolverRequest;
struct CpSolverRequestDefaultTypeInternal;
extern CpSolverRequestDefaultTypeInternal _CpSolverRequest_default_instance_;
}  // namespace v1
}  // namespace sat
}  // namespace operations_research
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace operations_research {
namespace sat {
namespace v1 {

// ===================================================================


// -------------------------------------------------------------------

class CpSolverRequest final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:operations_research.sat.v1.CpSolverRequest) */ {
 public:
  inline CpSolverRequest() : CpSolverRequest(nullptr) {}
  ~CpSolverRequest() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR CpSolverRequest(
      ::google::protobuf::internal::ConstantInitialized);

  inline CpSolverRequest(const CpSolverRequest& from) : CpSolverRequest(nullptr, from) {}
  inline CpSolverRequest(CpSolverRequest&& from) noexcept
      : CpSolverRequest(nullptr, std::move(from)) {}
  inline CpSolverRequest& operator=(const CpSolverRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline CpSolverRequest& operator=(CpSolverRequest&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const CpSolverRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const CpSolverRequest* internal_default_instance() {
    return reinterpret_cast<const CpSolverRequest*>(
        &_CpSolverRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(CpSolverRequest& a, CpSolverRequest& b) { a.Swap(&b); }
  inline void Swap(CpSolverRequest* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(CpSolverRequest* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  CpSolverRequest* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<CpSolverRequest>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const CpSolverRequest& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const CpSolverRequest& from) { CpSolverRequest::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(CpSolverRequest* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "operations_research.sat.v1.CpSolverRequest"; }

 protected:
  explicit CpSolverRequest(::google::protobuf::Arena* arena);
  CpSolverRequest(::google::protobuf::Arena* arena, const CpSolverRequest& from);
  CpSolverRequest(::google::protobuf::Arena* arena, CpSolverRequest&& from) noexcept
      : CpSolverRequest(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::MessageLite::ClassData* GetClassData()
      const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const final;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kModelFieldNumber = 1,
    kParametersFieldNumber = 3,
  };
  // .operations_research.sat.CpModelProto model = 1;
  bool has_model() const;
  void clear_model() ;
  const ::operations_research::sat::CpModelProto& model() const;
  PROTOBUF_NODISCARD ::operations_research::sat::CpModelProto* release_model();
  ::operations_research::sat::CpModelProto* mutable_model();
  void set_allocated_model(::operations_research::sat::CpModelProto* value);
  void unsafe_arena_set_allocated_model(::operations_research::sat::CpModelProto* value);
  ::operations_research::sat::CpModelProto* unsafe_arena_release_model();

  private:
  const ::operations_research::sat::CpModelProto& _internal_model() const;
  ::operations_research::sat::CpModelProto* _internal_mutable_model();

  public:
  // .operations_research.sat.SatParameters parameters = 3;
  bool has_parameters() const;
  void clear_parameters() ;
  const ::operations_research::sat::SatParameters& parameters() const;
  PROTOBUF_NODISCARD ::operations_research::sat::SatParameters* release_parameters();
  ::operations_research::sat::SatParameters* mutable_parameters();
  void set_allocated_parameters(::operations_research::sat::SatParameters* value);
  void unsafe_arena_set_allocated_parameters(::operations_research::sat::SatParameters* value);
  ::operations_research::sat::SatParameters* unsafe_arena_release_parameters();

  private:
  const ::operations_research::sat::SatParameters& _internal_parameters() const;
  ::operations_research::sat::SatParameters* _internal_mutable_parameters();

  public:
  // @@protoc_insertion_point(class_scope:operations_research.sat.v1.CpSolverRequest)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      2, 2, 2,
      0, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from);
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    ::operations_research::sat::CpModelProto* model_;
    ::operations_research::sat::SatParameters* parameters_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// CpSolverRequest

// .operations_research.sat.CpModelProto model = 1;
inline bool CpSolverRequest::has_model() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.model_ != nullptr);
  return value;
}
inline const ::operations_research::sat::CpModelProto& CpSolverRequest::_internal_model() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  const ::operations_research::sat::CpModelProto* p = _impl_.model_;
  return p != nullptr ? *p : reinterpret_cast<const ::operations_research::sat::CpModelProto&>(::operations_research::sat::_CpModelProto_default_instance_);
}
inline const ::operations_research::sat::CpModelProto& CpSolverRequest::model() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:operations_research.sat.v1.CpSolverRequest.model)
  return _internal_model();
}
inline void CpSolverRequest::unsafe_arena_set_allocated_model(::operations_research::sat::CpModelProto* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.model_);
  }
  _impl_.model_ = reinterpret_cast<::operations_research::sat::CpModelProto*>(value);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:operations_research.sat.v1.CpSolverRequest.model)
}
inline ::operations_research::sat::CpModelProto* CpSolverRequest::release_model() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);

  _impl_._has_bits_[0] &= ~0x00000001u;
  ::operations_research::sat::CpModelProto* released = _impl_.model_;
  _impl_.model_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old = reinterpret_cast<::google::protobuf::MessageLite*>(released);
  released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  if (GetArena() == nullptr) {
    delete old;
  }
#else   // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArena() != nullptr) {
    released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return released;
}
inline ::operations_research::sat::CpModelProto* CpSolverRequest::unsafe_arena_release_model() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:operations_research.sat.v1.CpSolverRequest.model)

  _impl_._has_bits_[0] &= ~0x00000001u;
  ::operations_research::sat::CpModelProto* temp = _impl_.model_;
  _impl_.model_ = nullptr;
  return temp;
}
inline ::operations_research::sat::CpModelProto* CpSolverRequest::_internal_mutable_model() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (_impl_.model_ == nullptr) {
    auto* p = ::google::protobuf::Message::DefaultConstruct<::operations_research::sat::CpModelProto>(GetArena());
    _impl_.model_ = reinterpret_cast<::operations_research::sat::CpModelProto*>(p);
  }
  return _impl_.model_;
}
inline ::operations_research::sat::CpModelProto* CpSolverRequest::mutable_model() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  _impl_._has_bits_[0] |= 0x00000001u;
  ::operations_research::sat::CpModelProto* _msg = _internal_mutable_model();
  // @@protoc_insertion_point(field_mutable:operations_research.sat.v1.CpSolverRequest.model)
  return _msg;
}
inline void CpSolverRequest::set_allocated_model(::operations_research::sat::CpModelProto* value) {
  ::google::protobuf::Arena* message_arena = GetArena();
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (message_arena == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.model_);
  }

  if (value != nullptr) {
    ::google::protobuf::Arena* submessage_arena = reinterpret_cast<::google::protobuf::MessageLite*>(value)->GetArena();
    if (message_arena != submessage_arena) {
      value = ::google::protobuf::internal::GetOwnedMessage(message_arena, value, submessage_arena);
    }
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }

  _impl_.model_ = reinterpret_cast<::operations_research::sat::CpModelProto*>(value);
  // @@protoc_insertion_point(field_set_allocated:operations_research.sat.v1.CpSolverRequest.model)
}

// .operations_research.sat.SatParameters parameters = 3;
inline bool CpSolverRequest::has_parameters() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.parameters_ != nullptr);
  return value;
}
inline const ::operations_research::sat::SatParameters& CpSolverRequest::_internal_parameters() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  const ::operations_research::sat::SatParameters* p = _impl_.parameters_;
  return p != nullptr ? *p : reinterpret_cast<const ::operations_research::sat::SatParameters&>(::operations_research::sat::_SatParameters_default_instance_);
}
inline const ::operations_research::sat::SatParameters& CpSolverRequest::parameters() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:operations_research.sat.v1.CpSolverRequest.parameters)
  return _internal_parameters();
}
inline void CpSolverRequest::unsafe_arena_set_allocated_parameters(::operations_research::sat::SatParameters* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.parameters_);
  }
  _impl_.parameters_ = reinterpret_cast<::operations_research::sat::SatParameters*>(value);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:operations_research.sat.v1.CpSolverRequest.parameters)
}
inline ::operations_research::sat::SatParameters* CpSolverRequest::release_parameters() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);

  _impl_._has_bits_[0] &= ~0x00000002u;
  ::operations_research::sat::SatParameters* released = _impl_.parameters_;
  _impl_.parameters_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old = reinterpret_cast<::google::protobuf::MessageLite*>(released);
  released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  if (GetArena() == nullptr) {
    delete old;
  }
#else   // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArena() != nullptr) {
    released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return released;
}
inline ::operations_research::sat::SatParameters* CpSolverRequest::unsafe_arena_release_parameters() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:operations_research.sat.v1.CpSolverRequest.parameters)

  _impl_._has_bits_[0] &= ~0x00000002u;
  ::operations_research::sat::SatParameters* temp = _impl_.parameters_;
  _impl_.parameters_ = nullptr;
  return temp;
}
inline ::operations_research::sat::SatParameters* CpSolverRequest::_internal_mutable_parameters() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (_impl_.parameters_ == nullptr) {
    auto* p = ::google::protobuf::Message::DefaultConstruct<::operations_research::sat::SatParameters>(GetArena());
    _impl_.parameters_ = reinterpret_cast<::operations_research::sat::SatParameters*>(p);
  }
  return _impl_.parameters_;
}
inline ::operations_research::sat::SatParameters* CpSolverRequest::mutable_parameters() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  _impl_._has_bits_[0] |= 0x00000002u;
  ::operations_research::sat::SatParameters* _msg = _internal_mutable_parameters();
  // @@protoc_insertion_point(field_mutable:operations_research.sat.v1.CpSolverRequest.parameters)
  return _msg;
}
inline void CpSolverRequest::set_allocated_parameters(::operations_research::sat::SatParameters* value) {
  ::google::protobuf::Arena* message_arena = GetArena();
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (message_arena == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.parameters_);
  }

  if (value != nullptr) {
    ::google::protobuf::Arena* submessage_arena = reinterpret_cast<::google::protobuf::MessageLite*>(value)->GetArena();
    if (message_arena != submessage_arena) {
      value = ::google::protobuf::internal::GetOwnedMessage(message_arena, value, submessage_arena);
    }
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }

  _impl_.parameters_ = reinterpret_cast<::operations_research::sat::SatParameters*>(value);
  // @@protoc_insertion_point(field_set_allocated:operations_research.sat.v1.CpSolverRequest.parameters)
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace v1
}  // namespace sat
}  // namespace operations_research


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_ortools_2fsat_2fcp_5fmodel_5fservice_2eproto_2epb_2eh
