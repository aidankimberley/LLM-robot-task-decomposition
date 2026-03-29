// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from highlevel_interfaces:srv/SetKD.idl
// generated code does not contain a copyright notice

#include "highlevel_interfaces/srv/detail/set_kd__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_highlevel_interfaces
const rosidl_type_hash_t *
highlevel_interfaces__srv__SetKD__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x32, 0x8c, 0x7f, 0x9f, 0x05, 0xb5, 0x71, 0x79,
      0xe2, 0xce, 0x1d, 0xa7, 0xf2, 0x21, 0x20, 0x54,
      0xaf, 0x1c, 0x38, 0x35, 0x4d, 0xc2, 0x1f, 0x2a,
      0x03, 0x45, 0x25, 0xf1, 0x53, 0x99, 0x3a, 0xee,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_highlevel_interfaces
const rosidl_type_hash_t *
highlevel_interfaces__srv__SetKD_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc9, 0x73, 0x09, 0xd3, 0x16, 0x3d, 0xa6, 0x95,
      0x58, 0x23, 0x3d, 0x10, 0x42, 0x22, 0xa3, 0x72,
      0x9e, 0x2e, 0x0d, 0xe3, 0xdd, 0x87, 0x92, 0x34,
      0x81, 0xb7, 0x8e, 0x65, 0xb2, 0x5b, 0x87, 0xbf,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_highlevel_interfaces
const rosidl_type_hash_t *
highlevel_interfaces__srv__SetKD_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x40, 0xa3, 0x93, 0x40, 0x7c, 0xcc, 0x71, 0x7b,
      0x90, 0x4d, 0x3e, 0xb3, 0x9b, 0x1a, 0xb5, 0xa6,
      0x1f, 0xdf, 0x76, 0xb9, 0x08, 0x75, 0xdd, 0x76,
      0x76, 0x91, 0x6d, 0xbd, 0x89, 0x79, 0xfa, 0x79,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_highlevel_interfaces
const rosidl_type_hash_t *
highlevel_interfaces__srv__SetKD_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x51, 0x8e, 0x9a, 0x34, 0x10, 0xc4, 0xd0, 0x11,
      0x0e, 0x52, 0xb9, 0xc5, 0x8c, 0xf4, 0x3b, 0x8e,
      0x49, 0x24, 0x3d, 0x1a, 0x5d, 0x79, 0xa1, 0x77,
      0x06, 0x81, 0x61, 0x4c, 0x58, 0x91, 0xbd, 0x73,
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

