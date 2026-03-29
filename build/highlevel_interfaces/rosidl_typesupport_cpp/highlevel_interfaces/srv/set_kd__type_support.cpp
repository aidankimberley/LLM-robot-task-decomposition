// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from highlevel_interfaces:srv/SetKD.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "highlevel_interfaces/srv/detail/set_kd__functions.h"
#include "highlevel_interfaces/srv/detail/set_kd__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace highlevel_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetKD_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetKD_Request_type_support_ids_t;

static const _SetKD_Request_type_support_ids_t _SetKD_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetKD_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetKD_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetKD_Request_type_support_symbol_names_t _SetKD_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, highlevel_interfaces, srv, SetKD_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, highlevel_interfaces, srv, SetKD_Request)),
  }
};

typedef struct _SetKD_Request_type_support_data_t
{
  void * data[2];
} _SetKD_Request_type_support_data_t;

static _SetKD_Request_type_support_data_t _SetKD_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetKD_Request_message_typesupport_map = {
  2,
  "highlevel_interfaces",
  &_SetKD_Request_message_typesupport_ids.typesupport_identifier[0],
  &_SetKD_Request_message_typesupport_symbol_names.symbol_name[0],
  &_SetKD_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetKD_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetKD_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &highlevel_interfaces__srv__SetKD_Request__get_type_hash,
  &highlevel_interfaces__srv__SetKD_Request__get_type_description,
  &highlevel_interfaces__srv__SetKD_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace highlevel_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<highlevel_interfaces::srv::SetKD_Request>()
{
  return &::highlevel_interfaces::srv::rosidl_typesupport_cpp::SetKD_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, highlevel_interfaces, srv, SetKD_Request)() {
  return get_message_type_support_handle<highlevel_interfaces::srv::SetKD_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "highlevel_interfaces/srv/detail/set_kd__functions.h"
// already included above
// #include "highlevel_interfaces/srv/detail/set_kd__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace highlevel_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetKD_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetKD_Response_type_support_ids_t;

static const _SetKD_Response_type_support_ids_t _SetKD_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetKD_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetKD_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetKD_Response_type_support_symbol_names_t _SetKD_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, highlevel_interfaces, srv, SetKD_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, highlevel_interfaces, srv, SetKD_Response)),
  }
};

typedef struct _SetKD_Response_type_support_data_t
{
  void * data[2];
} _SetKD_Response_type_support_data_t;

static _SetKD_Response_type_support_data_t _SetKD_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetKD_Response_message_typesupport_map = {
  2,
  "highlevel_interfaces",
  &_SetKD_Response_message_typesupport_ids.typesupport_identifier[0],
  &_SetKD_Response_message_typesupport_symbol_names.symbol_name[0],
  &_SetKD_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetKD_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetKD_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &highlevel_interfaces__srv__SetKD_Response__get_type_hash,
  &highlevel_interfaces__srv__SetKD_Response__get_type_description,
  &highlevel_interfaces__srv__SetKD_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace highlevel_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<highlevel_interfaces::srv::SetKD_Response>()
{
  return &::highlevel_interfaces::srv::rosidl_typesupport_cpp::SetKD_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, highlevel_interfaces, srv, SetKD_Response)() {
  return get_message_type_support_handle<highlevel_interfaces::srv::SetKD_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "highlevel_interfaces/srv/detail/set_kd__functions.h"
// already included above
// #include "highlevel_interfaces/srv/detail/set_kd__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace highlevel_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetKD_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetKD_Event_type_support_ids_t;

static const _SetKD_Event_type_support_ids_t _SetKD_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetKD_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetKD_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetKD_Event_type_support_symbol_names_t _SetKD_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, highlevel_interfaces, srv, SetKD_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, highlevel_interfaces, srv, SetKD_Event)),
  }
};

typedef struct _SetKD_Event_type_support_data_t
{
  void * data[2];
} _SetKD_Event_type_support_data_t;

static _SetKD_Event_type_support_data_t _SetKD_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetKD_Event_message_typesupport_map = {
  2,
  "highlevel_interfaces",
  &_SetKD_Event_message_typesupport_ids.typesupport_identifier[0],
  &_SetKD_Event_message_typesupport_symbol_names.symbol_name[0],
  &_SetKD_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetKD_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetKD_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &highlevel_interfaces__srv__SetKD_Event__get_type_hash,
  &highlevel_interfaces__srv__SetKD_Event__get_type_description,
  &highlevel_interfaces__srv__SetKD_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace highlevel_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<highlevel_interfaces::srv::SetKD_Event>()
{
  return &::highlevel_interfaces::srv::rosidl_typesupport_cpp::SetKD_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, highlevel_interfaces, srv, SetKD_Event)() {
  return get_message_type_support_handle<highlevel_interfaces::srv::SetKD_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "highlevel_interfaces/srv/detail/set_kd__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace highlevel_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetKD_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetKD_type_support_ids_t;

static const _SetKD_type_support_ids_t _SetKD_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetKD_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetKD_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetKD_type_support_symbol_names_t _SetKD_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, highlevel_interfaces, srv, SetKD)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, highlevel_interfaces, srv, SetKD)),
  }
};

typedef struct _SetKD_type_support_data_t
{
  void * data[2];
} _SetKD_type_support_data_t;

static _SetKD_type_support_data_t _SetKD_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetKD_service_typesupport_map = {
  2,
  "highlevel_interfaces",
  &_SetKD_service_typesupport_ids.typesupport_identifier[0],
  &_SetKD_service_typesupport_symbol_names.symbol_name[0],
  &_SetKD_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t SetKD_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetKD_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<highlevel_interfaces::srv::SetKD_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<highlevel_interfaces::srv::SetKD_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<highlevel_interfaces::srv::SetKD_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<highlevel_interfaces::srv::SetKD>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<highlevel_interfaces::srv::SetKD>,
  &highlevel_interfaces__srv__SetKD__get_type_hash,
  &highlevel_interfaces__srv__SetKD__get_type_description,
  &highlevel_interfaces__srv__SetKD__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace highlevel_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<highlevel_interfaces::srv::SetKD>()
{
  return &::highlevel_interfaces::srv::rosidl_typesupport_cpp::SetKD_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, highlevel_interfaces, srv, SetKD)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<highlevel_interfaces::srv::SetKD>();
}

#ifdef __cplusplus
}
#endif
