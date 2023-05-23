#include <iostream>
#include <fstream>
#include <array>
#include <map>
#include <vector>

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

    void setOem(std::string oem) {
        this->oem = oem;
    }

    std::string getOem() {
        return oem;
    }

    void setModel(std::string model) {
        this->model = model;
    }

    std::string getModel() {
        return model;
    }

    void setLaunchAnnounced(int launch_announced) {
        this->launch_announced = launch_announced;
    }

    int getLaunchAnnounced() {
        return launch_announced;
    }

    void setLaunchStatus(std::string launch_status) {
        this->launch_status = launch_status;
    }

    std::string getLaunchStatus() {
        return launch_status;
    }

    void setBodyDimensions(std::string body_dimensions) {
        this->body_dimensions = body_dimensions;
    }

    std::string getBodyDimensions() {
        return body_dimensions;
    }

    void setBodyWeight(float body_weight) {
        this->body_weight = body_weight;
    }

    float getBodyWeight() {
        return body_weight;
    }

    void setBodySim(std::string body_sim) {
        this->body_sim = body_sim;
    }

    std::string getBodySim() {
        return body_sim;
    }

    void setDisplayType(std::string display_type) {
        this->display_type = display_type;
    }
    std::string getDisplayType()
    {
        return display_type;
    }
    void setDisplaySize(float display_size)
    {
        this->display_size = display_size;
    }
    float getDisplaySize()
    {
        return display_size;
    }
    void setDisplayResolution(std::string display_resolution)
    {
        this->display_resolution = display_resolution;
    }
    std::string getDisplayResolution()
    {
        return display_resolution;
    }
    void setFeaturesSensors(std::string features_sensors)
    {
        this->features_sensors = features_sensors;
    }
    std::string getFeaturesSensors()
    {
        return features_sensors;
    }
    void setPlatformOs(std::string platform_os)
    {
        this->platform_os = platform_os;
    }
    std::string getPlatformOs()
    {
        return platform_os;
    }


};

std::ostream& operator<<(std::ostream& os, Cell & cell)
{
    std::string str;

    str += "Cell Phone -> {\n";
    str += "\tOEM : '" + cell.getOem() + "',\n";
    str += "\tModel : '" + cell.getModel() + "',\n";
    str += "\tLaunch Announced : " + std::to_string(cell.getLaunchAnnounced()) + ",\n";
    str += "\tLaunch Year : " + ((cell.launch != NULL) ? std::to_string(cell.launch) : "NULL") + ",\n";
    str += "\tLaunch Status : '" + cell.getLaunchStatus() + "',\n";
    str += "\tBody Dimensions : '" + cell.getBodyDimensions() + "',\n";
    str += "\tBody Weight : " + std::to_string(cell.getBodyWeight()) + ",\n";
    str += "\tBody Sim : '" + cell.getBodySim() + "',\n";
    str += "\tDisplay Type : '" + cell.getDisplayType() + "'\n";
    str += "\tDisplay Size : " + std::to_string(cell.getDisplaySize()) + ",\n";
    str += "\tDisplay Resolution : '" + cell.getDisplayResolution() + "',\n";
    str += "\tFeatures Sensors : '" + cell.getFeaturesSensors() + "',\n";
    str += "\tPlatform Os : '" + cell.getPlatformOs() + "'\n}";

    os << str << std::endl;
    return os;
}

std::string trim(std::string & str)
{
    const char* typeOfWhitespaces = " \t\n\r\f\v";
    str.erase(str.find_last_not_of(typeOfWhitespaces) + 1);
    str.erase(0,str.find_first_not_of(typeOfWhitespaces));
    return str;
}

bool isValid_notMissing(const std::string & val)
{
    return !val.empty() && val != "-";
}

