// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from highlevel_interfaces:action/PoseCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "highlevel_interfaces/action/pose_command.hpp"


#ifndef HIGHLEVEL_INTERFACES__ACTION__DETAIL__POSE_COMMAND__BUILDER_HPP_
#define HIGHLEVEL_INTERFACES__ACTION__DETAIL__POSE_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "highlevel_interfaces/action/detail/pose_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace highlevel_interfaces
{

namespace action
{

namespace builder
{

class Init_PoseCommand_Goal_yaw
{
public:
  explicit Init_PoseCommand_Goal_yaw(::highlevel_interfaces::action::PoseCommand_Goal & msg)
  : msg_(msg)
  {}
  ::highlevel_interfaces::action::PoseCommand_Goal yaw(::highlevel_interfaces::action::PoseCommand_Goal::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::highlevel_interfaces::action::PoseCommand_Goal msg_;
};

class Init_PoseCommand_Goal_pitch
{
public:
  explicit Init_PoseCommand_Goal_pitch(::highlevel_interfaces::action::PoseCommand_Goal & msg)
  : msg_(msg)
  {}
  Init_PoseCommand_Goal_yaw pitch(::highlevel_interfaces::action::PoseCommand_Goal::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_PoseCommand_Goal_yaw(msg_);
  }

private:
  ::highlevel_interfaces::action::PoseCommand_Goal msg_;
};

class Init_PoseCommand_Goal_roll
{
public:
  explicit Init_PoseCommand_Goal_roll(::highlevel_interfaces::action::PoseCommand_Goal & msg)
  : msg_(msg)
  {}
  Init_PoseCommand_Goal_pitch roll(::highlevel_interfaces::action::PoseCommand_Goal::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_PoseCommand_Goal_pitch(msg_);
  }

private:
  ::highlevel_interfaces::action::PoseCommand_Goal msg_;
};

class Init_PoseCommand_Goal_z
{
public:
  explicit Init_PoseCommand_Goal_z(::highlevel_interfaces::action::PoseCommand_Goal & msg)
  : msg_(msg)
  {}
  Init_PoseCommand_Goal_roll z(::highlevel_interfaces::action::PoseCommand_Goal::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_PoseCommand_Goal_roll(msg_);
  }

private:
  ::highlevel_interfaces::action::PoseCommand_Goal msg_;
};

class Init_PoseCommand_Goal_y
{
public:
  explicit Init_PoseCommand_Goal_y(::highlevel_interfaces::action::PoseCommand_Goal & msg)
  : msg_(msg)
  {}
  Init_PoseCommand_Goal_z y(::highlevel_interfaces::action::PoseCommand_Goal::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_PoseCommand_Goal_z(msg_);
  }

private:
  ::highlevel_interfaces::action::PoseCommand_Goal msg_;
};

class Init_PoseCommand_Goal_x
{
public:
  Init_PoseCommand_Goal_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseCommand_Goal_y x(::highlevel_interfaces::action::PoseCommand_Goal::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_PoseCommand_Goal_y(msg_);
  }

private:
  ::highlevel_interfaces::action::PoseCommand_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::highlevel_interfaces::action::PoseCommand_Goal>()
{
  return highlevel_interfaces::action::builder::Init_PoseCommand_Goal_x();
}

}  // namespace highlevel_interfaces


namespace highlevel_interfaces
{

namespace action
{

namespace builder
{

class Init_PoseCommand_Result_message
{
public:
  explicit Init_PoseCommand_Result_message(::highlevel_interfaces::action::PoseCommand_Result & msg)
  : msg_(msg)
  {}
  ::highlevel_interfaces::action::PoseCommand_Result message(::highlevel_interfaces::action::PoseCommand_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::highlevel_interfaces::action::PoseCommand_Result msg_;
};

class Init_PoseCommand_Result_success
{
public:
  Init_PoseCommand_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseCommand_Result_message success(::highlevel_interfaces::action::PoseCommand_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_PoseCommand_Result_message(msg_);
  }

private:
  ::highlevel_interfaces::action::PoseCommand_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::highlevel_interfaces::action::PoseCommand_Result>()
{
  return highlevel_interfaces::action::builder::Init_PoseCommand_Result_success();
}

}  // namespace highlevel_interfaces


namespace highlevel_interfaces
{

namespace action
{

namespace builder
{

class Init_PoseCommand_Feedback_time_elapsed
{
public:
  explicit Init_PoseCommand_Feedback_time_elapsed(::highlevel_interfaces::action::PoseCommand_Feedback & msg)
  : msg_(msg)
  {}
  ::highlevel_interfaces::action::PoseCommand_Feedback time_elapsed(::highlevel_interfaces::action::PoseCommand_Feedback::_time_elapsed_type arg)
  {
    msg_.time_elapsed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::highlevel_interfaces::action::PoseCommand_Feedback msg_;
};

class Init_PoseCommand_Feedback_distance_orientation
{
public:
  explicit Init_PoseCommand_Feedback_distance_orientation(::highlevel_interfaces::action::PoseCommand_Feedback & msg)
  : msg_(msg)
  {}
  Init_PoseCommand_Feedback_time_elapsed distance_orientation(::highlevel_interfaces::action::PoseCommand_Feedback::_distance_orientation_type arg)
  {
    msg_.distance_orientation = std::move(arg);
    return Init_PoseCommand_Feedback_time_elapsed(msg_);
  }

private:
  ::highlevel_interfaces::action::PoseCommand_Feedback msg_;
};

class Init_PoseCommand_Feedback_distance_translation
{
public:
  Init_PoseCommand_Feedback_distance_translation()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseCommand_Feedback_distance_orientation distance_translation(::highlevel_interfaces::action::PoseCommand_Feedback::_distance_translation_type arg)
  {
    msg_.distance_translation = std::move(arg);
    return Init_PoseCommand_Feedback_distance_orientation(msg_);
  }

private:
  ::highlevel_interfaces::action::PoseCommand_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::highlevel_interfaces::action::PoseCommand_Feedback>()
{
  return highlevel_interfaces::action::builder::Init_PoseCommand_Feedback_distance_translation();
}

}  // namespace highlevel_interfaces


namespace highlevel_interfaces
{

namespace action
{

namespace builder
{

class Init_PoseCommand_SendGoal_Request_goal
{
public:
  explicit Init_PoseCommand_SendGoal_Request_goal(::highlevel_interfaces::action::PoseCommand_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::highlevel_interfaces::action::PoseCommand_SendGoal_Request goal(::highlevel_interfaces::action::PoseCommand_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::highlevel_interfaces::action::PoseCommand_SendGoal_Request msg_;
};

class Init_PoseCommand_SendGoal_Request_goal_id
{
public:
  Init_PoseCommand_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseCommand_SendGoal_Request_goal goal_id(::highlevel_interfaces::action::PoseCommand_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_PoseCommand_SendGoal_Request_goal(msg_);
  }

private:
  ::highlevel_interfaces::action::PoseCommand_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::highlevel_interfaces::action::PoseCommand_SendGoal_Request>()
{
  return highlevel_interfaces::action::builder::Init_PoseCommand_SendGoal_Request_goal_id();
}

}  // namespace highlevel_interfaces


namespace highlevel_interfaces
{

namespace action
{

namespace builder
{

class Init_PoseCommand_SendGoal_Response_stamp
{
public:
  explicit Init_PoseCommand_SendGoal_Response_stamp(::highlevel_interfaces::action::PoseCommand_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::highlevel_interfaces::action::PoseCommand_SendGoal_Response stamp(::highlevel_interfaces::action::PoseCommand_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::highlevel_interfaces::action::PoseCommand_SendGoal_Response msg_;
};

class Init_PoseCommand_SendGoal_Response_accepted
{
public:
  Init_PoseCommand_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseCommand_SendGoal_Response_stamp accepted(::highlevel_interfaces::action::PoseCommand_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_PoseCommand_SendGoal_Response_stamp(msg_);
  }

private:
  ::highlevel_interfaces::action::PoseCommand_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::highlevel_interfaces::action::PoseCommand_SendGoal_Response>()
{
  return highlevel_interfaces::action::builder::Init_PoseCommand_SendGoal_Response_accepted();
}

}  // namespace highlevel_interfaces


namespace highlevel_interfaces
{

namespace action
{

namespace builder
{

class Init_PoseCommand_SendGoal_Event_response
{
public:
  explicit Init_PoseCommand_SendGoal_Event_response(::highlevel_interfaces::action::PoseCommand_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::highlevel_interfaces::action::PoseCommand_SendGoal_Event response(::highlevel_interfaces::action::PoseCommand_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::highlevel_interfaces::action::PoseCommand_SendGoal_Event msg_;
};

class Init_PoseCommand_SendGoal_Event_request
{
public:
  explicit Init_PoseCommand_SendGoal_Event_request(::highlevel_interfaces::action::PoseCommand_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_PoseCommand_SendGoal_Event_response request(::highlevel_interfaces::action::PoseCommand_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_PoseCommand_SendGoal_Event_response(msg_);
  }

private:
  ::highlevel_interfaces::action::PoseCommand_SendGoal_Event msg_;
};

class Init_PoseCommand_SendGoal_Event_info
{
public:
  Init_PoseCommand_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseCommand_SendGoal_Event_request info(::highlevel_interfaces::action::PoseCommand_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_PoseCommand_SendGoal_Event_request(msg_);
  }

private:
  ::highlevel_interfaces::action::PoseCommand_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::highlevel_interfaces::action::PoseCommand_SendGoal_Event>()
{
  return highlevel_interfaces::action::builder::Init_PoseCommand_SendGoal_Event_info();
}

}  // namespace highlevel_interfaces


namespace highlevel_interfaces
{

namespace action
{

namespace builder
{

class Init_PoseCommand_GetResult_Request_goal_id
{
public:
  Init_PoseCommand_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::highlevel_interfaces::action::PoseCommand_GetResult_Request goal_id(::highlevel_interfaces::action::PoseCommand_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::highlevel_interfaces::action::PoseCommand_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::highlevel_interfaces::action::PoseCommand_GetResult_Request>()
{
  return highlevel_interfaces::action::builder::Init_PoseCommand_GetResult_Request_goal_id();
}

}  // namespace highlevel_interfaces


namespace highlevel_interfaces
{

namespace action
{

namespace builder
{

class Init_PoseCommand_GetResult_Response_result
{
public:
  explicit Init_PoseCommand_GetResult_Response_result(::highlevel_interfaces::action::PoseCommand_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::highlevel_interfaces::action::PoseCommand_GetResult_Response result(::highlevel_interfaces::action::PoseCommand_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::highlevel_interfaces::action::PoseCommand_GetResult_Response msg_;
};

class Init_PoseCommand_GetResult_Response_status
{
public:
  Init_PoseCommand_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseCommand_GetResult_Response_result status(::highlevel_interfaces::action::PoseCommand_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_PoseCommand_GetResult_Response_result(msg_);
  }

private:
  ::highlevel_interfaces::action::PoseCommand_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::highlevel_interfaces::action::PoseCommand_GetResult_Response>()
{
  return highlevel_interfaces::action::builder::Init_PoseCommand_GetResult_Response_status();
}

}  // namespace highlevel_interfaces


namespace highlevel_interfaces
{

namespace action
{

namespace builder
{

class Init_PoseCommand_GetResult_Event_response
{
public:
  explicit Init_PoseCommand_GetResult_Event_response(::highlevel_interfaces::action::PoseCommand_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::highlevel_interfaces::action::PoseCommand_GetResult_Event response(::highlevel_interfaces::action::PoseCommand_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::highlevel_interfaces::action::PoseCommand_GetResult_Event msg_;
};

class Init_PoseCommand_GetResult_Event_request
{
public:
  explicit Init_PoseCommand_GetResult_Event_request(::highlevel_interfaces::action::PoseCommand_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_PoseCommand_GetResult_Event_response request(::highlevel_interfaces::action::PoseCommand_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_PoseCommand_GetResult_Event_response(msg_);
  }

private:
  ::highlevel_interfaces::action::PoseCommand_GetResult_Event msg_;
};

class Init_PoseCommand_GetResult_Event_info
{
public:
  Init_PoseCommand_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseCommand_GetResult_Event_request info(::highlevel_interfaces::action::PoseCommand_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_PoseCommand_GetResult_Event_request(msg_);
  }

private:
  ::highlevel_interfaces::action::PoseCommand_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::highlevel_interfaces::action::PoseCommand_GetResult_Event>()
{
  return highlevel_interfaces::action::builder::Init_PoseCommand_GetResult_Event_info();
}

}  // namespace highlevel_interfaces


namespace highlevel_interfaces
{

namespace action
{

namespace builder
{

class Init_PoseCommand_FeedbackMessage_feedback
{
public:
  explicit Init_PoseCommand_FeedbackMessage_feedback(::highlevel_interfaces::action::PoseCommand_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::highlevel_interfaces::action::PoseCommand_FeedbackMessage feedback(::highlevel_interfaces::action::PoseCommand_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::highlevel_interfaces::action::PoseCommand_FeedbackMessage msg_;
};

class Init_PoseCommand_FeedbackMessage_goal_id
{
public:
  Init_PoseCommand_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseCommand_FeedbackMessage_feedback goal_id(::highlevel_interfaces::action::PoseCommand_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_PoseCommand_FeedbackMessage_feedback(msg_);
  }

private:
  ::highlevel_interfaces::action::PoseCommand_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::highlevel_interfaces::action::PoseCommand_FeedbackMessage>()
{
  return highlevel_interfaces::action::builder::Init_PoseCommand_FeedbackMessage_goal_id();
}

}  // namespace highlevel_interfaces

#endif  // HIGHLEVEL_INTERFACES__ACTION__DETAIL__POSE_COMMAND__BUILDER_HPP_
