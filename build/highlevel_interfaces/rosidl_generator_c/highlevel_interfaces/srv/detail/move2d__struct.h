// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from highlevel_interfaces:srv/Move2d.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "highlevel_interfaces/srv/move2d.h"


#ifndef HIGHLEVEL_INTERFACES__SRV__DETAIL__MOVE2D__STRUCT_H_
#define HIGHLEVEL_INTERFACES__SRV__DETAIL__MOVE2D__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Move2d in the package highlevel_interfaces.
typedef struct highlevel_interfaces__srv__Move2d_Request
{
  double x;
  double y;
} highlevel_interfaces__srv__Move2d_Request;

// Struct for a sequence of highlevel_interfaces__srv__Move2d_Request.
typedef struct highlevel_interfaces__srv__Move2d_Request__Sequence
{
  highlevel_interfaces__srv__Move2d_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} highlevel_interfaces__srv__Move2d_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/Move2d in the package highlevel_interfaces.
typedef struct highlevel_interfaces__srv__Move2d_Response
{
  bool success;
} highlevel_interfaces__srv__Move2d_Response;

// Struct for a sequence of highlevel_interfaces__srv__Move2d_Response.
typedef struct highlevel_interfaces__srv__Move2d_Response__Sequence
{
  highlevel_interfaces__srv__Move2d_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} highlevel_interfaces__srv__Move2d_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  highlevel_interfaces__srv__Move2d_Event__request__MAX_SIZE = 1
};
// response
enum
{
  highlevel_interfaces__srv__Move2d_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/Move2d in the package highlevel_interfaces.
typedef struct highlevel_interfaces__srv__Move2d_Event
{
  service_msgs__msg__ServiceEventInfo info;
  highlevel_interfaces__srv__Move2d_Request__Sequence request;
  highlevel_interfaces__srv__Move2d_Response__Sequence response;
} highlevel_interfaces__srv__Move2d_Event;

// Struct for a sequence of highlevel_interfaces__srv__Move2d_Event.
typedef struct highlevel_interfaces__srv__Move2d_Event__Sequence
{
  highlevel_interfaces__srv__Move2d_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} highlevel_interfaces__srv__Move2d_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HIGHLEVEL_INTERFACES__SRV__DETAIL__MOVE2D__STRUCT_H_
