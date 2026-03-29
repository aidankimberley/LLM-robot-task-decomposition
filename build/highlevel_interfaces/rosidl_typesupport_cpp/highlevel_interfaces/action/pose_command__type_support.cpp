// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from highlevel_interfaces:action/PoseCommand.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "highlevel_interfaces/action/detail/pose_command__functions.h"
#include "highlevel_interfaces/action/detail/pose_command__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace highlevel_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseCommand_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseCommand_Goal_type_support_ids_t;

static const _PoseCommand_Goal_type_support_ids_t _PoseCommand_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PoseCommand_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseCommand_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseCommand_Goal_type_support_symbol_names_t _PoseCommand_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, highlevel_interfaces, action, PoseCommand_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, highlevel_interfaces, action, PoseCommand_Goal)),
  }
};

typedef struct _PoseCommand_Goal_type_support_data_t
{
  void * data[2];
} _PoseCommand_Goal_type_support_data_t;

static _PoseCommand_Goal_type_support_data_t _PoseCommand_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseCommand_Goal_message_typesupport_map = {
  2,
  "highlevel_interfaces",
  &_PoseCommand_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_PoseCommand_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_PoseCommand_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseCommand_Goal_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseCommand_Goal_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &highlevel_interfaces__action__PoseCommand_Goal__get_type_hash,
  &highlevel_interfaces__action__PoseCommand_Goal__get_type_description,
  &highlevel_interfaces__action__PoseCommand_Goal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace highlevel_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<highlevel_interfaces::action::PoseCommand_Goal>()
{
  return &::highlevel_interfaces::action::rosidl_typesupport_cpp::PoseCommand_Goal_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, highlevel_interfaces, action, PoseCommand_Goal)() {
  return get_message_type_support_handle<highlevel_interfaces::action::PoseCommand_Goal>();
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
// #include "highlevel_interfaces/action/detail/pose_command__functions.h"
// already included above
// #include "highlevel_interfaces/action/detail/pose_command__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseCommand_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseCommand_Result_type_support_ids_t;

static const _PoseCommand_Result_type_support_ids_t _PoseCommand_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PoseCommand_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseCommand_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseCommand_Result_type_support_symbol_names_t _PoseCommand_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, highlevel_interfaces, action, PoseCommand_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, highlevel_interfaces, action, PoseCommand_Result)),
  }
};

typedef struct _PoseCommand_Result_type_support_data_t
{
  void * data[2];
} _PoseCommand_Result_type_support_data_t;

static _PoseCommand_Result_type_support_data_t _PoseCommand_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseCommand_Result_message_typesupport_map = {
  2,
  "highlevel_interfaces",
  &_PoseCommand_Result_message_typesupport_ids.typesupport_identifier[0],
  &_PoseCommand_Result_message_typesupport_symbol_names.symbol_name[0],
  &_PoseCommand_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseCommand_Result_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseCommand_Result_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &highlevel_interfaces__action__PoseCommand_Result__get_type_hash,
  &highlevel_interfaces__action__PoseCommand_Result__get_type_description,
  &highlevel_interfaces__action__PoseCommand_Result__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace highlevel_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<highlevel_interfaces::action::PoseCommand_Result>()
{
  return &::highlevel_interfaces::action::rosidl_typesupport_cpp::PoseCommand_Result_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, highlevel_interfaces, action, PoseCommand_Result)() {
  return get_message_type_support_handle<highlevel_interfaces::action::PoseCommand_Result>();
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
// #include "highlevel_interfaces/action/detail/pose_command__functions.h"
// already included above
// #include "highlevel_interfaces/action/detail/pose_command__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseCommand_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseCommand_Feedback_type_support_ids_t;

static const _PoseCommand_Feedback_type_support_ids_t _PoseCommand_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PoseCommand_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseCommand_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseCommand_Feedback_type_support_symbol_names_t _PoseCommand_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, highlevel_interfaces, action, PoseCommand_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, highlevel_interfaces, action, PoseCommand_Feedback)),
  }
};

typedef struct _PoseCommand_Feedback_type_support_data_t
{
  void * data[2];
} _PoseCommand_Feedback_type_support_data_t;

