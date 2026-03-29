// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from highlevel_interfaces:srv/SetKD.idl
// generated code does not contain a copyright notice
#include "highlevel_interfaces/srv/detail/set_kd__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
highlevel_interfaces__srv__SetKD_Request__init(highlevel_interfaces__srv__SetKD_Request * msg)
{
  if (!msg) {
    return false;
  }
  // k
  // d
  return true;
}

void
highlevel_interfaces__srv__SetKD_Request__fini(highlevel_interfaces__srv__SetKD_Request * msg)
{
  if (!msg) {
    return;
  }
  // k
  // d
}

bool
highlevel_interfaces__srv__SetKD_Request__are_equal(const highlevel_interfaces__srv__SetKD_Request * lhs, const highlevel_interfaces__srv__SetKD_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // k
  if (lhs->k != rhs->k) {
    return false;
  }
  // d
  if (lhs->d != rhs->d) {
    return false;
  }
  return true;
}

bool
highlevel_interfaces__srv__SetKD_Request__copy(
  const highlevel_interfaces__srv__SetKD_Request * input,
  highlevel_interfaces__srv__SetKD_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // k
  output->k = input->k;
  // d
  output->d = input->d;
  return true;
}

highlevel_interfaces__srv__SetKD_Request *
highlevel_interfaces__srv__SetKD_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__srv__SetKD_Request * msg = (highlevel_interfaces__srv__SetKD_Request *)allocator.allocate(sizeof(highlevel_interfaces__srv__SetKD_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(highlevel_interfaces__srv__SetKD_Request));
  bool success = highlevel_interfaces__srv__SetKD_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
highlevel_interfaces__srv__SetKD_Request__destroy(highlevel_interfaces__srv__SetKD_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    highlevel_interfaces__srv__SetKD_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
highlevel_interfaces__srv__SetKD_Request__Sequence__init(highlevel_interfaces__srv__SetKD_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__srv__SetKD_Request * data = NULL;

  if (size) {
    data = (highlevel_interfaces__srv__SetKD_Request *)allocator.zero_allocate(size, sizeof(highlevel_interfaces__srv__SetKD_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = highlevel_interfaces__srv__SetKD_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        highlevel_interfaces__srv__SetKD_Request__fini(&data[i - 1]);
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
highlevel_interfaces__srv__SetKD_Request__Sequence__fini(highlevel_interfaces__srv__SetKD_Request__Sequence * array)
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
      highlevel_interfaces__srv__SetKD_Request__fini(&array->data[i]);
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

highlevel_interfaces__srv__SetKD_Request__Sequence *
highlevel_interfaces__srv__SetKD_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__srv__SetKD_Request__Sequence * array = (highlevel_interfaces__srv__SetKD_Request__Sequence *)allocator.allocate(sizeof(highlevel_interfaces__srv__SetKD_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = highlevel_interfaces__srv__SetKD_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
highlevel_interfaces__srv__SetKD_Request__Sequence__destroy(highlevel_interfaces__srv__SetKD_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    highlevel_interfaces__srv__SetKD_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
highlevel_interfaces__srv__SetKD_Request__Sequence__are_equal(const highlevel_interfaces__srv__SetKD_Request__Sequence * lhs, const highlevel_interfaces__srv__SetKD_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!highlevel_interfaces__srv__SetKD_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
highlevel_interfaces__srv__SetKD_Request__Sequence__copy(
  const highlevel_interfaces__srv__SetKD_Request__Sequence * input,
  highlevel_interfaces__srv__SetKD_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(highlevel_interfaces__srv__SetKD_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    highlevel_interfaces__srv__SetKD_Request * data =
      (highlevel_interfaces__srv__SetKD_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!highlevel_interfaces__srv__SetKD_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          highlevel_interfaces__srv__SetKD_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!highlevel_interfaces__srv__SetKD_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
highlevel_interfaces__srv__SetKD_Response__init(highlevel_interfaces__srv__SetKD_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
highlevel_interfaces__srv__SetKD_Response__fini(highlevel_interfaces__srv__SetKD_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
highlevel_interfaces__srv__SetKD_Response__are_equal(const highlevel_interfaces__srv__SetKD_Response * lhs, const highlevel_interfaces__srv__SetKD_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
highlevel_interfaces__srv__SetKD_Response__copy(
  const highlevel_interfaces__srv__SetKD_Response * input,
  highlevel_interfaces__srv__SetKD_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

highlevel_interfaces__srv__SetKD_Response *
highlevel_interfaces__srv__SetKD_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__srv__SetKD_Response * msg = (highlevel_interfaces__srv__SetKD_Response *)allocator.allocate(sizeof(highlevel_interfaces__srv__SetKD_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(highlevel_interfaces__srv__SetKD_Response));
  bool success = highlevel_interfaces__srv__SetKD_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
highlevel_interfaces__srv__SetKD_Response__destroy(highlevel_interfaces__srv__SetKD_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    highlevel_interfaces__srv__SetKD_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
highlevel_interfaces__srv__SetKD_Response__Sequence__init(highlevel_interfaces__srv__SetKD_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__srv__SetKD_Response * data = NULL;

  if (size) {
    data = (highlevel_interfaces__srv__SetKD_Response *)allocator.zero_allocate(size, sizeof(highlevel_interfaces__srv__SetKD_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = highlevel_interfaces__srv__SetKD_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        highlevel_interfaces__srv__SetKD_Response__fini(&data[i - 1]);
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
highlevel_interfaces__srv__SetKD_Response__Sequence__fini(highlevel_interfaces__srv__SetKD_Response__Sequence * array)
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
      highlevel_interfaces__srv__SetKD_Response__fini(&array->data[i]);
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

highlevel_interfaces__srv__SetKD_Response__Sequence *
highlevel_interfaces__srv__SetKD_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__srv__SetKD_Response__Sequence * array = (highlevel_interfaces__srv__SetKD_Response__Sequence *)allocator.allocate(sizeof(highlevel_interfaces__srv__SetKD_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = highlevel_interfaces__srv__SetKD_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
highlevel_interfaces__srv__SetKD_Response__Sequence__destroy(highlevel_interfaces__srv__SetKD_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    highlevel_interfaces__srv__SetKD_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
highlevel_interfaces__srv__SetKD_Response__Sequence__are_equal(const highlevel_interfaces__srv__SetKD_Response__Sequence * lhs, const highlevel_interfaces__srv__SetKD_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!highlevel_interfaces__srv__SetKD_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
highlevel_interfaces__srv__SetKD_Response__Sequence__copy(
  const highlevel_interfaces__srv__SetKD_Response__Sequence * input,
  highlevel_interfaces__srv__SetKD_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(highlevel_interfaces__srv__SetKD_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    highlevel_interfaces__srv__SetKD_Response * data =
      (highlevel_interfaces__srv__SetKD_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!highlevel_interfaces__srv__SetKD_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          highlevel_interfaces__srv__SetKD_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!highlevel_interfaces__srv__SetKD_Response__copy(
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
// #include "highlevel_interfaces/srv/detail/set_kd__functions.h"

bool
highlevel_interfaces__srv__SetKD_Event__init(highlevel_interfaces__srv__SetKD_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    highlevel_interfaces__srv__SetKD_Event__fini(msg);
    return false;
  }
  // request
  if (!highlevel_interfaces__srv__SetKD_Request__Sequence__init(&msg->request, 0)) {
    highlevel_interfaces__srv__SetKD_Event__fini(msg);
    return false;
  }
  // response
  if (!highlevel_interfaces__srv__SetKD_Response__Sequence__init(&msg->response, 0)) {
    highlevel_interfaces__srv__SetKD_Event__fini(msg);
    return false;
  }
  return true;
}

void
highlevel_interfaces__srv__SetKD_Event__fini(highlevel_interfaces__srv__SetKD_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  highlevel_interfaces__srv__SetKD_Request__Sequence__fini(&msg->request);
  // response
  highlevel_interfaces__srv__SetKD_Response__Sequence__fini(&msg->response);
}

bool
highlevel_interfaces__srv__SetKD_Event__are_equal(const highlevel_interfaces__srv__SetKD_Event * lhs, const highlevel_interfaces__srv__SetKD_Event * rhs)
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
  if (!highlevel_interfaces__srv__SetKD_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!highlevel_interfaces__srv__SetKD_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
highlevel_interfaces__srv__SetKD_Event__copy(
  const highlevel_interfaces__srv__SetKD_Event * input,
  highlevel_interfaces__srv__SetKD_Event * output)
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
  if (!highlevel_interfaces__srv__SetKD_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!highlevel_interfaces__srv__SetKD_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

highlevel_interfaces__srv__SetKD_Event *
highlevel_interfaces__srv__SetKD_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__srv__SetKD_Event * msg = (highlevel_interfaces__srv__SetKD_Event *)allocator.allocate(sizeof(highlevel_interfaces__srv__SetKD_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(highlevel_interfaces__srv__SetKD_Event));
  bool success = highlevel_interfaces__srv__SetKD_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
highlevel_interfaces__srv__SetKD_Event__destroy(highlevel_interfaces__srv__SetKD_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    highlevel_interfaces__srv__SetKD_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
highlevel_interfaces__srv__SetKD_Event__Sequence__init(highlevel_interfaces__srv__SetKD_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__srv__SetKD_Event * data = NULL;

  if (size) {
    data = (highlevel_interfaces__srv__SetKD_Event *)allocator.zero_allocate(size, sizeof(highlevel_interfaces__srv__SetKD_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = highlevel_interfaces__srv__SetKD_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        highlevel_interfaces__srv__SetKD_Event__fini(&data[i - 1]);
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
highlevel_interfaces__srv__SetKD_Event__Sequence__fini(highlevel_interfaces__srv__SetKD_Event__Sequence * array)
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
      highlevel_interfaces__srv__SetKD_Event__fini(&array->data[i]);
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

highlevel_interfaces__srv__SetKD_Event__Sequence *
highlevel_interfaces__srv__SetKD_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  highlevel_interfaces__srv__SetKD_Event__Sequence * array = (highlevel_interfaces__srv__SetKD_Event__Sequence *)allocator.allocate(sizeof(highlevel_interfaces__srv__SetKD_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = highlevel_interfaces__srv__SetKD_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
highlevel_interfaces__srv__SetKD_Event__Sequence__destroy(highlevel_interfaces__srv__SetKD_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    highlevel_interfaces__srv__SetKD_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
highlevel_interfaces__srv__SetKD_Event__Sequence__are_equal(const highlevel_interfaces__srv__SetKD_Event__Sequence * lhs, const highlevel_interfaces__srv__SetKD_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!highlevel_interfaces__srv__SetKD_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
highlevel_interfaces__srv__SetKD_Event__Sequence__copy(
  const highlevel_interfaces__srv__SetKD_Event__Sequence * input,
  highlevel_interfaces__srv__SetKD_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(highlevel_interfaces__srv__SetKD_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    highlevel_interfaces__srv__SetKD_Event * data =
      (highlevel_interfaces__srv__SetKD_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!highlevel_interfaces__srv__SetKD_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          highlevel_interfaces__srv__SetKD_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!highlevel_interfaces__srv__SetKD_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
