// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from highlevel_interfaces:srv/Move2d.idl
// generated code does not contain a copyright notice

#include "highlevel_interfaces/srv/detail/move2d__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_highlevel_interfaces
const rosidl_type_hash_t *
highlevel_interfaces__srv__Move2d__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x0a, 0x74, 0xe0, 0x70, 0x84, 0x12, 0x11, 0xaf,
      0xd6, 0x3a, 0x10, 0x8f, 0xcd, 0x25, 0xdb, 0xb1,
      0x24, 0x1c, 0x4c, 0xfa, 0x5e, 0xcf, 0xb7, 0x7d,
      0x67, 0x86, 0x11, 0xfc, 0x71, 0xfd, 0x45, 0x48,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_highlevel_interfaces
const rosidl_type_hash_t *
highlevel_interfaces__srv__Move2d_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x00, 0xf5, 0x7e, 0x4e, 0x5d, 0x46, 0xc1, 0x22,
      0xf8, 0x29, 0x59, 0xb0, 0xe8, 0x87, 0xab, 0x3d,
      0x3f, 0xb4, 0xed, 0xf2, 0xb5, 0xf2, 0xc6, 0x51,
      0x60, 0xdc, 0x1f, 0x09, 0x9b, 0x05, 0x3d, 0xbc,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_highlevel_interfaces
const rosidl_type_hash_t *
highlevel_interfaces__srv__Move2d_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xe0, 0x11, 0xc6, 0x26, 0x5f, 0xb4, 0x18, 0x00,
      0x41, 0xe2, 0x8a, 0x71, 0xa4, 0xf2, 0x17, 0x6c,
      0xb7, 0x69, 0x89, 0xa2, 0xf8, 0xec, 0x6a, 0xa4,
      0xcd, 0xba, 0x0b, 0x7c, 0x6c, 0x2a, 0xc1, 0x67,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_highlevel_interfaces
const rosidl_type_hash_t *
highlevel_interfaces__srv__Move2d_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xe0, 0x7e, 0xcd, 0x7f, 0x63, 0x67, 0xf3, 0xba,
      0xf4, 0x6b, 0x66, 0x6b, 0x2b, 0x80, 0xc8, 0xcc,
      0x53, 0x10, 0x8f, 0x01, 0xb5, 0x03, 0x62, 0xaf,
      0x7b, 0xe3, 0xe8, 0x54, 0x93, 0x08, 0x4b, 0x68,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char highlevel_interfaces__srv__Move2d__TYPE_NAME[] = "highlevel_interfaces/srv/Move2d";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char highlevel_interfaces__srv__Move2d_Event__TYPE_NAME[] = "highlevel_interfaces/srv/Move2d_Event";
