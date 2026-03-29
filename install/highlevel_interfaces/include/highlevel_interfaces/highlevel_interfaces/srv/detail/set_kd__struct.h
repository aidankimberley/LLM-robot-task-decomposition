// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from highlevel_interfaces:srv/SetKD.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "highlevel_interfaces/srv/set_kd.h"


#ifndef HIGHLEVEL_INTERFACES__SRV__DETAIL__SET_KD__STRUCT_H_
#define HIGHLEVEL_INTERFACES__SRV__DETAIL__SET_KD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetKD in the package highlevel_interfaces.
typedef struct highlevel_interfaces__srv__SetKD_Request
{
  double k;
  double d;
} highlevel_interfaces__srv__SetKD_Request;

// Struct for a sequence of highlevel_interfaces__srv__SetKD_Request.
typedef struct highlevel_interfaces__srv__SetKD_Request__Sequence
{
  highlevel_interfaces__srv__SetKD_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} highlevel_interfaces__srv__SetKD_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/SetKD in the package highlevel_interfaces.
typedef struct highlevel_interfaces__srv__SetKD_Response
{
  bool success;
} highlevel_interfaces__srv__SetKD_Response;

// Struct for a sequence of highlevel_interfaces__srv__SetKD_Response.
typedef struct highlevel_interfaces__srv__SetKD_Response__Sequence
{
  highlevel_interfaces__srv__SetKD_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} highlevel_interfaces__srv__SetKD_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  highlevel_interfaces__srv__SetKD_Event__request__MAX_SIZE = 1
};
// response
enum
{
  highlevel_interfaces__srv__SetKD_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/SetKD in the package highlevel_interfaces.
typedef struct highlevel_interfaces__srv__SetKD_Event
{
  service_msgs__msg__ServiceEventInfo info;
  highlevel_interfaces__srv__SetKD_Request__Sequence request;
  highlevel_interfaces__srv__SetKD_Response__Sequence response;
} highlevel_interfaces__srv__SetKD_Event;

// Struct for a sequence of highlevel_interfaces__srv__SetKD_Event.
typedef struct highlevel_interfaces__srv__SetKD_Event__Sequence
{
  highlevel_interfaces__srv__SetKD_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} highlevel_interfaces__srv__SetKD_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HIGHLEVEL_INTERFACES__SRV__DETAIL__SET_KD__STRUCT_H_
