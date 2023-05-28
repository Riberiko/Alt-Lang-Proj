
#include "Driver.h"

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
                cell.setLaunchAnnounced(0);
            }
        }
        case 3:
        {
            cell.setLaunchStatus((!isValid_notMissing(data[iter++])) ? "NULL" :data[iter-1].substr(0, data[iter-1].find('.')));
            cell.launch = 0;
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
                cell.setBodyWeight(0);
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
                cell.setDisplaySize(0);
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
    float num = 0, sum = 0;
    for(Cell item: cells) if(item.getBodyWeight() != 0)
        {
            sum += item.getBodyWeight();
            num++;
        }
    return sum/num;
}

std::vector<Cell> getAnnouncedNotEReleased(const std::vector<Cell> &cells)
{
    std::vector<Cell> result;
    for(Cell item : cells) if(item.launch != 0 && item.launch != item.getLaunchAnnounced()) result.push_back(item);
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
    std::vector<Cell> result;
    for (const auto &item: cells) if(item.launch >= lowerLimit && item.launch <= upperLimit) result.push_back(item);
    return result;
}

int getYearMostLaunched(const std::map<std::string, std::vector<Cell>> & phonesByOEM, int lower, int upper)
{
    std::map<int, int> yearCount;
    int most = 0, year = 0;

    for(const auto &pair : phonesByOEM)
    {
        for(const Cell &item : pair.second)
        {
            if(item.launch == 0 || item.launch < lower || item.launch >= upper) continue;
            if(yearCount.find(item.launch) == yearCount.end())
            {
                yearCount.insert(std::pair<int, int>(item.launch, 1));
            }else
            {
                yearCount.find(item.launch)->second = yearCount.find(item.launch)->second+1;
            }
        }
    }

    for (const auto &item: yearCount)
    {
        if(item.second > most)
        {
            most = item.second;
            year = item.first;
        }
    }

    return year;

}
