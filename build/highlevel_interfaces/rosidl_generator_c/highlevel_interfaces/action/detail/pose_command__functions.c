// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from highlevel_interfaces:action/PoseCommand.idl
// generated code does not contain a copyright notice
#include "highlevel_interfaces/action/detail/pose_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
highlevel_interfaces__action__PoseCommand_Goal__init(highlevel_interfaces__action__PoseCommand_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // z
  // roll
  // pitch
  // yaw
  return true;
}

void
highlevel_interfaces__action__PoseCommand_Goal__fini(highlevel_interfaces__action__PoseCommand_Goal * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // z
  // roll
  // pitch
  // yaw
}

bool
highlevel_interfaces__action__PoseCommand_Goal__are_equal(const highlevel_interfaces__action__PoseCommand_Goal * lhs, const highlevel_interfaces__action__PoseCommand_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // roll
  if (lhs->roll != rhs->roll) {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  return true;
}

bool
highlevel_interfaces__action__PoseCommand_Goal__copy(
  const highlevel_interfaces__action__PoseCommand_Goal * input,
  highlevel_interfaces__action__PoseCommand_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // roll
  output->roll = input->roll;
  // pitch
  output->pitch = input->pitch;
  // yaw
  output->yaw = input->yaw;
  return true;
}

highlevel_interfaces__action__PoseCommand_Goal *
highlevel_interfaces__action__PoseCommand_Goal__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_Goal * msg = (highlevel_interfaces__action__PoseCommand_Goal *)allocator.allocate(sizeof(highlevel_interfaces__action__PoseCommand_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(highlevel_interfaces__action__PoseCommand_Goal));
  bool success = highlevel_interfaces__action__PoseCommand_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
highlevel_interfaces__action__PoseCommand_Goal__destroy(highlevel_interfaces__action__PoseCommand_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    highlevel_interfaces__action__PoseCommand_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
highlevel_interfaces__action__PoseCommand_Goal__Sequence__init(highlevel_interfaces__action__PoseCommand_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_Goal * data = NULL;

  if (size) {
    data = (highlevel_interfaces__action__PoseCommand_Goal *)allocator.zero_allocate(size, sizeof(highlevel_interfaces__action__PoseCommand_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = highlevel_interfaces__action__PoseCommand_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        highlevel_interfaces__action__PoseCommand_Goal__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
highlevel_interfaces__action__PoseCommand_Goal__Sequence__fini(highlevel_interfaces__action__PoseCommand_Goal__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      highlevel_interfaces__action__PoseCommand_Goal__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

highlevel_interfaces__action__PoseCommand_Goal__Sequence *
highlevel_interfaces__action__PoseCommand_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_Goal__Sequence * array = (highlevel_interfaces__action__PoseCommand_Goal__Sequence *)allocator.allocate(sizeof(highlevel_interfaces__action__PoseCommand_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = highlevel_interfaces__action__PoseCommand_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
highlevel_interfaces__action__PoseCommand_Goal__Sequence__destroy(highlevel_interfaces__action__PoseCommand_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    highlevel_interfaces__action__PoseCommand_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
highlevel_interfaces__action__PoseCommand_Goal__Sequence__are_equal(const highlevel_interfaces__action__PoseCommand_Goal__Sequence * lhs, const highlevel_interfaces__action__PoseCommand_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!highlevel_interfaces__action__PoseCommand_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
highlevel_interfaces__action__PoseCommand_Goal__Sequence__copy(
  const highlevel_interfaces__action__PoseCommand_Goal__Sequence * input,
  highlevel_interfaces__action__PoseCommand_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(highlevel_interfaces__action__PoseCommand_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    highlevel_interfaces__action__PoseCommand_Goal * data =
      (highlevel_interfaces__action__PoseCommand_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!highlevel_interfaces__action__PoseCommand_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          highlevel_interfaces__action__PoseCommand_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!highlevel_interfaces__action__PoseCommand_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
highlevel_interfaces__action__PoseCommand_Result__init(highlevel_interfaces__action__PoseCommand_Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    highlevel_interfaces__action__PoseCommand_Result__fini(msg);
    return false;
  }
  return true;
}

void
highlevel_interfaces__action__PoseCommand_Result__fini(highlevel_interfaces__action__PoseCommand_Result * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
highlevel_interfaces__action__PoseCommand_Result__are_equal(const highlevel_interfaces__action__PoseCommand_Result * lhs, const highlevel_interfaces__action__PoseCommand_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
highlevel_interfaces__action__PoseCommand_Result__copy(
  const highlevel_interfaces__action__PoseCommand_Result * input,
  highlevel_interfaces__action__PoseCommand_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

highlevel_interfaces__action__PoseCommand_Result *
highlevel_interfaces__action__PoseCommand_Result__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_Result * msg = (highlevel_interfaces__action__PoseCommand_Result *)allocator.allocate(sizeof(highlevel_interfaces__action__PoseCommand_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(highlevel_interfaces__action__PoseCommand_Result));
  bool success = highlevel_interfaces__action__PoseCommand_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
highlevel_interfaces__action__PoseCommand_Result__destroy(highlevel_interfaces__action__PoseCommand_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    highlevel_interfaces__action__PoseCommand_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
highlevel_interfaces__action__PoseCommand_Result__Sequence__init(highlevel_interfaces__action__PoseCommand_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_Result * data = NULL;

  if (size) {
    data = (highlevel_interfaces__action__PoseCommand_Result *)allocator.zero_allocate(size, sizeof(highlevel_interfaces__action__PoseCommand_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = highlevel_interfaces__action__PoseCommand_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        highlevel_interfaces__action__PoseCommand_Result__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
highlevel_interfaces__action__PoseCommand_Result__Sequence__fini(highlevel_interfaces__action__PoseCommand_Result__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      highlevel_interfaces__action__PoseCommand_Result__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

highlevel_interfaces__action__PoseCommand_Result__Sequence *
highlevel_interfaces__action__PoseCommand_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_Result__Sequence * array = (highlevel_interfaces__action__PoseCommand_Result__Sequence *)allocator.allocate(sizeof(highlevel_interfaces__action__PoseCommand_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = highlevel_interfaces__action__PoseCommand_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
highlevel_interfaces__action__PoseCommand_Result__Sequence__destroy(highlevel_interfaces__action__PoseCommand_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    highlevel_interfaces__action__PoseCommand_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
highlevel_interfaces__action__PoseCommand_Result__Sequence__are_equal(const highlevel_interfaces__action__PoseCommand_Result__Sequence * lhs, const highlevel_interfaces__action__PoseCommand_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!highlevel_interfaces__action__PoseCommand_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
highlevel_interfaces__action__PoseCommand_Result__Sequence__copy(
  const highlevel_interfaces__action__PoseCommand_Result__Sequence * input,
  highlevel_interfaces__action__PoseCommand_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(highlevel_interfaces__action__PoseCommand_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    highlevel_interfaces__action__PoseCommand_Result * data =
      (highlevel_interfaces__action__PoseCommand_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!highlevel_interfaces__action__PoseCommand_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          highlevel_interfaces__action__PoseCommand_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!highlevel_interfaces__action__PoseCommand_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
highlevel_interfaces__action__PoseCommand_Feedback__init(highlevel_interfaces__action__PoseCommand_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // distance_translation
  // distance_orientation
  // time_elapsed
  return true;
}

void
highlevel_interfaces__action__PoseCommand_Feedback__fini(highlevel_interfaces__action__PoseCommand_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // distance_translation
  // distance_orientation
  // time_elapsed
}

bool
highlevel_interfaces__action__PoseCommand_Feedback__are_equal(const highlevel_interfaces__action__PoseCommand_Feedback * lhs, const highlevel_interfaces__action__PoseCommand_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // distance_translation
  if (lhs->distance_translation != rhs->distance_translation) {
    return false;
  }
  // distance_orientation
  if (lhs->distance_orientation != rhs->distance_orientation) {
    return false;
  }
  // time_elapsed
  if (lhs->time_elapsed != rhs->time_elapsed) {
    return false;
  }
  return true;
}

bool
highlevel_interfaces__action__PoseCommand_Feedback__copy(
  const highlevel_interfaces__action__PoseCommand_Feedback * input,
  highlevel_interfaces__action__PoseCommand_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // distance_translation
  output->distance_translation = input->distance_translation;
  // distance_orientation
  output->distance_orientation = input->distance_orientation;
  // time_elapsed
  output->time_elapsed = input->time_elapsed;
  return true;
}

highlevel_interfaces__action__PoseCommand_Feedback *
highlevel_interfaces__action__PoseCommand_Feedback__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_Feedback * msg = (highlevel_interfaces__action__PoseCommand_Feedback *)allocator.allocate(sizeof(highlevel_interfaces__action__PoseCommand_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(highlevel_interfaces__action__PoseCommand_Feedback));
  bool success = highlevel_interfaces__action__PoseCommand_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
highlevel_interfaces__action__PoseCommand_Feedback__destroy(highlevel_interfaces__action__PoseCommand_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    highlevel_interfaces__action__PoseCommand_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
highlevel_interfaces__action__PoseCommand_Feedback__Sequence__init(highlevel_interfaces__action__PoseCommand_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_Feedback * data = NULL;

  if (size) {
    data = (highlevel_interfaces__action__PoseCommand_Feedback *)allocator.zero_allocate(size, sizeof(highlevel_interfaces__action__PoseCommand_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = highlevel_interfaces__action__PoseCommand_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        highlevel_interfaces__action__PoseCommand_Feedback__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
highlevel_interfaces__action__PoseCommand_Feedback__Sequence__fini(highlevel_interfaces__action__PoseCommand_Feedback__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      highlevel_interfaces__action__PoseCommand_Feedback__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

highlevel_interfaces__action__PoseCommand_Feedback__Sequence *
highlevel_interfaces__action__PoseCommand_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_Feedback__Sequence * array = (highlevel_interfaces__action__PoseCommand_Feedback__Sequence *)allocator.allocate(sizeof(highlevel_interfaces__action__PoseCommand_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = highlevel_interfaces__action__PoseCommand_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
highlevel_interfaces__action__PoseCommand_Feedback__Sequence__destroy(highlevel_interfaces__action__PoseCommand_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    highlevel_interfaces__action__PoseCommand_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
highlevel_interfaces__action__PoseCommand_Feedback__Sequence__are_equal(const highlevel_interfaces__action__PoseCommand_Feedback__Sequence * lhs, const highlevel_interfaces__action__PoseCommand_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!highlevel_interfaces__action__PoseCommand_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
highlevel_interfaces__action__PoseCommand_Feedback__Sequence__copy(
  const highlevel_interfaces__action__PoseCommand_Feedback__Sequence * input,
  highlevel_interfaces__action__PoseCommand_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(highlevel_interfaces__action__PoseCommand_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    highlevel_interfaces__action__PoseCommand_Feedback * data =
      (highlevel_interfaces__action__PoseCommand_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!highlevel_interfaces__action__PoseCommand_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          highlevel_interfaces__action__PoseCommand_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!highlevel_interfaces__action__PoseCommand_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "highlevel_interfaces/action/detail/pose_command__functions.h"

bool
highlevel_interfaces__action__PoseCommand_SendGoal_Request__init(highlevel_interfaces__action__PoseCommand_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    highlevel_interfaces__action__PoseCommand_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!highlevel_interfaces__action__PoseCommand_Goal__init(&msg->goal)) {
    highlevel_interfaces__action__PoseCommand_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
highlevel_interfaces__action__PoseCommand_SendGoal_Request__fini(highlevel_interfaces__action__PoseCommand_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  highlevel_interfaces__action__PoseCommand_Goal__fini(&msg->goal);
}

bool
highlevel_interfaces__action__PoseCommand_SendGoal_Request__are_equal(const highlevel_interfaces__action__PoseCommand_SendGoal_Request * lhs, const highlevel_interfaces__action__PoseCommand_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!highlevel_interfaces__action__PoseCommand_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
highlevel_interfaces__action__PoseCommand_SendGoal_Request__copy(
  const highlevel_interfaces__action__PoseCommand_SendGoal_Request * input,
  highlevel_interfaces__action__PoseCommand_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!highlevel_interfaces__action__PoseCommand_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

highlevel_interfaces__action__PoseCommand_SendGoal_Request *
highlevel_interfaces__action__PoseCommand_SendGoal_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_SendGoal_Request * msg = (highlevel_interfaces__action__PoseCommand_SendGoal_Request *)allocator.allocate(sizeof(highlevel_interfaces__action__PoseCommand_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(highlevel_interfaces__action__PoseCommand_SendGoal_Request));
  bool success = highlevel_interfaces__action__PoseCommand_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
highlevel_interfaces__action__PoseCommand_SendGoal_Request__destroy(highlevel_interfaces__action__PoseCommand_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    highlevel_interfaces__action__PoseCommand_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
highlevel_interfaces__action__PoseCommand_SendGoal_Request__Sequence__init(highlevel_interfaces__action__PoseCommand_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_SendGoal_Request * data = NULL;

  if (size) {
    data = (highlevel_interfaces__action__PoseCommand_SendGoal_Request *)allocator.zero_allocate(size, sizeof(highlevel_interfaces__action__PoseCommand_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = highlevel_interfaces__action__PoseCommand_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        highlevel_interfaces__action__PoseCommand_SendGoal_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
highlevel_interfaces__action__PoseCommand_SendGoal_Request__Sequence__fini(highlevel_interfaces__action__PoseCommand_SendGoal_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      highlevel_interfaces__action__PoseCommand_SendGoal_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

highlevel_interfaces__action__PoseCommand_SendGoal_Request__Sequence *
highlevel_interfaces__action__PoseCommand_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_SendGoal_Request__Sequence * array = (highlevel_interfaces__action__PoseCommand_SendGoal_Request__Sequence *)allocator.allocate(sizeof(highlevel_interfaces__action__PoseCommand_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = highlevel_interfaces__action__PoseCommand_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
highlevel_interfaces__action__PoseCommand_SendGoal_Request__Sequence__destroy(highlevel_interfaces__action__PoseCommand_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    highlevel_interfaces__action__PoseCommand_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
highlevel_interfaces__action__PoseCommand_SendGoal_Request__Sequence__are_equal(const highlevel_interfaces__action__PoseCommand_SendGoal_Request__Sequence * lhs, const highlevel_interfaces__action__PoseCommand_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!highlevel_interfaces__action__PoseCommand_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
highlevel_interfaces__action__PoseCommand_SendGoal_Request__Sequence__copy(
  const highlevel_interfaces__action__PoseCommand_SendGoal_Request__Sequence * input,
  highlevel_interfaces__action__PoseCommand_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(highlevel_interfaces__action__PoseCommand_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    highlevel_interfaces__action__PoseCommand_SendGoal_Request * data =
      (highlevel_interfaces__action__PoseCommand_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!highlevel_interfaces__action__PoseCommand_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          highlevel_interfaces__action__PoseCommand_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!highlevel_interfaces__action__PoseCommand_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
highlevel_interfaces__action__PoseCommand_SendGoal_Response__init(highlevel_interfaces__action__PoseCommand_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    highlevel_interfaces__action__PoseCommand_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
highlevel_interfaces__action__PoseCommand_SendGoal_Response__fini(highlevel_interfaces__action__PoseCommand_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
highlevel_interfaces__action__PoseCommand_SendGoal_Response__are_equal(const highlevel_interfaces__action__PoseCommand_SendGoal_Response * lhs, const highlevel_interfaces__action__PoseCommand_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
highlevel_interfaces__action__PoseCommand_SendGoal_Response__copy(
  const highlevel_interfaces__action__PoseCommand_SendGoal_Response * input,
  highlevel_interfaces__action__PoseCommand_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

highlevel_interfaces__action__PoseCommand_SendGoal_Response *
highlevel_interfaces__action__PoseCommand_SendGoal_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_SendGoal_Response * msg = (highlevel_interfaces__action__PoseCommand_SendGoal_Response *)allocator.allocate(sizeof(highlevel_interfaces__action__PoseCommand_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(highlevel_interfaces__action__PoseCommand_SendGoal_Response));
  bool success = highlevel_interfaces__action__PoseCommand_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
highlevel_interfaces__action__PoseCommand_SendGoal_Response__destroy(highlevel_interfaces__action__PoseCommand_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    highlevel_interfaces__action__PoseCommand_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
highlevel_interfaces__action__PoseCommand_SendGoal_Response__Sequence__init(highlevel_interfaces__action__PoseCommand_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_SendGoal_Response * data = NULL;

  if (size) {
    data = (highlevel_interfaces__action__PoseCommand_SendGoal_Response *)allocator.zero_allocate(size, sizeof(highlevel_interfaces__action__PoseCommand_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = highlevel_interfaces__action__PoseCommand_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        highlevel_interfaces__action__PoseCommand_SendGoal_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
highlevel_interfaces__action__PoseCommand_SendGoal_Response__Sequence__fini(highlevel_interfaces__action__PoseCommand_SendGoal_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      highlevel_interfaces__action__PoseCommand_SendGoal_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

highlevel_interfaces__action__PoseCommand_SendGoal_Response__Sequence *
highlevel_interfaces__action__PoseCommand_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_SendGoal_Response__Sequence * array = (highlevel_interfaces__action__PoseCommand_SendGoal_Response__Sequence *)allocator.allocate(sizeof(highlevel_interfaces__action__PoseCommand_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = highlevel_interfaces__action__PoseCommand_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
highlevel_interfaces__action__PoseCommand_SendGoal_Response__Sequence__destroy(highlevel_interfaces__action__PoseCommand_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    highlevel_interfaces__action__PoseCommand_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
highlevel_interfaces__action__PoseCommand_SendGoal_Response__Sequence__are_equal(const highlevel_interfaces__action__PoseCommand_SendGoal_Response__Sequence * lhs, const highlevel_interfaces__action__PoseCommand_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!highlevel_interfaces__action__PoseCommand_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
highlevel_interfaces__action__PoseCommand_SendGoal_Response__Sequence__copy(
  const highlevel_interfaces__action__PoseCommand_SendGoal_Response__Sequence * input,
  highlevel_interfaces__action__PoseCommand_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(highlevel_interfaces__action__PoseCommand_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    highlevel_interfaces__action__PoseCommand_SendGoal_Response * data =
      (highlevel_interfaces__action__PoseCommand_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!highlevel_interfaces__action__PoseCommand_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          highlevel_interfaces__action__PoseCommand_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!highlevel_interfaces__action__PoseCommand_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "highlevel_interfaces/action/detail/pose_command__functions.h"

bool
highlevel_interfaces__action__PoseCommand_SendGoal_Event__init(highlevel_interfaces__action__PoseCommand_SendGoal_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    highlevel_interfaces__action__PoseCommand_SendGoal_Event__fini(msg);
    return false;
  }
  // request
  if (!highlevel_interfaces__action__PoseCommand_SendGoal_Request__Sequence__init(&msg->request, 0)) {
    highlevel_interfaces__action__PoseCommand_SendGoal_Event__fini(msg);
    return false;
  }
  // response
  if (!highlevel_interfaces__action__PoseCommand_SendGoal_Response__Sequence__init(&msg->response, 0)) {
    highlevel_interfaces__action__PoseCommand_SendGoal_Event__fini(msg);
    return false;
  }
  return true;
}

void
highlevel_interfaces__action__PoseCommand_SendGoal_Event__fini(highlevel_interfaces__action__PoseCommand_SendGoal_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  highlevel_interfaces__action__PoseCommand_SendGoal_Request__Sequence__fini(&msg->request);
  // response
  highlevel_interfaces__action__PoseCommand_SendGoal_Response__Sequence__fini(&msg->response);
}

bool
highlevel_interfaces__action__PoseCommand_SendGoal_Event__are_equal(const highlevel_interfaces__action__PoseCommand_SendGoal_Event * lhs, const highlevel_interfaces__action__PoseCommand_SendGoal_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!highlevel_interfaces__action__PoseCommand_SendGoal_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!highlevel_interfaces__action__PoseCommand_SendGoal_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
highlevel_interfaces__action__PoseCommand_SendGoal_Event__copy(
  const highlevel_interfaces__action__PoseCommand_SendGoal_Event * input,
  highlevel_interfaces__action__PoseCommand_SendGoal_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!highlevel_interfaces__action__PoseCommand_SendGoal_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!highlevel_interfaces__action__PoseCommand_SendGoal_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

highlevel_interfaces__action__PoseCommand_SendGoal_Event *
highlevel_interfaces__action__PoseCommand_SendGoal_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_SendGoal_Event * msg = (highlevel_interfaces__action__PoseCommand_SendGoal_Event *)allocator.allocate(sizeof(highlevel_interfaces__action__PoseCommand_SendGoal_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(highlevel_interfaces__action__PoseCommand_SendGoal_Event));
  bool success = highlevel_interfaces__action__PoseCommand_SendGoal_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
highlevel_interfaces__action__PoseCommand_SendGoal_Event__destroy(highlevel_interfaces__action__PoseCommand_SendGoal_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    highlevel_interfaces__action__PoseCommand_SendGoal_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
highlevel_interfaces__action__PoseCommand_SendGoal_Event__Sequence__init(highlevel_interfaces__action__PoseCommand_SendGoal_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_SendGoal_Event * data = NULL;

  if (size) {
    data = (highlevel_interfaces__action__PoseCommand_SendGoal_Event *)allocator.zero_allocate(size, sizeof(highlevel_interfaces__action__PoseCommand_SendGoal_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = highlevel_interfaces__action__PoseCommand_SendGoal_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        highlevel_interfaces__action__PoseCommand_SendGoal_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
highlevel_interfaces__action__PoseCommand_SendGoal_Event__Sequence__fini(highlevel_interfaces__action__PoseCommand_SendGoal_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      highlevel_interfaces__action__PoseCommand_SendGoal_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

highlevel_interfaces__action__PoseCommand_SendGoal_Event__Sequence *
highlevel_interfaces__action__PoseCommand_SendGoal_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_SendGoal_Event__Sequence * array = (highlevel_interfaces__action__PoseCommand_SendGoal_Event__Sequence *)allocator.allocate(sizeof(highlevel_interfaces__action__PoseCommand_SendGoal_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = highlevel_interfaces__action__PoseCommand_SendGoal_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
highlevel_interfaces__action__PoseCommand_SendGoal_Event__Sequence__destroy(highlevel_interfaces__action__PoseCommand_SendGoal_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    highlevel_interfaces__action__PoseCommand_SendGoal_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
highlevel_interfaces__action__PoseCommand_SendGoal_Event__Sequence__are_equal(const highlevel_interfaces__action__PoseCommand_SendGoal_Event__Sequence * lhs, const highlevel_interfaces__action__PoseCommand_SendGoal_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!highlevel_interfaces__action__PoseCommand_SendGoal_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
highlevel_interfaces__action__PoseCommand_SendGoal_Event__Sequence__copy(
  const highlevel_interfaces__action__PoseCommand_SendGoal_Event__Sequence * input,
  highlevel_interfaces__action__PoseCommand_SendGoal_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(highlevel_interfaces__action__PoseCommand_SendGoal_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    highlevel_interfaces__action__PoseCommand_SendGoal_Event * data =
      (highlevel_interfaces__action__PoseCommand_SendGoal_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!highlevel_interfaces__action__PoseCommand_SendGoal_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          highlevel_interfaces__action__PoseCommand_SendGoal_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!highlevel_interfaces__action__PoseCommand_SendGoal_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
highlevel_interfaces__action__PoseCommand_GetResult_Request__init(highlevel_interfaces__action__PoseCommand_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    highlevel_interfaces__action__PoseCommand_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
highlevel_interfaces__action__PoseCommand_GetResult_Request__fini(highlevel_interfaces__action__PoseCommand_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
highlevel_interfaces__action__PoseCommand_GetResult_Request__are_equal(const highlevel_interfaces__action__PoseCommand_GetResult_Request * lhs, const highlevel_interfaces__action__PoseCommand_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
highlevel_interfaces__action__PoseCommand_GetResult_Request__copy(
  const highlevel_interfaces__action__PoseCommand_GetResult_Request * input,
  highlevel_interfaces__action__PoseCommand_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

highlevel_interfaces__action__PoseCommand_GetResult_Request *
highlevel_interfaces__action__PoseCommand_GetResult_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_GetResult_Request * msg = (highlevel_interfaces__action__PoseCommand_GetResult_Request *)allocator.allocate(sizeof(highlevel_interfaces__action__PoseCommand_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(highlevel_interfaces__action__PoseCommand_GetResult_Request));
  bool success = highlevel_interfaces__action__PoseCommand_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
highlevel_interfaces__action__PoseCommand_GetResult_Request__destroy(highlevel_interfaces__action__PoseCommand_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    highlevel_interfaces__action__PoseCommand_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
highlevel_interfaces__action__PoseCommand_GetResult_Request__Sequence__init(highlevel_interfaces__action__PoseCommand_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_GetResult_Request * data = NULL;

  if (size) {
    data = (highlevel_interfaces__action__PoseCommand_GetResult_Request *)allocator.zero_allocate(size, sizeof(highlevel_interfaces__action__PoseCommand_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = highlevel_interfaces__action__PoseCommand_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        highlevel_interfaces__action__PoseCommand_GetResult_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
highlevel_interfaces__action__PoseCommand_GetResult_Request__Sequence__fini(highlevel_interfaces__action__PoseCommand_GetResult_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      highlevel_interfaces__action__PoseCommand_GetResult_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

highlevel_interfaces__action__PoseCommand_GetResult_Request__Sequence *
highlevel_interfaces__action__PoseCommand_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_GetResult_Request__Sequence * array = (highlevel_interfaces__action__PoseCommand_GetResult_Request__Sequence *)allocator.allocate(sizeof(highlevel_interfaces__action__PoseCommand_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = highlevel_interfaces__action__PoseCommand_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
highlevel_interfaces__action__PoseCommand_GetResult_Request__Sequence__destroy(highlevel_interfaces__action__PoseCommand_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    highlevel_interfaces__action__PoseCommand_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
highlevel_interfaces__action__PoseCommand_GetResult_Request__Sequence__are_equal(const highlevel_interfaces__action__PoseCommand_GetResult_Request__Sequence * lhs, const highlevel_interfaces__action__PoseCommand_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!highlevel_interfaces__action__PoseCommand_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
highlevel_interfaces__action__PoseCommand_GetResult_Request__Sequence__copy(
  const highlevel_interfaces__action__PoseCommand_GetResult_Request__Sequence * input,
  highlevel_interfaces__action__PoseCommand_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(highlevel_interfaces__action__PoseCommand_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    highlevel_interfaces__action__PoseCommand_GetResult_Request * data =
      (highlevel_interfaces__action__PoseCommand_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!highlevel_interfaces__action__PoseCommand_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          highlevel_interfaces__action__PoseCommand_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!highlevel_interfaces__action__PoseCommand_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "highlevel_interfaces/action/detail/pose_command__functions.h"

bool
highlevel_interfaces__action__PoseCommand_GetResult_Response__init(highlevel_interfaces__action__PoseCommand_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!highlevel_interfaces__action__PoseCommand_Result__init(&msg->result)) {
    highlevel_interfaces__action__PoseCommand_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
highlevel_interfaces__action__PoseCommand_GetResult_Response__fini(highlevel_interfaces__action__PoseCommand_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  highlevel_interfaces__action__PoseCommand_Result__fini(&msg->result);
}

bool
highlevel_interfaces__action__PoseCommand_GetResult_Response__are_equal(const highlevel_interfaces__action__PoseCommand_GetResult_Response * lhs, const highlevel_interfaces__action__PoseCommand_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!highlevel_interfaces__action__PoseCommand_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
highlevel_interfaces__action__PoseCommand_GetResult_Response__copy(
  const highlevel_interfaces__action__PoseCommand_GetResult_Response * input,
  highlevel_interfaces__action__PoseCommand_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!highlevel_interfaces__action__PoseCommand_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

highlevel_interfaces__action__PoseCommand_GetResult_Response *
highlevel_interfaces__action__PoseCommand_GetResult_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_GetResult_Response * msg = (highlevel_interfaces__action__PoseCommand_GetResult_Response *)allocator.allocate(sizeof(highlevel_interfaces__action__PoseCommand_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(highlevel_interfaces__action__PoseCommand_GetResult_Response));
  bool success = highlevel_interfaces__action__PoseCommand_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
highlevel_interfaces__action__PoseCommand_GetResult_Response__destroy(highlevel_interfaces__action__PoseCommand_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    highlevel_interfaces__action__PoseCommand_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
highlevel_interfaces__action__PoseCommand_GetResult_Response__Sequence__init(highlevel_interfaces__action__PoseCommand_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_GetResult_Response * data = NULL;

  if (size) {
    data = (highlevel_interfaces__action__PoseCommand_GetResult_Response *)allocator.zero_allocate(size, sizeof(highlevel_interfaces__action__PoseCommand_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = highlevel_interfaces__action__PoseCommand_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        highlevel_interfaces__action__PoseCommand_GetResult_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
highlevel_interfaces__action__PoseCommand_GetResult_Response__Sequence__fini(highlevel_interfaces__action__PoseCommand_GetResult_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      highlevel_interfaces__action__PoseCommand_GetResult_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

highlevel_interfaces__action__PoseCommand_GetResult_Response__Sequence *
highlevel_interfaces__action__PoseCommand_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_GetResult_Response__Sequence * array = (highlevel_interfaces__action__PoseCommand_GetResult_Response__Sequence *)allocator.allocate(sizeof(highlevel_interfaces__action__PoseCommand_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = highlevel_interfaces__action__PoseCommand_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
highlevel_interfaces__action__PoseCommand_GetResult_Response__Sequence__destroy(highlevel_interfaces__action__PoseCommand_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    highlevel_interfaces__action__PoseCommand_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
highlevel_interfaces__action__PoseCommand_GetResult_Response__Sequence__are_equal(const highlevel_interfaces__action__PoseCommand_GetResult_Response__Sequence * lhs, const highlevel_interfaces__action__PoseCommand_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!highlevel_interfaces__action__PoseCommand_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
highlevel_interfaces__action__PoseCommand_GetResult_Response__Sequence__copy(
  const highlevel_interfaces__action__PoseCommand_GetResult_Response__Sequence * input,
  highlevel_interfaces__action__PoseCommand_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(highlevel_interfaces__action__PoseCommand_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    highlevel_interfaces__action__PoseCommand_GetResult_Response * data =
      (highlevel_interfaces__action__PoseCommand_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!highlevel_interfaces__action__PoseCommand_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          highlevel_interfaces__action__PoseCommand_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!highlevel_interfaces__action__PoseCommand_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
// already included above
// #include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "highlevel_interfaces/action/detail/pose_command__functions.h"

bool
highlevel_interfaces__action__PoseCommand_GetResult_Event__init(highlevel_interfaces__action__PoseCommand_GetResult_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    highlevel_interfaces__action__PoseCommand_GetResult_Event__fini(msg);
    return false;
  }
  // request
  if (!highlevel_interfaces__action__PoseCommand_GetResult_Request__Sequence__init(&msg->request, 0)) {
    highlevel_interfaces__action__PoseCommand_GetResult_Event__fini(msg);
    return false;
  }
  // response
  if (!highlevel_interfaces__action__PoseCommand_GetResult_Response__Sequence__init(&msg->response, 0)) {
    highlevel_interfaces__action__PoseCommand_GetResult_Event__fini(msg);
    return false;
  }
  return true;
}

void
highlevel_interfaces__action__PoseCommand_GetResult_Event__fini(highlevel_interfaces__action__PoseCommand_GetResult_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  highlevel_interfaces__action__PoseCommand_GetResult_Request__Sequence__fini(&msg->request);
  // response
  highlevel_interfaces__action__PoseCommand_GetResult_Response__Sequence__fini(&msg->response);
}

bool
highlevel_interfaces__action__PoseCommand_GetResult_Event__are_equal(const highlevel_interfaces__action__PoseCommand_GetResult_Event * lhs, const highlevel_interfaces__action__PoseCommand_GetResult_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!highlevel_interfaces__action__PoseCommand_GetResult_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!highlevel_interfaces__action__PoseCommand_GetResult_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
highlevel_interfaces__action__PoseCommand_GetResult_Event__copy(
  const highlevel_interfaces__action__PoseCommand_GetResult_Event * input,
  highlevel_interfaces__action__PoseCommand_GetResult_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!highlevel_interfaces__action__PoseCommand_GetResult_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!highlevel_interfaces__action__PoseCommand_GetResult_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

highlevel_interfaces__action__PoseCommand_GetResult_Event *
highlevel_interfaces__action__PoseCommand_GetResult_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_GetResult_Event * msg = (highlevel_interfaces__action__PoseCommand_GetResult_Event *)allocator.allocate(sizeof(highlevel_interfaces__action__PoseCommand_GetResult_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(highlevel_interfaces__action__PoseCommand_GetResult_Event));
  bool success = highlevel_interfaces__action__PoseCommand_GetResult_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
highlevel_interfaces__action__PoseCommand_GetResult_Event__destroy(highlevel_interfaces__action__PoseCommand_GetResult_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    highlevel_interfaces__action__PoseCommand_GetResult_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
highlevel_interfaces__action__PoseCommand_GetResult_Event__Sequence__init(highlevel_interfaces__action__PoseCommand_GetResult_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_GetResult_Event * data = NULL;

  if (size) {
    data = (highlevel_interfaces__action__PoseCommand_GetResult_Event *)allocator.zero_allocate(size, sizeof(highlevel_interfaces__action__PoseCommand_GetResult_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = highlevel_interfaces__action__PoseCommand_GetResult_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        highlevel_interfaces__action__PoseCommand_GetResult_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
highlevel_interfaces__action__PoseCommand_GetResult_Event__Sequence__fini(highlevel_interfaces__action__PoseCommand_GetResult_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      highlevel_interfaces__action__PoseCommand_GetResult_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

highlevel_interfaces__action__PoseCommand_GetResult_Event__Sequence *
highlevel_interfaces__action__PoseCommand_GetResult_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_GetResult_Event__Sequence * array = (highlevel_interfaces__action__PoseCommand_GetResult_Event__Sequence *)allocator.allocate(sizeof(highlevel_interfaces__action__PoseCommand_GetResult_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = highlevel_interfaces__action__PoseCommand_GetResult_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
highlevel_interfaces__action__PoseCommand_GetResult_Event__Sequence__destroy(highlevel_interfaces__action__PoseCommand_GetResult_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    highlevel_interfaces__action__PoseCommand_GetResult_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
highlevel_interfaces__action__PoseCommand_GetResult_Event__Sequence__are_equal(const highlevel_interfaces__action__PoseCommand_GetResult_Event__Sequence * lhs, const highlevel_interfaces__action__PoseCommand_GetResult_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!highlevel_interfaces__action__PoseCommand_GetResult_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
highlevel_interfaces__action__PoseCommand_GetResult_Event__Sequence__copy(
  const highlevel_interfaces__action__PoseCommand_GetResult_Event__Sequence * input,
  highlevel_interfaces__action__PoseCommand_GetResult_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(highlevel_interfaces__action__PoseCommand_GetResult_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    highlevel_interfaces__action__PoseCommand_GetResult_Event * data =
      (highlevel_interfaces__action__PoseCommand_GetResult_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!highlevel_interfaces__action__PoseCommand_GetResult_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          highlevel_interfaces__action__PoseCommand_GetResult_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!highlevel_interfaces__action__PoseCommand_GetResult_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "highlevel_interfaces/action/detail/pose_command__functions.h"

bool
highlevel_interfaces__action__PoseCommand_FeedbackMessage__init(highlevel_interfaces__action__PoseCommand_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    highlevel_interfaces__action__PoseCommand_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!highlevel_interfaces__action__PoseCommand_Feedback__init(&msg->feedback)) {
    highlevel_interfaces__action__PoseCommand_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
highlevel_interfaces__action__PoseCommand_FeedbackMessage__fini(highlevel_interfaces__action__PoseCommand_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  highlevel_interfaces__action__PoseCommand_Feedback__fini(&msg->feedback);
}

bool
highlevel_interfaces__action__PoseCommand_FeedbackMessage__are_equal(const highlevel_interfaces__action__PoseCommand_FeedbackMessage * lhs, const highlevel_interfaces__action__PoseCommand_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!highlevel_interfaces__action__PoseCommand_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
highlevel_interfaces__action__PoseCommand_FeedbackMessage__copy(
  const highlevel_interfaces__action__PoseCommand_FeedbackMessage * input,
  highlevel_interfaces__action__PoseCommand_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!highlevel_interfaces__action__PoseCommand_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

highlevel_interfaces__action__PoseCommand_FeedbackMessage *
highlevel_interfaces__action__PoseCommand_FeedbackMessage__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_FeedbackMessage * msg = (highlevel_interfaces__action__PoseCommand_FeedbackMessage *)allocator.allocate(sizeof(highlevel_interfaces__action__PoseCommand_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(highlevel_interfaces__action__PoseCommand_FeedbackMessage));
  bool success = highlevel_interfaces__action__PoseCommand_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
highlevel_interfaces__action__PoseCommand_FeedbackMessage__destroy(highlevel_interfaces__action__PoseCommand_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    highlevel_interfaces__action__PoseCommand_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
highlevel_interfaces__action__PoseCommand_FeedbackMessage__Sequence__init(highlevel_interfaces__action__PoseCommand_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_FeedbackMessage * data = NULL;

  if (size) {
    data = (highlevel_interfaces__action__PoseCommand_FeedbackMessage *)allocator.zero_allocate(size, sizeof(highlevel_interfaces__action__PoseCommand_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = highlevel_interfaces__action__PoseCommand_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        highlevel_interfaces__action__PoseCommand_FeedbackMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
highlevel_interfaces__action__PoseCommand_FeedbackMessage__Sequence__fini(highlevel_interfaces__action__PoseCommand_FeedbackMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      highlevel_interfaces__action__PoseCommand_FeedbackMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

highlevel_interfaces__action__PoseCommand_FeedbackMessage__Sequence *
highlevel_interfaces__action__PoseCommand_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__action__PoseCommand_FeedbackMessage__Sequence * array = (highlevel_interfaces__action__PoseCommand_FeedbackMessage__Sequence *)allocator.allocate(sizeof(highlevel_interfaces__action__PoseCommand_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = highlevel_interfaces__action__PoseCommand_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
highlevel_interfaces__action__PoseCommand_FeedbackMessage__Sequence__destroy(highlevel_interfaces__action__PoseCommand_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    highlevel_interfaces__action__PoseCommand_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
highlevel_interfaces__action__PoseCommand_FeedbackMessage__Sequence__are_equal(const highlevel_interfaces__action__PoseCommand_FeedbackMessage__Sequence * lhs, const highlevel_interfaces__action__PoseCommand_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!highlevel_interfaces__action__PoseCommand_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
highlevel_interfaces__action__PoseCommand_FeedbackMessage__Sequence__copy(
  const highlevel_interfaces__action__PoseCommand_FeedbackMessage__Sequence * input,
  highlevel_interfaces__action__PoseCommand_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(highlevel_interfaces__action__PoseCommand_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    highlevel_interfaces__action__PoseCommand_FeedbackMessage * data =
      (highlevel_interfaces__action__PoseCommand_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!highlevel_interfaces__action__PoseCommand_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          highlevel_interfaces__action__PoseCommand_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!highlevel_interfaces__action__PoseCommand_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
