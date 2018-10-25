// Copyright 2014 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

//cd ~/ros2_overlay_ws
//colcon build
//ros2 pkg executables

#include <chrono>
#include <cstdio>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "rcutils/cmdline_parser.h"

#include "std_msgs/msg/string.hpp"

//keyEvent include
#include "SDL2/SDL.h"
#include <stdbool.h>

using namespace std::chrono_literals;

void print_usage()
{
  printf("Usage for talkerKeyin app:\n");
  printf("talkerKeyin [-t topic_name] [-h]\n");
  printf("options:\n");
  printf("-h : Print this help function.\n");
  printf("-t topic_name : Specify the topic on which to publish. Defaults to chatter.\n");
}

// Create a Talker class that subclasses the generic rclcpp::Node base class.
// The main function below will instantiate the class as a ROS node.
class TalkerKeyin : public rclcpp::Node
{
public:
  explicit TalkerKeyin(const std::string & topic_name)
  : Node("talkerKeyin")
  {
    msg_ = std::make_shared<std_msgs::msg::String>();

    /* // Create a function for when messages are to be sent.
    auto publish_message =
      [this]() -> void
      {
        msg_->data = "Hello World: " + std::to_string(count_++);
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", msg_->data.c_str())

        // Put the message into a queue to be processed by the middleware.
        // This call is non-blocking.
        pub_->publish(msg_);
      };
 */
    // Create a publisher with a custom Quality of Service profile.
    rmw_qos_profile_t custom_qos_profile = rmw_qos_profile_default;
    custom_qos_profile.depth = 7;
    pub_ = this->create_publisher<std_msgs::msg::String>(topic_name, custom_qos_profile);

    // Use a timer to schedule periodic message publishing.
    //timer_ = this->create_wall_timer(1s, publish_message);


    //*** start keyEvent
    if (SDL_Init(SDL_INIT_VIDEO) != 0) /* Prefer only events SDL_INIT_EVENTS */
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return ;
    }

    //SDL_Window* gWindow = 
    SDL_CreateWindow( "RSO2 Keyin Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 320, SDL_WINDOW_SHOWN ); 
/* I don't want this window! */

    /* While no quit */
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
            //User presses a key
            //ref https://www.libsdl.org/release/SDL-1.2.15/docs/html/sdlgetmodstate.html
            //ref https://www.libsdl.org/release/SDL-1.2.15/docs/html/sdlkey.html
            else if( e.type == SDL_KEYDOWN )
            {
              char modifiers[256];
              memset(modifiers,0,sizeof(modifiers));
              sprintf(modifiers,"%s","");
              if (e.key.keysym.mod  & KMOD_CAPS) {
                sprintf(modifiers,"%s %s",modifiers,"[CAPS]");
              }
              if (e.key.keysym.mod  & KMOD_RSHIFT) {
                sprintf(modifiers,"%s %s",modifiers,"[RSHIFT]");
              }
                  
                printf( "Key type: %d ,modifiers:%s\n", e.key.keysym.sym ,modifiers);
                memset(mymsg,0,sizeof(mymsg));
                //sprintf(mymsg,"Key type: %d", e.key.keysym.sym );
                
                //publicMessage(mymsg);
                //Select surfaces based on key press
                switch( e.key.keysym.sym )
                {
                    case SDLK_UP:
                    printf( "UP!\n" );
                    sprintf(mymsg,"Key type: %s", "UP!");
                    publicMessage(mymsg);
                    break;

                    case SDLK_DOWN:
                    printf( "DOWN!\n" );                   
                    sprintf(mymsg,"Key type: %s", "DOWN!");
                    publicMessage(mymsg);
                    break;

                    case SDLK_LEFT:
                    printf( "LEFT!\n" );
                    sprintf(mymsg,"Key type: %s", "LEFT!");
                    publicMessage(mymsg);
                    break;

                    case SDLK_RIGHT:
                    printf( "RIGHT!\n" );
                    sprintf(mymsg,"Key type: %s", "RIGHT!");
                    publicMessage(mymsg);
                    break;

                    default:
                    break;
                }
            }
        }
    }
    
    SDL_Quit();
    //***end keyEvent
  }

  void publicMessage(char* keyin_msg)
  {
      //msg_->data = "Hello World: " + std::to_string(count_++);
      msg_->data =keyin_msg;
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", msg_->data.c_str())

        // Put the message into a queue to be processed by the middleware.
        // This call is non-blocking.
        pub_->publish(msg_);
  }

private:
  size_t count_ = 1;
  std::shared_ptr<std_msgs::msg::String> msg_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
  char mymsg[256]; 
};

int main(int argc, char * argv[])
{
  // Force flush of the stdout buffer.
  // This ensures a correct sync of all prints
  // even when executed simultaneously within the launch file.
  setvbuf(stdout, NULL, _IONBF, BUFSIZ);

  if (rcutils_cli_option_exist(argv, argv + argc, "-h")) {
    print_usage();
    return 0;
  }

  // Initialize any global resources needed by the middleware and the client library.
  // You must call this before using any other part of the ROS system.
  // This should be called once per process.
  rclcpp::init(argc, argv);

  // Parse the command line options.
  auto topic = std::string("chatter");
  char * cli_option = rcutils_cli_get_option(argv, argv + argc, "-t");
  if (nullptr != cli_option) {
    topic = std::string(cli_option);
  }

  // Create a node.
  auto node = std::make_shared<TalkerKeyin>(topic);

  // spin will block until work comes in, execute work as it becomes available, and keep blocking.
  // It will only be interrupted by Ctrl-C.
  rclcpp::spin(node);

  rclcpp::shutdown();
  return 0;
}
