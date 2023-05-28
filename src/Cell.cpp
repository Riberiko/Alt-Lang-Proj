
#include "Cell.h"

void Cell::setOem(std::string oem) {
    this->oem = oem;
}

std::string Cell::getOem() {
    return oem;
}

void Cell::setModel(std::string model) {
    this->model = model;
}

std::string Cell::getModel() {
    return model;
}

void Cell::setLaunchAnnounced(int launch_announced) {
    this->launch_announced = launch_announced;
}

int Cell::getLaunchAnnounced() {
    return launch_announced;
}

void Cell::setLaunchStatus(std::string launch_status) {
    this->launch_status = launch_status;
}

std::string Cell::getLaunchStatus() {
    return launch_status;
}

void Cell::setBodyDimensions(std::string body_dimensions) {
    this->body_dimensions = body_dimensions;
}

std::string Cell::getBodyDimensions() {
    return body_dimensions;
}

void Cell::setBodyWeight(float body_weight) {
    this->body_weight = body_weight;
}

float Cell::getBodyWeight() {
    return body_weight;
}

void Cell::setBodySim(std::string body_sim) {
    this->body_sim = body_sim;
}

std::string Cell::getBodySim() {
    return body_sim;
}

void Cell::setDisplayType(std::string display_type) {
    this->display_type = display_type;
}
std::string Cell::getDisplayType()
{
    return display_type;
}
void Cell::setDisplaySize(float display_size)
{
    this->display_size = display_size;
}
float Cell::getDisplaySize()
{
    return display_size;
}
void Cell::setDisplayResolution(std::string display_resolution)
{
    this->display_resolution = display_resolution;
}
std::string Cell::getDisplayResolution()
{
    return display_resolution;
}
void Cell::setFeaturesSensors(std::string features_sensors)
{
    this->features_sensors = features_sensors;
}
std::string Cell::getFeaturesSensors()
{
    return features_sensors;
}
void Cell::setPlatformOs(std::string platform_os)
{
    this->platform_os = platform_os;
}
std::string Cell::getPlatformOs()
{
    return platform_os;
}


std::string Cell::toString()
{
    std::string str;

    str += "Cell Phone -> {\n";
    str += "\tOEM : '" + getOem() + "',\n";
    str += "\tModel : '" + getModel() + "',\n";
    str += "\tLaunch Announced : " + std::to_string(getLaunchAnnounced()) + ",\n";
    str += "\tLaunch Year : " + ((launch != 0) ? std::to_string(launch) : "NULL") + ",\n";
    str += "\tLaunch Status : '" + getLaunchStatus() + "',\n";
    str += "\tBody Dimensions : '" + getBodyDimensions() + "',\n";
    str += "\tBody Weight : " + std::to_string(getBodyWeight()) + ",\n";
    str += "\tBody Sim : '" + getBodySim() + "',\n";
    str += "\tDisplay Type : '" + getDisplayType() + "'\n";
    str += "\tDisplay Size : " + std::to_string(getDisplaySize()) + ",\n";
    str += "\tDisplay Resolution : '" + getDisplayResolution() + "',\n";
    str += "\tFeatures Sensors : '" + getFeaturesSensors() + "',\n";
    str += "\tPlatform Os : '" + getPlatformOs() + "'\n}";
    return str;
}

bool Cell::isEqual(Cell & cell)
{
    return this->toString() == cell.toString();
}

std::ostream& operator<<(std::ostream& os, Cell & cell)
{
    os << cell.toString();
    return os;
}

std::ostream& operator<<(std::ostream& os, std::vector<Cell> & cells)
{
    for (auto &item: cells)
    {
        os << item.toString();
    }
    return os;
}
