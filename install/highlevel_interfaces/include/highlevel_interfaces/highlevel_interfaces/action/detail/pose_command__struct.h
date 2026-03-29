// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from highlevel_interfaces:action/PoseCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "highlevel_interfaces/action/pose_command.h"


#ifndef HIGHLEVEL_INTERFACES__ACTION__DETAIL__POSE_COMMAND__STRUCT_H_
#define HIGHLEVEL_INTERFACES__ACTION__DETAIL__POSE_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/PoseCommand in the package highlevel_interfaces.
typedef struct highlevel_interfaces__action__PoseCommand_Goal
{
  /// target x position
  double x;
  /// target y position
  double y;
  /// target z position
  double z;
  /// target roll
  double roll;
  double pitch;
  double yaw;
} highlevel_interfaces__action__PoseCommand_Goal;

// Struct for a sequence of highlevel_interfaces__action__PoseCommand_Goal.
typedef struct highlevel_interfaces__action__PoseCommand_Goal__Sequence
{
  highlevel_interfaces__action__PoseCommand_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} highlevel_interfaces__action__PoseCommand_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/PoseCommand in the package highlevel_interfaces.
typedef struct highlevel_interfaces__action__PoseCommand_Result
{
  bool success;
  rosidl_runtime_c__String message;
} highlevel_interfaces__action__PoseCommand_Result;

// Struct for a sequence of highlevel_interfaces__action__PoseCommand_Result.
typedef struct highlevel_interfaces__action__PoseCommand_Result__Sequence
{
  highlevel_interfaces__action__PoseCommand_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} highlevel_interfaces__action__PoseCommand_Result__Sequence;

// Constants defined in the message

/// Struct defined in action/PoseCommand in the package highlevel_interfaces.
typedef struct highlevel_interfaces__action__PoseCommand_Feedback
{
  /// distance between feedback and target translation
  double distance_translation;
  /// shortest angle between feedback and orientation
  double distance_orientation;
  /// time elapsed since action request is accepted
  double time_elapsed;
} highlevel_interfaces__action__PoseCommand_Feedback;

// Struct for a sequence of highlevel_interfaces__action__PoseCommand_Feedback.
typedef struct highlevel_interfaces__action__PoseCommand_Feedback__Sequence
{
  highlevel_interfaces__action__PoseCommand_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} highlevel_interfaces__action__PoseCommand_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "highlevel_interfaces/action/detail/pose_command__struct.h"

/// Struct defined in action/PoseCommand in the package highlevel_interfaces.
typedef struct highlevel_interfaces__action__PoseCommand_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  highlevel_interfaces__action__PoseCommand_Goal goal;
} highlevel_interfaces__action__PoseCommand_SendGoal_Request;

// Struct for a sequence of highlevel_interfaces__action__PoseCommand_SendGoal_Request.
typedef struct highlevel_interfaces__action__PoseCommand_SendGoal_Request__Sequence
{
  highlevel_interfaces__action__PoseCommand_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} highlevel_interfaces__action__PoseCommand_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/PoseCommand in the package highlevel_interfaces.
typedef struct highlevel_interfaces__action__PoseCommand_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} highlevel_interfaces__action__PoseCommand_SendGoal_Response;

// Struct for a sequence of highlevel_interfaces__action__PoseCommand_SendGoal_Response.
typedef struct highlevel_interfaces__action__PoseCommand_SendGoal_Response__Sequence
{
  highlevel_interfaces__action__PoseCommand_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} highlevel_interfaces__action__PoseCommand_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  highlevel_interfaces__action__PoseCommand_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  highlevel_interfaces__action__PoseCommand_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/PoseCommand in the package highlevel_interfaces.
typedef struct highlevel_interfaces__action__PoseCommand_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  highlevel_interfaces__action__PoseCommand_SendGoal_Request__Sequence request;
  highlevel_interfaces__action__PoseCommand_SendGoal_Response__Sequence response;
} highlevel_interfaces__action__PoseCommand_SendGoal_Event;

// Struct for a sequence of highlevel_interfaces__action__PoseCommand_SendGoal_Event.
typedef struct highlevel_interfaces__action__PoseCommand_SendGoal_Event__Sequence
{
  highlevel_interfaces__action__PoseCommand_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} highlevel_interfaces__action__PoseCommand_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/PoseCommand in the package highlevel_interfaces.
typedef struct highlevel_interfaces__action__PoseCommand_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} highlevel_interfaces__action__PoseCommand_GetResult_Request;

// Struct for a sequence of highlevel_interfaces__action__PoseCommand_GetResult_Request.
typedef struct highlevel_interfaces__action__PoseCommand_GetResult_Request__Sequence
{
  highlevel_interfaces__action__PoseCommand_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} highlevel_interfaces__action__PoseCommand_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "highlevel_interfaces/action/detail/pose_command__struct.h"

/// Struct defined in action/PoseCommand in the package highlevel_interfaces.
typedef struct highlevel_interfaces__action__PoseCommand_GetResult_Response
{
  int8_t status;
  highlevel_interfaces__action__PoseCommand_Result result;
} highlevel_interfaces__action__PoseCommand_GetResult_Response;

// Struct for a sequence of highlevel_interfaces__action__PoseCommand_GetResult_Response.
typedef struct highlevel_interfaces__action__PoseCommand_GetResult_Response__Sequence
{
  highlevel_interfaces__action__PoseCommand_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} highlevel_interfaces__action__PoseCommand_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  highlevel_interfaces__action__PoseCommand_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  highlevel_interfaces__action__PoseCommand_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/PoseCommand in the package highlevel_interfaces.
typedef struct highlevel_interfaces__action__PoseCommand_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  highlevel_interfaces__action__PoseCommand_GetResult_Request__Sequence request;
  highlevel_interfaces__action__PoseCommand_GetResult_Response__Sequence response;
} highlevel_interfaces__action__PoseCommand_GetResult_Event;

// Struct for a sequence of highlevel_interfaces__action__PoseCommand_GetResult_Event.
typedef struct highlevel_interfaces__action__PoseCommand_GetResult_Event__Sequence
{
  highlevel_interfaces__action__PoseCommand_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} highlevel_interfaces__action__PoseCommand_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "highlevel_interfaces/action/detail/pose_command__struct.h"

/// Struct defined in action/PoseCommand in the package highlevel_interfaces.
typedef struct highlevel_interfaces__action__PoseCommand_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  highlevel_interfaces__action__PoseCommand_Feedback feedback;
} highlevel_interfaces__action__PoseCommand_FeedbackMessage;

// Struct for a sequence of highlevel_interfaces__action__PoseCommand_FeedbackMessage.
typedef struct highlevel_interfaces__action__PoseCommand_FeedbackMessage__Sequence
{
  highlevel_interfaces__action__PoseCommand_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} highlevel_interfaces__action__PoseCommand_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HIGHLEVEL_INTERFACES__ACTION__DETAIL__POSE_COMMAND__STRUCT_H_
