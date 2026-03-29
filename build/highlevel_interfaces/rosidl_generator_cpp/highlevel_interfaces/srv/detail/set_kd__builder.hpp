// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from highlevel_interfaces:srv/SetKD.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "highlevel_interfaces/srv/set_kd.hpp"


#ifndef HIGHLEVEL_INTERFACES__SRV__DETAIL__SET_KD__BUILDER_HPP_
#define HIGHLEVEL_INTERFACES__SRV__DETAIL__SET_KD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "highlevel_interfaces/srv/detail/set_kd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace highlevel_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetKD_Request_d
{
public:
  explicit Init_SetKD_Request_d(::highlevel_interfaces::srv::SetKD_Request & msg)
  : msg_(msg)
  {}
  ::highlevel_interfaces::srv::SetKD_Request d(::highlevel_interfaces::srv::SetKD_Request::_d_type arg)
  {
    msg_.d = std::move(arg);
    return std::move(msg_);
  }

private:
  ::highlevel_interfaces::srv::SetKD_Request msg_;
};

class Init_SetKD_Request_k
{
public:
  Init_SetKD_Request_k()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetKD_Request_d k(::highlevel_interfaces::srv::SetKD_Request::_k_type arg)
  {
    msg_.k = std::move(arg);
    return Init_SetKD_Request_d(msg_);
  }

private:
  ::highlevel_interfaces::srv::SetKD_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::highlevel_interfaces::srv::SetKD_Request>()
{
  return highlevel_interfaces::srv::builder::Init_SetKD_Request_k();
}

}  // namespace highlevel_interfaces


namespace highlevel_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetKD_Response_success
{
public:
  Init_SetKD_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::highlevel_interfaces::srv::SetKD_Response success(::highlevel_interfaces::srv::SetKD_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::highlevel_interfaces::srv::SetKD_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::highlevel_interfaces::srv::SetKD_Response>()
{
  return highlevel_interfaces::srv::builder::Init_SetKD_Response_success();
}

}  // namespace highlevel_interfaces


namespace highlevel_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetKD_Event_response
{
public:
  explicit Init_SetKD_Event_response(::highlevel_interfaces::srv::SetKD_Event & msg)
  : msg_(msg)
  {}
  ::highlevel_interfaces::srv::SetKD_Event response(::highlevel_interfaces::srv::SetKD_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::highlevel_interfaces::srv::SetKD_Event msg_;
};

class Init_SetKD_Event_request
{
public:
  explicit Init_SetKD_Event_request(::highlevel_interfaces::srv::SetKD_Event & msg)
  : msg_(msg)
  {}
  Init_SetKD_Event_response request(::highlevel_interfaces::srv::SetKD_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SetKD_Event_response(msg_);
  }

private:
  ::highlevel_interfaces::srv::SetKD_Event msg_;
};

class Init_SetKD_Event_info
{
public:
  Init_SetKD_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetKD_Event_request info(::highlevel_interfaces::srv::SetKD_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SetKD_Event_request(msg_);
  }

private:
  ::highlevel_interfaces::srv::SetKD_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::highlevel_interfaces::srv::SetKD_Event>()
{
  return highlevel_interfaces::srv::builder::Init_SetKD_Event_info();
}

}  // namespace highlevel_interfaces

#endif  // HIGHLEVEL_INTERFACES__SRV__DETAIL__SET_KD__BUILDER_HPP_
