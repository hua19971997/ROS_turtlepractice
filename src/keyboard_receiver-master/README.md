# keyboard_receiver
Receive key pressed in keyboard and publish to ROS topic. 
This implementation uses OpenCV `waitKey()` function to catch keyboard events. 
## Usage
```
rosrun keyboard_receiver keyboard_receiver_node
```
Click on the image window, then any key pressed will be published to topic. 

Note: you need to keep the image window active (by clicking on the window) to be able to receive the key input.

## Published topics
Topic: "key_pressed"

Type: "std_msgs/Int64"

The publised message is the ASCII code in decimal of the pressed key.
