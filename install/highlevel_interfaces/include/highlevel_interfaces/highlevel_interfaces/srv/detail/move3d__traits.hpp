// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from highlevel_interfaces:srv/Move3d.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "highlevel_interfaces/srv/move3d.hpp"


#ifndef HIGHLEVEL_INTERFACES__SRV__DETAIL__MOVE3D__TRAITS_HPP_
#define HIGHLEVEL_INTERFACES__SRV__DETAIL__MOVE3D__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "highlevel_interfaces/srv/detail/move3d__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace highlevel_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Move3d_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Move3d_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Move3d_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace highlevel_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use highlevel_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const highlevel_interfaces::srv::Move3d_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  highlevel_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use highlevel_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const highlevel_interfaces::srv::Move3d_Request & msg)
{
  return highlevel_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<highlevel_interfaces::srv::Move3d_Request>()
{
  return "highlevel_interfaces::srv::Move3d_Request";
}

template<>
inline const char * name<highlevel_interfaces::srv::Move3d_Request>()
{
  return "highlevel_interfaces/srv/Move3d_Request";
}

template<>
struct has_fixed_size<highlevel_interfaces::srv::Move3d_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<highlevel_interfaces::srv::Move3d_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<highlevel_interfaces::srv::Move3d_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace highlevel_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Move3d_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Move3d_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Move3d_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace highlevel_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use highlevel_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const highlevel_interfaces::srv::Move3d_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  highlevel_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use highlevel_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const highlevel_interfaces::srv::Move3d_Response & msg)
{
  return highlevel_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<highlevel_interfaces::srv::Move3d_Response>()
{
  return "highlevel_interfaces::srv::Move3d_Response";
}

template<>
inline const char * name<highlevel_interfaces::srv::Move3d_Response>()
{
  return "highlevel_interfaces/srv/Move3d_Response";
}

template<>
struct has_fixed_size<highlevel_interfaces::srv::Move3d_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<highlevel_interfaces::srv::Move3d_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<highlevel_interfaces::srv::Move3d_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace highlevel_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Move3d_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Move3d_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Move3d_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace highlevel_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use highlevel_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const highlevel_interfaces::srv::Move3d_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  highlevel_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use highlevel_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const highlevel_interfaces::srv::Move3d_Event & msg)
{
  return highlevel_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<highlevel_interfaces::srv::Move3d_Event>()
{
  return "highlevel_interfaces::srv::Move3d_Event";
}

template<>
inline const char * name<highlevel_interfaces::srv::Move3d_Event>()
{
  return "highlevel_interfaces/srv/Move3d_Event";
}

template<>
struct has_fixed_size<highlevel_interfaces::srv::Move3d_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<highlevel_interfaces::srv::Move3d_Event>
  : std::integral_constant<bool, has_bounded_size<highlevel_interfaces::srv::Move3d_Request>::value && has_bounded_size<highlevel_interfaces::srv::Move3d_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<highlevel_interfaces::srv::Move3d_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<highlevel_interfaces::srv::Move3d>()
{
  return "highlevel_interfaces::srv::Move3d";
}

template<>
inline const char * name<highlevel_interfaces::srv::Move3d>()
{
  return "highlevel_interfaces/srv/Move3d";
}

template<>
struct has_fixed_size<highlevel_interfaces::srv::Move3d>
  : std::integral_constant<
    bool,
    has_fixed_size<highlevel_interfaces::srv::Move3d_Request>::value &&
    has_fixed_size<highlevel_interfaces::srv::Move3d_Response>::value
  >
{
};

template<>
struct has_bounded_size<highlevel_interfaces::srv::Move3d>
  : std::integral_constant<
    bool,
    has_bounded_size<highlevel_interfaces::srv::Move3d_Request>::value &&
    has_bounded_size<highlevel_interfaces::srv::Move3d_Response>::value
  >
{
};

template<>
struct is_service<highlevel_interfaces::srv::Move3d>
  : std::true_type
{
};

template<>
struct is_service_request<highlevel_interfaces::srv::Move3d_Request>
  : std::true_type
{
};

template<>
struct is_service_response<highlevel_interfaces::srv::Move3d_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // HIGHLEVEL_INTERFACES__SRV__DETAIL__MOVE3D__TRAITS_HPP_
