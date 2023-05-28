
#include <string>
#include <vector>
#include <iostream>

#pragma once

using namespace std;
class Cell {
private:
    std::string oem;
    std::string model;
    int launch_announced;
    std::string launch_status;
    std::string body_dimensions;
    float body_weight;
    std::string body_sim;
    std::string display_type;
    float display_size;
    std::string display_resolution;
    std::string features_sensors;
    std::string platform_os;
public:

    int launch;

    void setOem(std::string oem);
    std::string getOem();
    void setModel(std::string model);
    std::string getModel();
    void setLaunchAnnounced(int launch_announced);
    int getLaunchAnnounced();
    void setLaunchStatus(std::string launch_status);
    std::string getLaunchStatus();
    void setBodyDimensions(std::string body_dimensions);
    std::string getBodyDimensions();
    void setBodyWeight(float body_weight);
    float getBodyWeight();
    void setBodySim(std::string body_sim);
    std::string getBodySim();
    void setDisplayType(std::string display_type);
    std::string getDisplayType();
    void setDisplaySize(float display_size);
    float getDisplaySize();
    void setDisplayResolution(std::string display_resolution);
    std::string getDisplayResolution();
    void setFeaturesSensors(std::string features_sensors);
    std::string getFeaturesSensors();
    void setPlatformOs(std::string platform_os);
    std::string getPlatformOs();


    std::string toString();
    bool isEqual(Cell & cell);
};

std::ostream& operator<<(std::ostream& os, Cell & cell);

std::ostream& operator<<(std::ostream& os, std::vector<Cell> & cells);