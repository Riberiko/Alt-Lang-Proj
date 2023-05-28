#include <iostream>
#include <cassert>
#include "../src/Driver.h"

using namespace std;

int main()
{
    string cellStr1 = "Benefon,Vega,1999,Discontinued,145 x 56 x 23 mm (5.71 x 2.20 x 0.91 in),190 g (6.70 oz),Mini-SIM,Monochrome graphic,,6 lines,V1,";
    Cell actualOne;
    actualOne.setOem("Benefon");
    actualOne.setModel("Vega");
    actualOne.setLaunchAnnounced(1999);
    actualOne.launch = 0;
    actualOne.setLaunchStatus("Discontinued");
    actualOne.setBodyDimensions("145 x 56 x 23 mm (5.71 x 2.20 x 0.91 in)");
    actualOne.setBodyWeight(190);
    actualOne.setBodySim("Mini-SIM");
    actualOne.setDisplayType("Monochrome graphic");
    actualOne.setDisplaySize(0);
    actualOne.setDisplayResolution("6 lines");
    actualOne.setFeaturesSensors("V1");
    actualOne.setPlatformOs("NULL");

    string cellStr2 = "Garmin-Asus,nuvifone M10,\"2010, January. Released 2010, March\",Discontinued,-,-,Mini-SIM,\"TFT resistive touchscreen, 65K colors\",\"3.5 inches, 34.9 cm\",\"480 x 800 pixels, 5:3 ratio (~267 ppi density)\",Accelerometer,Microsoft Windows Mobile 6.5.3 Professional";
    Cell actualTwo;
    actualTwo.setOem("Garmin-Asus");
    actualTwo.setModel("nuvifone M10");
    actualTwo.setLaunchAnnounced(2010);
    actualTwo.launch = 0;
    actualTwo.setLaunchStatus("Discontinued");
    actualTwo.setBodyDimensions("NULL");
    actualTwo.setBodyWeight(0);
    actualTwo.setBodySim("Mini-SIM");
    actualTwo.setDisplayType("TFT resistive touchscreen, 65K colors");
    actualTwo.setDisplaySize(3.5);
    actualTwo.setDisplayResolution("480 x 800 pixels, 5:3 ratio (~267 ppi density)");
    actualTwo.setFeaturesSensors("Accelerometer");
    actualTwo.setPlatformOs("Microsoft Windows Mobile 6.5.3 Professional");


    string cellStr3 = "Gigabyte,GSmart G1305 Boston,\"2010, April. Released 2010, April\",Discontinued,116 x 56.8 x 12.4 mm (4.57 x 2.24 x 0.49 in),118 g (4.16 oz),Mini-SIM,\"TFT capacitive touchscreen, 256K colors\",\"3.2 inches, 30.5 cm (~46.3% screen-to-body ratio)\",\"320 x 480 pixels, 3:2 ratio (~180 ppi density)\",Accelerometer,Android 1.6 (Donut)";
    Cell actualThree;
    actualThree.setOem("Gigabyte");
    actualThree.setModel("GSmart G1305 Boston");
    actualThree.setLaunchAnnounced(2010);
    actualThree.launch = 0;
    actualThree.setLaunchStatus("Discontinued");
    actualThree.setBodyDimensions("116 x 56.8 x 12.4 mm (4.57 x 2.24 x 0.49 in)");
    actualThree.setBodyWeight(118);
    actualThree.setBodySim("Mini-SIM");
    actualThree.setDisplayType("TFT capacitive touchscreen, 256K colors");
    actualThree.setDisplaySize(3.2);
    actualThree.setDisplayResolution("320 x 480 pixels, 3:2 ratio (~180 ppi density)");
    actualThree.setFeaturesSensors("Accelerometer");
    actualThree.setPlatformOs("Android 1.6 (Donut)");

    Cell one = parseCell(cellStr1);
    Cell two = parseCell(cellStr2);
    Cell three = parseCell(cellStr3);

    assert(actualOne.isEqual(one));
    printf("Cell Creation 1 Test Passed\n");
    assert(actualTwo.isEqual(two));
    printf("Cell Creation 2 Test Passed\n");
    assert(actualThree.isEqual(three));
    printf("Cell Creation 3 Test Passed\n");
    cout << "All Tests Passed";
    return 0;
}