static char highlevel_interfaces__srv__SetKD__TYPE_NAME[] = "highlevel_interfaces/srv/SetKD";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char highlevel_interfaces__srv__SetKD_Event__TYPE_NAME[] = "highlevel_interfaces/srv/SetKD_Event";
static char highlevel_interfaces__srv__SetKD_Request__TYPE_NAME[] = "highlevel_interfaces/srv/SetKD_Request";
static char highlevel_interfaces__srv__SetKD_Response__TYPE_NAME[] = "highlevel_interfaces/srv/SetKD_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char highlevel_interfaces__srv__SetKD__FIELD_NAME__request_message[] = "request_message";
static char highlevel_interfaces__srv__SetKD__FIELD_NAME__response_message[] = "response_message";
static char highlevel_interfaces__srv__SetKD__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field highlevel_interfaces__srv__SetKD__FIELDS[] = {
  {
    {highlevel_interfaces__srv__SetKD__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {highlevel_interfaces__srv__SetKD_Request__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
  {
    {highlevel_interfaces__srv__SetKD__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {highlevel_interfaces__srv__SetKD_Response__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
  {
    {highlevel_interfaces__srv__SetKD__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {highlevel_interfaces__srv__SetKD_Event__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription highlevel_interfaces__srv__SetKD__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {highlevel_interfaces__srv__SetKD_Event__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {highlevel_interfaces__srv__SetKD_Request__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {highlevel_interfaces__srv__SetKD_Response__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
highlevel_interfaces__srv__SetKD__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {highlevel_interfaces__srv__SetKD__TYPE_NAME, 30, 30},
      {highlevel_interfaces__srv__SetKD__FIELDS, 3, 3},
    },
    {highlevel_interfaces__srv__SetKD__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = highlevel_interfaces__srv__SetKD_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = highlevel_interfaces__srv__SetKD_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = highlevel_interfaces__srv__SetKD_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char highlevel_interfaces__srv__SetKD_Request__FIELD_NAME__k[] = "k";
static char highlevel_interfaces__srv__SetKD_Request__FIELD_NAME__d[] = "d";

static rosidl_runtime_c__type_description__Field highlevel_interfaces__srv__SetKD_Request__FIELDS[] = {
  {
    {highlevel_interfaces__srv__SetKD_Request__FIELD_NAME__k, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {highlevel_interfaces__srv__SetKD_Request__FIELD_NAME__d, 1, 1},
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
highlevel_interfaces__srv__SetKD_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {highlevel_interfaces__srv__SetKD_Request__TYPE_NAME, 38, 38},
      {highlevel_interfaces__srv__SetKD_Request__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char highlevel_interfaces__srv__SetKD_Response__FIELD_NAME__success[] = "success";

static rosidl_runtime_c__type_description__Field highlevel_interfaces__srv__SetKD_Response__FIELDS[] = {
  {
    {highlevel_interfaces__srv__SetKD_Response__FIELD_NAME__success, 7, 7},
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
highlevel_interfaces__srv__SetKD_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {highlevel_interfaces__srv__SetKD_Response__TYPE_NAME, 39, 39},
      {highlevel_interfaces__srv__SetKD_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char highlevel_interfaces__srv__SetKD_Event__FIELD_NAME__info[] = "info";
static char highlevel_interfaces__srv__SetKD_Event__FIELD_NAME__request[] = "request";
static char highlevel_interfaces__srv__SetKD_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field highlevel_interfaces__srv__SetKD_Event__FIELDS[] = {
  {
    {highlevel_interfaces__srv__SetKD_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {highlevel_interfaces__srv__SetKD_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {highlevel_interfaces__srv__SetKD_Request__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
  {
    {highlevel_interfaces__srv__SetKD_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {highlevel_interfaces__srv__SetKD_Response__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription highlevel_interfaces__srv__SetKD_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {highlevel_interfaces__srv__SetKD_Request__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {highlevel_interfaces__srv__SetKD_Response__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
highlevel_interfaces__srv__SetKD_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {highlevel_interfaces__srv__SetKD_Event__TYPE_NAME, 36, 36},
      {highlevel_interfaces__srv__SetKD_Event__FIELDS, 3, 3},
    },
    {highlevel_interfaces__srv__SetKD_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = highlevel_interfaces__srv__SetKD_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = highlevel_interfaces__srv__SetKD_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 k\n"
  "float64 d\n"
  "---\n"
  "bool success";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
highlevel_interfaces__srv__SetKD__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {highlevel_interfaces__srv__SetKD__TYPE_NAME, 30, 30},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 37, 37},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
highlevel_interfaces__srv__SetKD_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {highlevel_interfaces__srv__SetKD_Request__TYPE_NAME, 38, 38},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
highlevel_interfaces__srv__SetKD_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {highlevel_interfaces__srv__SetKD_Response__TYPE_NAME, 39, 39},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
highlevel_interfaces__srv__SetKD_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {highlevel_interfaces__srv__SetKD_Event__TYPE_NAME, 36, 36},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
highlevel_interfaces__srv__SetKD__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *highlevel_interfaces__srv__SetKD__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *highlevel_interfaces__srv__SetKD_Event__get_individual_type_description_source(NULL);
    sources[3] = *highlevel_interfaces__srv__SetKD_Request__get_individual_type_description_source(NULL);
    sources[4] = *highlevel_interfaces__srv__SetKD_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
highlevel_interfaces__srv__SetKD_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *highlevel_interfaces__srv__SetKD_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
highlevel_interfaces__srv__SetKD_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *highlevel_interfaces__srv__SetKD_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
highlevel_interfaces__srv__SetKD_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *highlevel_interfaces__srv__SetKD_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *highlevel_interfaces__srv__SetKD_Request__get_individual_type_description_source(NULL);
    sources[3] = *highlevel_interfaces__srv__SetKD_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
