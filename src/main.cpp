//
// Created by GMD on 5/25/2023.
//
#include "Driver.h"

int main()
{
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
        else phonesByOEM.insert(std::pair<std::string, std::vector<Cell>>(curr.getOem(), std::vector<Cell> {curr}));
    }

    std::string highAvgOem;
    double highAvgVal = 0;
    double temp;

    std::vector<Cell> announcedYearNotEqualReleaseYear;
    std::vector<Cell> oneFeature;
    std::vector<Cell> launchedBetween;

    for (const auto &pair: phonesByOEM)
    {
        temp = getAvgBodyWeight(pair.second);
        if(temp > highAvgVal)
        {
            highAvgOem = pair.first;
            highAvgVal = temp;
        }
        std::vector<Cell> AYNER = getAnnouncedNotEReleased(pair.second);
        std::vector<Cell> oneF = getPhoneWithNumFeatures(pair.second, 1);

        announcedYearNotEqualReleaseYear.insert(announcedYearNotEqualReleaseYear.end(), AYNER.begin(), AYNER.end());
        oneFeature.insert(oneFeature.end(), oneF.begin(), oneF.end());
    }

    std::cout << "OEM with Highest Average cell body weight" << std::endl;
    std::cout << highAvgOem << " : " << highAvgVal << "\n" << std::endl;

    std::cout << "Cells which were announced in one year but then released in another" << std::endl;
    std::cout << announcedYearNotEqualReleaseYear << std::endl;

    std::cout << "Phones that only have one feature with v1 as a place holder for a feature" << std::endl;
    std::cout << oneFeature.size() << std::endl;

    std::cout << "Year that had the most phones launched in the 2000s?" << std::endl;
    std::cout << getYearMostLaunched(phonesByOEM, 2000, 3000);

    return 0;
}
