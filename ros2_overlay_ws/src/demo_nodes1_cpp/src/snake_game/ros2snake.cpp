//ubuntu 16.04 make error must run "sudo apt-get install libncurses5-dev"
//setup ros2
//cd ~/ros2_overlay_ws
//colcon build 
//ros2 run demo_nodes1_cpp talkerKeyin
//ros2 run demo_nodes1_cpp ros2snake


#include <cstdio>
#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "rcutils/cmdline_parser.h"
#include "std_msgs/msg/string.hpp"

int ros2dir;

#include <ncurses.h>
#include <cstdlib>
#include <unistd.h>								//So that we can use usleep() which introduces delay
#include <string.h>								//In order to use strlen()

#include "snake.h"								//Header file containing the Class Snake which is the overall representation of snake
#include "unit.h"								//Header file containing the Class Unit which is representation of individual units of snake
#include "Stack.h"								//Stack used for storing Class Unit in class Snake
#include "collision.h"							//Function to check if collision has happened
#include "Score.h"								//Function to keep track of score and prints score
#include "food.h"								//Function to check if food is consumed and to generate food
#include "level.h"								//Function to draw the level, i.e. the gaming arena.

#define HEIGHT 30
#define WIDTH 80
#define DELAY_VER 60000*5
#define DELAY_HOR 47000*5

extern int delay_ver;								//Variable used to control speed of game
extern int delay_hor;
int delay_ver = DELAY_VER;
int delay_hor = DELAY_HOR;

// Create a Listener class that subclasses the generic rclcpp::Node base class.
// The main function below will instantiate the class as a ROS node.
class Listener1 : public rclcpp::Node
{
public:
  explicit Listener1(const std::string & topic_name)
  : Node("listener456")
  {
    // Create a callback function for when messages are received.
    // Variations of this function also exist using, for example UniquePtr for zero-copy transport.
    auto callback =
      [this](const std_msgs::msg::String::SharedPtr msg) -> void
      {
		
        //RCLCPP_INFO(this->get_logger(), "RCLCPP_INFO: [%s]", msg->data.c_str())
		if(strstr( msg->data.c_str(),"LEFT")!=NULL)
		{
			ros2dir=-1;
			//printf("I heard: [%s] [%d]\n", msg->data.c_str(),ros2dir);
		}
		else if(strstr( msg->data.c_str(),"RIGHT")!=NULL)
		{
			ros2dir=1;
			//printf("I heard: [%s] [%d]\n", msg->data.c_str(),ros2dir);
		}
      };

    // Create a subscription to the topic which can be matched with one or more compatible ROS
    // publishers.
    // Note that not all publishers on the same topic with the same type will be compatible:
    // they must have compatible Quality of Service policies.
    sub_ = create_subscription<std_msgs::msg::String>(topic_name, callback);
  }

private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;
};

