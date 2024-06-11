#ifndef YARN_H
#define YARN_H
#include <string>
#include <map>
#include <sstream>
#include <stdexcept>
#include <algorithm>

/* Program name: yarn.cpp
* Author: Carr O'Connor
* Date last updated: 6/9/2024
* Purpose: Build yarn objects
*/

class YarnSkein {
    public:
        enum fiberType {
            ACRYLIC,
            BAMBOO,
            COTTON,
            SILK,
            WOOL
        };

        enum weightType {
            BULKY,
            FINE,
            JUMBO,
            LACE,
            LIGHT,
            MEDIUM,
            SUPERBULKY,
            SUPERFINE
        };

        // helper function for removing leading and trailing whitespace from a string
        std::string trim(const std::string &str, const std::string &whitespace = " ");


	    YarnSkein(std::string strandWeight, std::string color, double length, std::string fiber, double skeinWeight, double needleSize, double hookSize); //constructor
	    YarnSkein(const YarnSkein &); //copy constructor
	    ~YarnSkein(); //destructor
	    YarnSkein& operator=(const YarnSkein &);
        static const std::map<fiberType, std::string> fiberToStr;
        static const std::map<std::string, fiberType> strToFiber;
        static const std::map<std::string, weightType> strToWeight;
        static const std::map<weightType, std::string> weightToStr;

        double getHookSize() const;
        double getLength() const;
        double getNeedleSize() const;
        double getSkeinWeight() const;
        int getStrandWeight() const;
        std::string getColor() const;
        std::string getFiberList() const;
        std::string getStrandWeightName() const;

        void setColor(std::string color);
        void setLength(double length);
    
    private:
        double hookSize;
        double length;
        double needleSize;
        double skeinWeight;
        fiberType fiber;
        int numFiberType;
        std::string color;
        weightType strandWeight;

        void copyYarn(const YarnSkein &);
        void setFiber(std::string fiber);
};

#endif