static _PoseCommand_Feedback_type_support_data_t _PoseCommand_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseCommand_Feedback_message_typesupport_map = {
  2,
  "highlevel_interfaces",
  &_PoseCommand_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_PoseCommand_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_PoseCommand_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseCommand_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseCommand_Feedback_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &highlevel_interfaces__action__PoseCommand_Feedback__get_type_hash,
  &highlevel_interfaces__action__PoseCommand_Feedback__get_type_description,
  &highlevel_interfaces__action__PoseCommand_Feedback__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace highlevel_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<highlevel_interfaces::action::PoseCommand_Feedback>()
{
  return &::highlevel_interfaces::action::rosidl_typesupport_cpp::PoseCommand_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, highlevel_interfaces, action, PoseCommand_Feedback)() {
  return get_message_type_support_handle<highlevel_interfaces::action::PoseCommand_Feedback>();
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
// #include "highlevel_interfaces/action/detail/pose_command__functions.h"
// already included above
// #include "highlevel_interfaces/action/detail/pose_command__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseCommand_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseCommand_SendGoal_Request_type_support_ids_t;

static const _PoseCommand_SendGoal_Request_type_support_ids_t _PoseCommand_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PoseCommand_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseCommand_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseCommand_SendGoal_Request_type_support_symbol_names_t _PoseCommand_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, highlevel_interfaces, action, PoseCommand_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, highlevel_interfaces, action, PoseCommand_SendGoal_Request)),
  }
};

typedef struct _PoseCommand_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _PoseCommand_SendGoal_Request_type_support_data_t;

static _PoseCommand_SendGoal_Request_type_support_data_t _PoseCommand_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseCommand_SendGoal_Request_message_typesupport_map = {
  2,
  "highlevel_interfaces",
  &_PoseCommand_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_PoseCommand_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_PoseCommand_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseCommand_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseCommand_SendGoal_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &highlevel_interfaces__action__PoseCommand_SendGoal_Request__get_type_hash,
  &highlevel_interfaces__action__PoseCommand_SendGoal_Request__get_type_description,
  &highlevel_interfaces__action__PoseCommand_SendGoal_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace highlevel_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<highlevel_interfaces::action::PoseCommand_SendGoal_Request>()
{
  return &::highlevel_interfaces::action::rosidl_typesupport_cpp::PoseCommand_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, highlevel_interfaces, action, PoseCommand_SendGoal_Request)() {
  return get_message_type_support_handle<highlevel_interfaces::action::PoseCommand_SendGoal_Request>();
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
// #include "highlevel_interfaces/action/detail/pose_command__functions.h"
// already included above
// #include "highlevel_interfaces/action/detail/pose_command__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseCommand_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseCommand_SendGoal_Response_type_support_ids_t;

static const _PoseCommand_SendGoal_Response_type_support_ids_t _PoseCommand_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PoseCommand_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseCommand_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseCommand_SendGoal_Response_type_support_symbol_names_t _PoseCommand_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, highlevel_interfaces, action, PoseCommand_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, highlevel_interfaces, action, PoseCommand_SendGoal_Response)),
  }
};

typedef struct _PoseCommand_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _PoseCommand_SendGoal_Response_type_support_data_t;

static _PoseCommand_SendGoal_Response_type_support_data_t _PoseCommand_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseCommand_SendGoal_Response_message_typesupport_map = {
  2,
  "highlevel_interfaces",
  &_PoseCommand_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_PoseCommand_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_PoseCommand_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseCommand_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseCommand_SendGoal_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &highlevel_interfaces__action__PoseCommand_SendGoal_Response__get_type_hash,
  &highlevel_interfaces__action__PoseCommand_SendGoal_Response__get_type_description,
  &highlevel_interfaces__action__PoseCommand_SendGoal_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace highlevel_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<highlevel_interfaces::action::PoseCommand_SendGoal_Response>()
{
  return &::highlevel_interfaces::action::rosidl_typesupport_cpp::PoseCommand_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, highlevel_interfaces, action, PoseCommand_SendGoal_Response)() {
  return get_message_type_support_handle<highlevel_interfaces::action::PoseCommand_SendGoal_Response>();
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
// #include "highlevel_interfaces/action/detail/pose_command__functions.h"
// already included above
// #include "highlevel_interfaces/action/detail/pose_command__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseCommand_SendGoal_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseCommand_SendGoal_Event_type_support_ids_t;

static const _PoseCommand_SendGoal_Event_type_support_ids_t _PoseCommand_SendGoal_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PoseCommand_SendGoal_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseCommand_SendGoal_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseCommand_SendGoal_Event_type_support_symbol_names_t _PoseCommand_SendGoal_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, highlevel_interfaces, action, PoseCommand_SendGoal_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, highlevel_interfaces, action, PoseCommand_SendGoal_Event)),
  }
};

typedef struct _PoseCommand_SendGoal_Event_type_support_data_t
{
  void * data[2];
} _PoseCommand_SendGoal_Event_type_support_data_t;