int main(int argc, char * argv[]){
	ros2dir=0;
	// Initialize any global resources needed by the middleware and the client library.
  // You must call this before using any other part of the ROS system.
  // This should be called once per process.
  rclcpp::init(argc, argv);

  // Parse the command line options.
  auto topic = std::string("chatter");

  // Create a node.
  auto node = std::make_shared<Listener1>(topic);

	int ch;										//container for keys pressed
	Stack* snake_head;
	std::pair<int,int> coor_food;				//coorinates of the food for snake
	initscr();
	noecho();
	cbreak();
	start_color();
	draw_level(stdscr);
	keypad(stdscr,TRUE);
	curs_set(0);

	//Color pair initialization
	init_pair(1,COLOR_RED,COLOR_BLACK);
	init_pair(2,COLOR_RED,COLOR_YELLOW);
	init_pair(3,COLOR_CYAN,COLOR_CYAN);
	init_pair(4,COLOR_CYAN,COLOR_BLACK);
	init_pair(5,COLOR_GREEN,COLOR_BLACK);
	init_pair(6,COLOR_YELLOW,COLOR_BLACK);

	//Loop for restarting of game after game over.

	while(1){
		Score score;
		clear();
		draw_level(stdscr);						//Draws Border and Other Information like name etc.
		
		// To confirm starting of game and erase the "Press any key to continue" line.
		ch = getch();
		mvwprintw(stdscr,LINES/2,(COLS-strlen("                         "))/2,"                         ");
		
		nodelay(stdscr,TRUE);					//sets calls as non-blocking
		
		Snake snake(COLS/2,LINES/2);			//creates inital snake at center
		snake.grow(5);							//creates body of 5 'x' of snake
		food_gen(stdscr,&snake,coor_food);		//generates the coordinates for food and prints them on window
		snake.update(stdscr);					//draws the snake on screen
		refresh();								//refresh the screen to display all the changes
		//printf("start rclcpp::spin_some(node)\n");
		//rclcpp::spin_some(node);
		//printf("end rclcpp::spin_some(node)\n");
		while((ch = getch()) != 27){			//Game will run until ESC is pressed.
			rclcpp::spin_some(node);
			if(ros2dir !=0)//ros2 topic control
			{
				snake.update_dir(ros2dir);
				ros2dir=0;
			}
			else if(ch != ERR){						//If a key is pressed by user
				switch(ch){
					//changes the direction of head accordingly. NOTE: update_dir() is responsible for managing the directions of all snake units.
					case KEY_LEFT:
						snake.update_dir(-1);
						break;
					case KEY_RIGHT:
						snake.update_dir(1);
						break;
					default:
						snake.update_dir(0);
						break;
				}
			} 
			else{snake.update_dir(0);} //Update the 

			food_check(stdscr,&snake,coor_food,&score); //checks if snake has consumed food or not and if yes then draws another food and speeds up the game
			
			snake.update(stdscr); 						// draws updated snake on the screen and also updates the coordinates of snake according to motion of direction.
			
			if(collision_check(stdscr,&snake)){break;}	//Exits the game if snake collides with itself or the Wall
			
			score.print(stdscr);	//Prints the current score on the screen
			refresh();				//Refreshes the screen to display the changes
			snake_head = snake.head();

			//Introduces a delay so as to control the speed at which the game proceeds
			if(snake_head->elem.gcurrent_dir() % 2 == 1){usleep(delay_ver);}
			else{usleep(delay_hor);}			

		}

		//When Game gets over, these modify the screen accordingly 
		snake.kill();						//Deallocates the space occupied by current snake 
		delay_ver = DELAY_VER;						//resets the delay
		delay_hor = DELAY_HOR;
		clear();
		attron(COLOR_PAIR(6)|A_UNDERLINE|A_BOLD);
		mvwprintw(stdscr,LINES/2,(COLS-strlen("Your Score -   "))/2,"Your Score - %d",score.get_score());
		attroff(COLOR_PAIR(6)|A_UNDERLINE|A_BOLD);
		attron(COLOR_PAIR(1)|A_BOLD|A_UNDERLINE);
		mvwprintw(stdscr,LINES/2-3,(COLS-strlen("GAME OVER!"))/2,"GAME OVER!");
		attroff(COLOR_PAIR(1)|A_BOLD|A_UNDERLINE);
		refresh();
		usleep(1000000);
		attron(COLOR_PAIR(6));
		mvwprintw(stdscr,LINES/2+2,(COLS-strlen("Do you want to play again? (y/n)"))/2,"Do you want to play again? (y/n)");
		attroff(COLOR_PAIR(6));
		refresh();
		nodelay(stdscr,FALSE);
		while(ch != 'y'&& ch != 'n'){ch = getch();}
		if(ch == 'n'){break;}
	}

	//When User Doesn't want to restart, this modifies the screen accordingly
	attron(COLOR_PAIR(4));
	mvwprintw(stdscr,LINES/2+4,(COLS-strlen("Thank You for playing"))/2,"Thank You for playing");
	attroff(COLOR_PAIR(4));
	refresh();
	usleep(1000000);
	endwin();

	printf("topic:[%s]start rclcpp::shutdown()\n",topic.c_str());
  rclcpp::shutdown();
  printf("end rclcpp::shutdown()\n");

	return 0;
}
