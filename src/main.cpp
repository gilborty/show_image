#include <exception>
#include <iostream>
#include <string>
#include <vector>

// OpenCV Includes
#include <opencv2/highgui/highgui.hpp>

namespace
{
    const std::string main_window = "Main window";

    // Application flags and vars
    bool program_is_running = true;

    //Frames
    cv::Mat raw_frame;


    //Helper functions
    void print_opencv_version()
    {
        std::cout << "OpenCV version : " << CV_VERSION << std::endl;
        std::cout << "Major version : " << CV_MAJOR_VERSION << std::endl;
        std::cout << "Minor version : " << CV_MINOR_VERSION << std::endl;
        std::cout << "Subminor version : " << CV_SUBMINOR_VERSION << std::endl;
        std::cout << std::endl;
    } 

    
    void handle_wait_key(char key)
    {
        switch(key)
        {
            case(27):
            {
                //ESC key
                program_is_running = false;
                break;
            }
            case(32):
            {
                //Space bar
                break;
            }
            case('q'):
            {
                program_is_running = false;
                break;
            }
            case('Q'):
            {
                program_is_running = false;
                break;
            }
            default:
            {
                break;
            }
        }
    }
    
} //namespace


int main(int argc, const char* argv[])
{
    print_opencv_version();

    //Set up a video capture object
    //Default to /dev/video0
    auto capture = cv::VideoCapture(0);
    if(!capture.isOpened())
    {
        throw std::runtime_error("Could not open capture device");
    }

    //Setup a viewing window
    cv::namedWindow(main_window, cv::WINDOW_NORMAL);
    
    while(program_is_running)
    {
        //Get a frame from the camera
        capture >> raw_frame;
        if(raw_frame.empty())
        {
            throw std::runtime_error("Could not get frame from camera!");
        }

        //Display
        cv::imshow(main_window, raw_frame);

        //Loop 
        handle_wait_key(static_cast<char>(cv::waitKey(1)));   
    }
    
    return 0;
}