static char highlevel_interfaces__srv__Move2d_Request__TYPE_NAME[] = "highlevel_interfaces/srv/Move2d_Request";
static char highlevel_interfaces__srv__Move2d_Response__TYPE_NAME[] = "highlevel_interfaces/srv/Move2d_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char highlevel_interfaces__srv__Move2d__FIELD_NAME__request_message[] = "request_message";
static char highlevel_interfaces__srv__Move2d__FIELD_NAME__response_message[] = "response_message";
static char highlevel_interfaces__srv__Move2d__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field highlevel_interfaces__srv__Move2d__FIELDS[] = {
  {
    {highlevel_interfaces__srv__Move2d__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {highlevel_interfaces__srv__Move2d_Request__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
  {
    {highlevel_interfaces__srv__Move2d__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {highlevel_interfaces__srv__Move2d_Response__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {highlevel_interfaces__srv__Move2d__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {highlevel_interfaces__srv__Move2d_Event__TYPE_NAME, 37, 37},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription highlevel_interfaces__srv__Move2d__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {highlevel_interfaces__srv__Move2d_Event__TYPE_NAME, 37, 37},
    {NULL, 0, 0},
  },
  {
    {highlevel_interfaces__srv__Move2d_Request__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {highlevel_interfaces__srv__Move2d_Response__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
highlevel_interfaces__srv__Move2d__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {highlevel_interfaces__srv__Move2d__TYPE_NAME, 31, 31},
      {highlevel_interfaces__srv__Move2d__FIELDS, 3, 3},
    },
    {highlevel_interfaces__srv__Move2d__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = highlevel_interfaces__srv__Move2d_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = highlevel_interfaces__srv__Move2d_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = highlevel_interfaces__srv__Move2d_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char highlevel_interfaces__srv__Move2d_Request__FIELD_NAME__x[] = "x";
static char highlevel_interfaces__srv__Move2d_Request__FIELD_NAME__y[] = "y";

static rosidl_runtime_c__type_description__Field highlevel_interfaces__srv__Move2d_Request__FIELDS[] = {
  {
    {highlevel_interfaces__srv__Move2d_Request__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {highlevel_interfaces__srv__Move2d_Request__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
highlevel_interfaces__srv__Move2d_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {highlevel_interfaces__srv__Move2d_Request__TYPE_NAME, 39, 39},
      {highlevel_interfaces__srv__Move2d_Request__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char highlevel_interfaces__srv__Move2d_Response__FIELD_NAME__success[] = "success";

static rosidl_runtime_c__type_description__Field highlevel_interfaces__srv__Move2d_Response__FIELDS[] = {
  {
    {highlevel_interfaces__srv__Move2d_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
highlevel_interfaces__srv__Move2d_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {highlevel_interfaces__srv__Move2d_Response__TYPE_NAME, 40, 40},
      {highlevel_interfaces__srv__Move2d_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char highlevel_interfaces__srv__Move2d_Event__FIELD_NAME__info[] = "info";
static char highlevel_interfaces__srv__Move2d_Event__FIELD_NAME__request[] = "request";
static char highlevel_interfaces__srv__Move2d_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field highlevel_interfaces__srv__Move2d_Event__FIELDS[] = {
  {
    {highlevel_interfaces__srv__Move2d_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {highlevel_interfaces__srv__Move2d_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {highlevel_interfaces__srv__Move2d_Request__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
  {
    {highlevel_interfaces__srv__Move2d_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {highlevel_interfaces__srv__Move2d_Response__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription highlevel_interfaces__srv__Move2d_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {highlevel_interfaces__srv__Move2d_Request__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {highlevel_interfaces__srv__Move2d_Response__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
highlevel_interfaces__srv__Move2d_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {highlevel_interfaces__srv__Move2d_Event__TYPE_NAME, 37, 37},
      {highlevel_interfaces__srv__Move2d_Event__FIELDS, 3, 3},
    },
    {highlevel_interfaces__srv__Move2d_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = highlevel_interfaces__srv__Move2d_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = highlevel_interfaces__srv__Move2d_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 x\n"
  "float64 y\n"
  "---\n"
  "bool success";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
highlevel_interfaces__srv__Move2d__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {highlevel_interfaces__srv__Move2d__TYPE_NAME, 31, 31},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 36, 36},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
highlevel_interfaces__srv__Move2d_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {highlevel_interfaces__srv__Move2d_Request__TYPE_NAME, 39, 39},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
highlevel_interfaces__srv__Move2d_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {highlevel_interfaces__srv__Move2d_Response__TYPE_NAME, 40, 40},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
highlevel_interfaces__srv__Move2d_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {highlevel_interfaces__srv__Move2d_Event__TYPE_NAME, 37, 37},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
highlevel_interfaces__srv__Move2d__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *highlevel_interfaces__srv__Move2d__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *highlevel_interfaces__srv__Move2d_Event__get_individual_type_description_source(NULL);
    sources[3] = *highlevel_interfaces__srv__Move2d_Request__get_individual_type_description_source(NULL);
    sources[4] = *highlevel_interfaces__srv__Move2d_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
highlevel_interfaces__srv__Move2d_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *highlevel_interfaces__srv__Move2d_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
highlevel_interfaces__srv__Move2d_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *highlevel_interfaces__srv__Move2d_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
highlevel_interfaces__srv__Move2d_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *highlevel_interfaces__srv__Move2d_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *highlevel_interfaces__srv__Move2d_Request__get_individual_type_description_source(NULL);
    sources[3] = *highlevel_interfaces__srv__Move2d_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