static _PoseCommand_SendGoal_Event_type_support_data_t _PoseCommand_SendGoal_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseCommand_SendGoal_Event_message_typesupport_map = {
  2,
  "highlevel_interfaces",
  &_PoseCommand_SendGoal_Event_message_typesupport_ids.typesupport_identifier[0],
  &_PoseCommand_SendGoal_Event_message_typesupport_symbol_names.symbol_name[0],
  &_PoseCommand_SendGoal_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseCommand_SendGoal_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseCommand_SendGoal_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &highlevel_interfaces__action__PoseCommand_SendGoal_Event__get_type_hash,
  &highlevel_interfaces__action__PoseCommand_SendGoal_Event__get_type_description,
  &highlevel_interfaces__action__PoseCommand_SendGoal_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace highlevel_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<highlevel_interfaces::action::PoseCommand_SendGoal_Event>()
{
  return &::highlevel_interfaces::action::rosidl_typesupport_cpp::PoseCommand_SendGoal_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, highlevel_interfaces, action, PoseCommand_SendGoal_Event)() {
  return get_message_type_support_handle<highlevel_interfaces::action::PoseCommand_SendGoal_Event>();
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
// #include "highlevel_interfaces/action/detail/pose_command__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseCommand_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseCommand_SendGoal_type_support_ids_t;

static const _PoseCommand_SendGoal_type_support_ids_t _PoseCommand_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PoseCommand_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseCommand_SendGoal_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseCommand_SendGoal_type_support_symbol_names_t _PoseCommand_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, highlevel_interfaces, action, PoseCommand_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, highlevel_interfaces, action, PoseCommand_SendGoal)),
  }
};

typedef struct _PoseCommand_SendGoal_type_support_data_t
{
  void * data[2];
} _PoseCommand_SendGoal_type_support_data_t;

static _PoseCommand_SendGoal_type_support_data_t _PoseCommand_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseCommand_SendGoal_service_typesupport_map = {
  2,
  "highlevel_interfaces",
  &_PoseCommand_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_PoseCommand_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_PoseCommand_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t PoseCommand_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseCommand_SendGoal_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<highlevel_interfaces::action::PoseCommand_SendGoal_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<highlevel_interfaces::action::PoseCommand_SendGoal_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<highlevel_interfaces::action::PoseCommand_SendGoal_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<highlevel_interfaces::action::PoseCommand_SendGoal>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<highlevel_interfaces::action::PoseCommand_SendGoal>,
  &highlevel_interfaces__action__PoseCommand_SendGoal__get_type_hash,
  &highlevel_interfaces__action__PoseCommand_SendGoal__get_type_description,
  &highlevel_interfaces__action__PoseCommand_SendGoal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace highlevel_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<highlevel_interfaces::action::PoseCommand_SendGoal>()
{
  return &::highlevel_interfaces::action::rosidl_typesupport_cpp::PoseCommand_SendGoal_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, highlevel_interfaces, action, PoseCommand_SendGoal)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<highlevel_interfaces::action::PoseCommand_SendGoal>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "highlevel_interfaces/action/detail/pose_command__functions.h"
// already included above
// #include "highlevel_interfaces/action/detail/pose_command__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseCommand_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseCommand_GetResult_Request_type_support_ids_t;

static const _PoseCommand_GetResult_Request_type_support_ids_t _PoseCommand_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PoseCommand_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseCommand_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseCommand_GetResult_Request_type_support_symbol_names_t _PoseCommand_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, highlevel_interfaces, action, PoseCommand_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, highlevel_interfaces, action, PoseCommand_GetResult_Request)),
  }
};

typedef struct _PoseCommand_GetResult_Request_type_support_data_t
{
  void * data[2];
} _PoseCommand_GetResult_Request_type_support_data_t;

static _PoseCommand_GetResult_Request_type_support_data_t _PoseCommand_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseCommand_GetResult_Request_message_typesupport_map = {
  2,
  "highlevel_interfaces",
  &_PoseCommand_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_PoseCommand_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_PoseCommand_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseCommand_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseCommand_GetResult_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &highlevel_interfaces__action__PoseCommand_GetResult_Request__get_type_hash,
  &highlevel_interfaces__action__PoseCommand_GetResult_Request__get_type_description,
  &highlevel_interfaces__action__PoseCommand_GetResult_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace highlevel_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<highlevel_interfaces::action::PoseCommand_GetResult_Request>()
{
  return &::highlevel_interfaces::action::rosidl_typesupport_cpp::PoseCommand_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, highlevel_interfaces, action, PoseCommand_GetResult_Request)() {
  return get_message_type_support_handle<highlevel_interfaces::action::PoseCommand_GetResult_Request>();
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
// #include "highlevel_interfaces/action/detail/pose_command__functions.h"
// already included above
// #include "highlevel_interfaces/action/detail/pose_command__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseCommand_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseCommand_GetResult_Response_type_support_ids_t;

static const _PoseCommand_GetResult_Response_type_support_ids_t _PoseCommand_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PoseCommand_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseCommand_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseCommand_GetResult_Response_type_support_symbol_names_t _PoseCommand_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, highlevel_interfaces, action, PoseCommand_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, highlevel_interfaces, action, PoseCommand_GetResult_Response)),
  }
};

