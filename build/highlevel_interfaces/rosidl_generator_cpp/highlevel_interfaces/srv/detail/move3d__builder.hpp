// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from highlevel_interfaces:srv/Move3d.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "highlevel_interfaces/srv/move3d.hpp"


#ifndef HIGHLEVEL_INTERFACES__SRV__DETAIL__MOVE3D__BUILDER_HPP_
#define HIGHLEVEL_INTERFACES__SRV__DETAIL__MOVE3D__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "highlevel_interfaces/srv/detail/move3d__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace highlevel_interfaces
{

namespace srv
{

namespace builder
{

class Init_Move3d_Request_z
{
public:
  explicit Init_Move3d_Request_z(::highlevel_interfaces::srv::Move3d_Request & msg)
  : msg_(msg)
  {}
  ::highlevel_interfaces::srv::Move3d_Request z(::highlevel_interfaces::srv::Move3d_Request::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::highlevel_interfaces::srv::Move3d_Request msg_;
};

class Init_Move3d_Request_y
{
public:
  explicit Init_Move3d_Request_y(::highlevel_interfaces::srv::Move3d_Request & msg)
  : msg_(msg)
  {}
  Init_Move3d_Request_z y(::highlevel_interfaces::srv::Move3d_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Move3d_Request_z(msg_);
  }

private:
  ::highlevel_interfaces::srv::Move3d_Request msg_;
};

class Init_Move3d_Request_x
{
public:
  Init_Move3d_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Move3d_Request_y x(::highlevel_interfaces::srv::Move3d_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Move3d_Request_y(msg_);
  }

private:
  ::highlevel_interfaces::srv::Move3d_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::highlevel_interfaces::srv::Move3d_Request>()
{
  return highlevel_interfaces::srv::builder::Init_Move3d_Request_x();
}

}  // namespace highlevel_interfaces


namespace highlevel_interfaces
{

namespace srv
{

namespace builder
{

class Init_Move3d_Response_success
{
public:
  Init_Move3d_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::highlevel_interfaces::srv::Move3d_Response success(::highlevel_interfaces::srv::Move3d_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::highlevel_interfaces::srv::Move3d_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::highlevel_interfaces::srv::Move3d_Response>()
{
  return highlevel_interfaces::srv::builder::Init_Move3d_Response_success();
}

}  // namespace highlevel_interfaces


namespace highlevel_interfaces
{

namespace srv
{

namespace builder
{

class Init_Move3d_Event_response
{
public:
  explicit Init_Move3d_Event_response(::highlevel_interfaces::srv::Move3d_Event & msg)
  : msg_(msg)
  {}
  ::highlevel_interfaces::srv::Move3d_Event response(::highlevel_interfaces::srv::Move3d_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::highlevel_interfaces::srv::Move3d_Event msg_;
};

class Init_Move3d_Event_request
{
public:
  explicit Init_Move3d_Event_request(::highlevel_interfaces::srv::Move3d_Event & msg)
  : msg_(msg)
  {}
  Init_Move3d_Event_response request(::highlevel_interfaces::srv::Move3d_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Move3d_Event_response(msg_);
  }

private:
  ::highlevel_interfaces::srv::Move3d_Event msg_;
};

class Init_Move3d_Event_info
{
public:
  Init_Move3d_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Move3d_Event_request info(::highlevel_interfaces::srv::Move3d_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Move3d_Event_request(msg_);
  }

private:
  ::highlevel_interfaces::srv::Move3d_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::highlevel_interfaces::srv::Move3d_Event>()
{
  return highlevel_interfaces::srv::builder::Init_Move3d_Event_info();
}

}  // namespace highlevel_interfaces

#endif  // HIGHLEVEL_INTERFACES__SRV__DETAIL__MOVE3D__BUILDER_HPP_
