# Install script for directory: /home/op/ros2_overlay_ws/src/demo_nodes1_cpp

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/op/ros2_overlay_ws/install/demo_nodes1_cpp")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/demo_nodes1_cpp/ros2snake" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/demo_nodes1_cpp/ros2snake")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/demo_nodes1_cpp/ros2snake"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/demo_nodes1_cpp" TYPE EXECUTABLE FILES "/home/op/ros2_overlay_ws/build/demo_nodes1_cpp/ros2snake")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/demo_nodes1_cpp/ros2snake" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/demo_nodes1_cpp/ros2snake")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/demo_nodes1_cpp/ros2snake"
         OLD_RPATH "/home/op/ros2_ws/install/example_interfaces/lib:/home/op/ros2_ws/install/rclcpp/lib:/home/op/ros2_ws/install/rcl/lib:/home/op/ros2_ws/install/rcl_interfaces/lib:/home/op/ros2_ws/install/rmw_fastrtps_cpp/lib:/home/op/ros2_ws/install/fastrtps/lib:/home/op/ros2_ws/install/fastcdr/lib:/home/op/ros2_ws/install/rmw/lib:/home/op/ros2_ws/install/rosgraph_msgs/lib:/home/op/ros2_ws/install/rcl_yaml_param_parser/lib:/home/op/ros2_ws/install/rcutils/lib:/home/op/ros2_ws/install/builtin_interfaces/lib:/home/op/ros2_ws/install/rosidl_typesupport_cpp/lib:/home/op/ros2_ws/install/rosidl_typesupport_c/lib:/home/op/ros2_ws/install/rosidl_typesupport_introspection_cpp/lib:/home/op/ros2_ws/install/rosidl_typesupport_introspection_c/lib:/home/op/ros2_ws/install/rosidl_generator_c/lib:/home/op/ros2_ws/install/std_msgs/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/demo_nodes1_cpp/ros2snake")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/demo_nodes1_cpp/talkerKeyin" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/demo_nodes1_cpp/talkerKeyin")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/demo_nodes1_cpp/talkerKeyin"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/demo_nodes1_cpp" TYPE EXECUTABLE FILES "/home/op/ros2_overlay_ws/build/demo_nodes1_cpp/talkerKeyin")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/demo_nodes1_cpp/talkerKeyin" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/demo_nodes1_cpp/talkerKeyin")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/demo_nodes1_cpp/talkerKeyin"
         OLD_RPATH "/home/op/ros2_ws/install/example_interfaces/lib:/home/op/ros2_ws/install/rclcpp/lib:/home/op/ros2_ws/install/rcl/lib:/home/op/ros2_ws/install/rcl_interfaces/lib:/home/op/ros2_ws/install/rmw_fastrtps_cpp/lib:/home/op/ros2_ws/install/fastrtps/lib:/home/op/ros2_ws/install/fastcdr/lib:/home/op/ros2_ws/install/rmw/lib:/home/op/ros2_ws/install/rosgraph_msgs/lib:/home/op/ros2_ws/install/rcl_yaml_param_parser/lib:/home/op/ros2_ws/install/rcutils/lib:/home/op/ros2_ws/install/builtin_interfaces/lib:/home/op/ros2_ws/install/rosidl_typesupport_cpp/lib:/home/op/ros2_ws/install/rosidl_typesupport_c/lib:/home/op/ros2_ws/install/rosidl_typesupport_introspection_cpp/lib:/home/op/ros2_ws/install/rosidl_typesupport_introspection_c/lib:/home/op/ros2_ws/install/rosidl_generator_c/lib:/home/op/ros2_ws/install/std_msgs/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/demo_nodes1_cpp/talkerKeyin")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/demo_nodes1_cpp/listener1" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/demo_nodes1_cpp/listener1")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/demo_nodes1_cpp/listener1"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/demo_nodes1_cpp" TYPE EXECUTABLE FILES "/home/op/ros2_overlay_ws/build/demo_nodes1_cpp/listener1")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/demo_nodes1_cpp/listener1" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/demo_nodes1_cpp/listener1")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/demo_nodes1_cpp/listener1"
         OLD_RPATH "/home/op/ros2_ws/install/example_interfaces/lib:/home/op/ros2_ws/install/rclcpp/lib:/home/op/ros2_ws/install/rcl/lib:/home/op/ros2_ws/install/rcl_interfaces/lib:/home/op/ros2_ws/install/rmw_fastrtps_cpp/lib:/home/op/ros2_ws/install/fastrtps/lib:/home/op/ros2_ws/install/fastcdr/lib:/home/op/ros2_ws/install/rmw/lib:/home/op/ros2_ws/install/rosgraph_msgs/lib:/home/op/ros2_ws/install/rcl_yaml_param_parser/lib:/home/op/ros2_ws/install/rcutils/lib:/home/op/ros2_ws/install/builtin_interfaces/lib:/home/op/ros2_ws/install/rosidl_typesupport_cpp/lib:/home/op/ros2_ws/install/rosidl_typesupport_c/lib:/home/op/ros2_ws/install/rosidl_typesupport_introspection_cpp/lib:/home/op/ros2_ws/install/rosidl_typesupport_introspection_c/lib:/home/op/ros2_ws/install/rosidl_generator_c/lib:/home/op/ros2_ws/install/std_msgs/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/demo_nodes1_cpp/listener1")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/demo_nodes1_cpp/" TYPE DIRECTORY FILES "/home/op/ros2_overlay_ws/src/demo_nodes1_cpp/launch")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/home/op/ros2_overlay_ws/build/demo_nodes1_cpp/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/demo_nodes1_cpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/home/op/ros2_overlay_ws/build/demo_nodes1_cpp/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/demo_nodes1_cpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/demo_nodes1_cpp/environment" TYPE FILE FILES "/home/op/ros2_ws/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/demo_nodes1_cpp/environment" TYPE FILE FILES "/home/op/ros2_ws/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/demo_nodes1_cpp" TYPE FILE FILES "/home/op/ros2_overlay_ws/build/demo_nodes1_cpp/ament_cmake_environment_hooks/local_setup.bash")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/demo_nodes1_cpp" TYPE FILE FILES "/home/op/ros2_overlay_ws/build/demo_nodes1_cpp/ament_cmake_environment_hooks/local_setup.sh")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/demo_nodes1_cpp" TYPE FILE FILES "/home/op/ros2_overlay_ws/build/demo_nodes1_cpp/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/home/op/ros2_overlay_ws/build/demo_nodes1_cpp/ament_cmake_index/share/ament_index/resource_index/packages/demo_nodes1_cpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/demo_nodes1_cpp/cmake" TYPE FILE FILES
    "/home/op/ros2_overlay_ws/build/demo_nodes1_cpp/ament_cmake_core/demo_nodes1_cppConfig.cmake"
    "/home/op/ros2_overlay_ws/build/demo_nodes1_cpp/ament_cmake_core/demo_nodes1_cppConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/demo_nodes1_cpp" TYPE FILE FILES "/home/op/ros2_overlay_ws/src/demo_nodes1_cpp/package.xml")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/op/ros2_overlay_ws/build/demo_nodes1_cpp/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