typedef struct _PoseCommand_GetResult_Response_type_support_data_t
{
  void * data[2];
} _PoseCommand_GetResult_Response_type_support_data_t;

static _PoseCommand_GetResult_Response_type_support_data_t _PoseCommand_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseCommand_GetResult_Response_message_typesupport_map = {
  2,
  "highlevel_interfaces",
  &_PoseCommand_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_PoseCommand_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_PoseCommand_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseCommand_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseCommand_GetResult_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &highlevel_interfaces__action__PoseCommand_GetResult_Response__get_type_hash,
  &highlevel_interfaces__action__PoseCommand_GetResult_Response__get_type_description,
  &highlevel_interfaces__action__PoseCommand_GetResult_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace highlevel_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<highlevel_interfaces::action::PoseCommand_GetResult_Response>()
{
  return &::highlevel_interfaces::action::rosidl_typesupport_cpp::PoseCommand_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, highlevel_interfaces, action, PoseCommand_GetResult_Response)() {
  return get_message_type_support_handle<highlevel_interfaces::action::PoseCommand_GetResult_Response>();
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
// #include "highlevel_interfaces/action/detail/pose_command__functions.h"
// already included above
// #include "highlevel_interfaces/action/detail/pose_command__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseCommand_GetResult_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseCommand_GetResult_Event_type_support_ids_t;

static const _PoseCommand_GetResult_Event_type_support_ids_t _PoseCommand_GetResult_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PoseCommand_GetResult_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseCommand_GetResult_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseCommand_GetResult_Event_type_support_symbol_names_t _PoseCommand_GetResult_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, highlevel_interfaces, action, PoseCommand_GetResult_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, highlevel_interfaces, action, PoseCommand_GetResult_Event)),
  }
};

typedef struct _PoseCommand_GetResult_Event_type_support_data_t
{
  void * data[2];
} _PoseCommand_GetResult_Event_type_support_data_t;

static _PoseCommand_GetResult_Event_type_support_data_t _PoseCommand_GetResult_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseCommand_GetResult_Event_message_typesupport_map = {
  2,
  "highlevel_interfaces",
  &_PoseCommand_GetResult_Event_message_typesupport_ids.typesupport_identifier[0],
  &_PoseCommand_GetResult_Event_message_typesupport_symbol_names.symbol_name[0],
  &_PoseCommand_GetResult_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseCommand_GetResult_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseCommand_GetResult_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &highlevel_interfaces__action__PoseCommand_GetResult_Event__get_type_hash,
  &highlevel_interfaces__action__PoseCommand_GetResult_Event__get_type_description,
  &highlevel_interfaces__action__PoseCommand_GetResult_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace highlevel_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<highlevel_interfaces::action::PoseCommand_GetResult_Event>()
{
  return &::highlevel_interfaces::action::rosidl_typesupport_cpp::PoseCommand_GetResult_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, highlevel_interfaces, action, PoseCommand_GetResult_Event)() {
  return get_message_type_support_handle<highlevel_interfaces::action::PoseCommand_GetResult_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "highlevel_interfaces/action/detail/pose_command__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace highlevel_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseCommand_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseCommand_GetResult_type_support_ids_t;

static const _PoseCommand_GetResult_type_support_ids_t _PoseCommand_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PoseCommand_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseCommand_GetResult_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseCommand_GetResult_type_support_symbol_names_t _PoseCommand_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, highlevel_interfaces, action, PoseCommand_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, highlevel_interfaces, action, PoseCommand_GetResult)),
  }
};

typedef struct _PoseCommand_GetResult_type_support_data_t
{
  void * data[2];
} _PoseCommand_GetResult_type_support_data_t;

