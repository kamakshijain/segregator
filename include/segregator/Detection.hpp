
/**
 * @file Detection.hpp
 * Copyright [2019] [Kamakshi Jain] - driver
 * @date Nov 29, 2019
 * @brief This is the declaration of the Detection class
 */

#ifndef INCLUDE_SEGREGATOR_DETECTION_HPP_
#define INCLUDE_SEGREGATOR_DETECTION_HPP_

#include <ros/ros.h>
#include <iostream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

/*
 * @brief Detection is a class used for working with the camera in the world
 */
class Detection {
 private:
    //
    KukaKinematics & kuka;
    //
    bool dispImg = false;
    //
    ros::NodeHandle n;
    //
    cv_bridge::CvImagePtr cv_ptr;
    //
    image_transport::Subscriber imageSubscriber;
    //
    image_transport::ImageTransport imgT;
    //
    const std::string OPENCV_WINDOW = "Image Window";

 public:
    /*
     * @brief This is the constructor for the class
     */
    explicit Detection(KukaKinematics &, const bool &);

    /*
     * @brief This is the first method of the class. It gives the preloaded
     *        coordinates for a particular position index.
     *
     * @param This function takes the position index as input.
     *
     * @result This function returns the coordinates of the position index.
     */
    std::vector<double> getObjectCoords(const int);

    /*
     * @brief This is the second method of the class. It detects the position
     *        index of a particularly colored object.
     *
     * @param This function takes colour of the object as input.
     *
     * @result This function returns the position index for that object.
     */
    std::string colorThresholder(const KukaKinematics::States &);
    /*
     *
     *
    */
    void readImg(const sensor_msgs::ImageConstPtr&);


    /*
     * @brief This is the destructor for the class
     */
    ~Detection();
};

#endif  // INCLUDE_SEGREGATOR_DETECTION_HPP_