Cell cleanData(std::array<std::string, 12> & data)
{
    Cell cell;
    int iter = 0;

    switch (iter) {
        case 0: cell.setOem((!isValid_notMissing(data[iter++])) ? "NULL" : data[iter-1]);
        case 1: cell.setModel((!isValid_notMissing(data[iter++])) ? "NULL" : data[iter-1]);
        case 2:
        {
            try
            {
                cell.setLaunchAnnounced(std::stoi(data[iter++]));
            } catch (std::invalid_argument const &e)
            {
                cell.setLaunchAnnounced(NULL);
            }
        }
        case 3:
        {
            cell.setLaunchStatus((!isValid_notMissing(data[iter++])) ? "NULL" :data[iter-1].substr(0, data[iter-1].find('.')));
            cell.launch = NULL;
            if(data[iter-1].find("Released") != std::string::npos)
            {
                data[iter-1] = data[iter-1].substr(data[iter-1].find("Released")+9);
                try
                {
                    cell.launch = std::stoi(data[iter-1]);
                }catch (std::invalid_argument const &e){}
            }
        }
        case 4: cell.setBodyDimensions((!isValid_notMissing(data[iter++])) ? "NULL" : data[iter-1]);
        case 5:
        {
            try
            {
                cell.setBodyWeight(std::stof(data[iter++]));
            } catch (std::invalid_argument const &e)
            {
                cell.setBodyWeight(NULL);
            }
        }
        case 6: cell.setBodySim((!isValid_notMissing(data[iter++])) ? "NULL" :data[iter-1]);
        case 7: cell.setDisplayType((!isValid_notMissing(data[iter++])) ? "NULL" : data[iter-1]);
        case 8:
        {
            try
            {
                cell.setDisplaySize(std::stof(data[iter++]));
            }catch (std::invalid_argument const &e)
            {
                cell.setDisplaySize(NULL);
            }
        }
        case 9: cell.setDisplayResolution((!isValid_notMissing(data[iter++])) ? "NULL" : data[iter-1]);
        case 10: cell.setFeaturesSensors((!isValid_notMissing(data[iter++])) ? "NULL" : data[iter-1]);
        case 11: cell.setPlatformOs((!isValid_notMissing(data[iter])) ? "NULL" : data[iter].substr(0, data[iter].find(',')));
    }

    return cell;
}

Cell parseCell(std::string & line)
{
    std::array<std::string, 12> values;
    int next = 0;

    for(int i = 0; i < values.size(); i++)
    {
        trim(values[i]);

        if(line[0] == '"')
        {
            line = line.substr(1);
            next = line.find('"');
            values[i] = line.substr(0, next);
            line = line.substr(next+1);
            next = line.find(',');
            line = line.substr(next+1);
        }else
        {
            next = line.find(',');
            values[i] = line.substr(0, next);
            line = line.substr(next+1);
        }
    }
    return cleanData(values);
}

float getAvgBodyWeight(const std::vector<Cell> &cells)
{
    int num = 0, sum = 0;
    for(Cell item: cells) if(item.getBodyWeight() != NULL)
        {
            sum += item.getBodyWeight();
            num++;
        }
    return sum/num;
}

std::vector<Cell> getAnnouncedNotEReleased(const std::vector<Cell> &cells)
{
    std::vector<Cell> result;
    for(Cell item : cells) if(item.launch != NULL && item.launch != item.getLaunchAnnounced()) result.push_back(item);
    return result;
}

std::vector<Cell> getPhoneWithNumFeatures(const std::vector<Cell> &cells, int num)
{
    std::vector<Cell> result;
    std::string temp;

    for(Cell item: cells)
    {
        if(item.getFeaturesSensors() == "NULL") continue;
        temp = item.getFeaturesSensors();
        if(temp.empty() && num == 0)
        {
            result.push_back(item);
            continue;
        }
        int count = 1;
        for(char & c: temp)
        {
            if(count > num) continue;
            if(c == ',') count++;
        }
        if(count == num) result.push_back(item);
    }

    return result;
}

std::vector<Cell> getPhonesLaunchedSince(std::vector<Cell> &cells, int lowerLimit, int upperLimit)
{

}

int main() {
    std::ifstream file("../res/cells.csv");

    std::string str;
    std::map<std::string, std::vector<Cell>> phonesByOEM;
    Cell curr;

    if(!file.is_open())
    {
        std::cout << "Failed to open file " << "cells.csv" << std::endl;
        return 1;
    }

    std::getline(file, str);    //This will skip the header for the file

    while(!file.eof())
    {
        std::getline(file, str);
        curr = parseCell(str);
        if(phonesByOEM.find(curr.getOem()) != phonesByOEM.end()) phonesByOEM.find(curr.getOem())->second.push_back(curr);
        else phonesByOEM.insert(std::pair<std::string, std::vector<Cell>>(curr.getOem(), std::vector {curr}));
    }

    std::vector<Cell> announcedYearNotEqualReleaseYear;
    std::vector<Cell> oneFeature;

    for (const auto &item: phonesByOEM)
    {
        std::vector<Cell> AYNER = getAnnouncedNotEReleased(item.second);
        std::vector<Cell> oneF = getPhoneWithNumFeatures(item.second, 2);

        announcedYearNotEqualReleaseYear.insert(announcedYearNotEqualReleaseYear.end(), AYNER.begin(), AYNER.end());
        oneFeature.insert(oneFeature.end(), oneF.begin(), oneF.end());
    }

    for (auto &item: oneFeature)
    {
        std::cout << item;
    }

    return 0;
}