static _PoseCommand_GetResult_type_support_data_t _PoseCommand_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseCommand_GetResult_service_typesupport_map = {
  2,
  "highlevel_interfaces",
  &_PoseCommand_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_PoseCommand_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_PoseCommand_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t PoseCommand_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseCommand_GetResult_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<highlevel_interfaces::action::PoseCommand_GetResult_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<highlevel_interfaces::action::PoseCommand_GetResult_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<highlevel_interfaces::action::PoseCommand_GetResult_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<highlevel_interfaces::action::PoseCommand_GetResult>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<highlevel_interfaces::action::PoseCommand_GetResult>,
  &highlevel_interfaces__action__PoseCommand_GetResult__get_type_hash,
  &highlevel_interfaces__action__PoseCommand_GetResult__get_type_description,
  &highlevel_interfaces__action__PoseCommand_GetResult__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace highlevel_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<highlevel_interfaces::action::PoseCommand_GetResult>()
{
  return &::highlevel_interfaces::action::rosidl_typesupport_cpp::PoseCommand_GetResult_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, highlevel_interfaces, action, PoseCommand_GetResult)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<highlevel_interfaces::action::PoseCommand_GetResult>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "highlevel_interfaces/action/detail/pose_command__functions.h"
// already included above
// #include "highlevel_interfaces/action/detail/pose_command__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _PoseCommand_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PoseCommand_FeedbackMessage_type_support_ids_t;

static const _PoseCommand_FeedbackMessage_type_support_ids_t _PoseCommand_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _PoseCommand_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PoseCommand_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PoseCommand_FeedbackMessage_type_support_symbol_names_t _PoseCommand_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, highlevel_interfaces, action, PoseCommand_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, highlevel_interfaces, action, PoseCommand_FeedbackMessage)),
  }
};

typedef struct _PoseCommand_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _PoseCommand_FeedbackMessage_type_support_data_t;

static _PoseCommand_FeedbackMessage_type_support_data_t _PoseCommand_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PoseCommand_FeedbackMessage_message_typesupport_map = {
  2,
  "highlevel_interfaces",
  &_PoseCommand_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_PoseCommand_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_PoseCommand_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PoseCommand_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PoseCommand_FeedbackMessage_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &highlevel_interfaces__action__PoseCommand_FeedbackMessage__get_type_hash,
  &highlevel_interfaces__action__PoseCommand_FeedbackMessage__get_type_description,
  &highlevel_interfaces__action__PoseCommand_FeedbackMessage__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace highlevel_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<highlevel_interfaces::action::PoseCommand_FeedbackMessage>()
{
  return &::highlevel_interfaces::action::rosidl_typesupport_cpp::PoseCommand_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, highlevel_interfaces, action, PoseCommand_FeedbackMessage)() {
  return get_message_type_support_handle<highlevel_interfaces::action::PoseCommand_FeedbackMessage>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

#include "action_msgs/msg/goal_status_array.hpp"
#include "action_msgs/srv/cancel_goal.hpp"
// already included above
// #include "highlevel_interfaces/action/detail/pose_command__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_typesupport_cpp/action_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"

namespace highlevel_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

static rosidl_action_type_support_t PoseCommand_action_type_support_handle = {
  NULL, NULL, NULL, NULL, NULL,
  &highlevel_interfaces__action__PoseCommand__get_type_hash,
  &highlevel_interfaces__action__PoseCommand__get_type_description,
  &highlevel_interfaces__action__PoseCommand__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace highlevel_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
get_action_type_support_handle<highlevel_interfaces::action::PoseCommand>()
{
  using ::highlevel_interfaces::action::rosidl_typesupport_cpp::PoseCommand_action_type_support_handle;
  // Thread-safe by always writing the same values to the static struct
  PoseCommand_action_type_support_handle.goal_service_type_support = get_service_type_support_handle<::highlevel_interfaces::action::PoseCommand::Impl::SendGoalService>();
  PoseCommand_action_type_support_handle.result_service_type_support = get_service_type_support_handle<::highlevel_interfaces::action::PoseCommand::Impl::GetResultService>();
  PoseCommand_action_type_support_handle.cancel_service_type_support = get_service_type_support_handle<::highlevel_interfaces::action::PoseCommand::Impl::CancelGoalService>();
  PoseCommand_action_type_support_handle.feedback_message_type_support = get_message_type_support_handle<::highlevel_interfaces::action::PoseCommand::Impl::FeedbackMessage>();
  PoseCommand_action_type_support_handle.status_message_type_support = get_message_type_support_handle<::highlevel_interfaces::action::PoseCommand::Impl::GoalStatusMessage>();
  return &PoseCommand_action_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(rosidl_typesupport_cpp, highlevel_interfaces, action, PoseCommand)() {
  return ::rosidl_typesupport_cpp::get_action_type_support_handle<highlevel_interfaces::action::PoseCommand>();
}

#ifdef __cplusplus
}
#endif
