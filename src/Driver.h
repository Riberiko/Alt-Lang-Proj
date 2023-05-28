//
// Created by GMD on 5/24/2023.
//

#include <iostream>
#include <fstream>
#include <array>
#include <map>
#include <vector>
#include "Cell.h"

#pragma once
std::string trim(std::string & str);

bool isValid_notMissing(const std::string & val);

Cell cleanData(std::array<std::string, 12> & data);

Cell parseCell(std::string & line);

float getAvgBodyWeight(const std::vector<Cell> &cells);

std::vector<Cell> getAnnouncedNotEReleased(const std::vector<Cell> &cells);

std::vector<Cell> getPhoneWithNumFeatures(const std::vector<Cell> &cells, int num);

std::vector<Cell> getPhonesLaunchedSince(std::vector<Cell> &cells, int lowerLimit, int upperLimit);

int getYearMostLaunched(const std::map<std::string, std::vector<Cell>> & phonesByOEM, int lower, int upper);
