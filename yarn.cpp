#include "yarn.h"

// static maps
const std::map<YarnSkein::fiberType, std::string> YarnSkein::fiberToStr {
    {ACRYLIC, "Acrylic"},
    {BAMBOO, "Bamboo"},
    {COTTON, "Cotton"},
    {SILK, "Silk"},
    {WOOL, "Wool"}
};

const std::map<std::string, YarnSkein::fiberType> YarnSkein::strToFiber = {
    {"ACRYLIC", ACRYLIC},
    {"BAMBOO", BAMBOO},
    {"COTTON", COTTON},
    {"SILK", SILK},
    {"WOOL", WOOL}
};

const std::map<std::string, YarnSkein::weightType> YarnSkein::strToWeight = {
    {"BULKY", BULKY},
    {"FINE", FINE},
    {"JUMBO", JUMBO},
    {"LACE", LACE},
    {"LIGHT", LIGHT},
    {"MEDIUM", MEDIUM},
    {"SUPER BULKY", SUPERBULKY},
    {"SUPER FINE", SUPERFINE}
};

const std::map<YarnSkein::weightType, std::string> YarnSkein::weightToStr = {
    {BULKY, "Bulky"},
    {FINE, "Fine"},
    {JUMBO, "Jumbo"},
    {LACE, "Lace"},
    {LIGHT, "Light"},
    {MEDIUM, "Medium"},
    {SUPERBULKY, "Super Bulky"},
    {SUPERFINE, "Super Fine"}
};

// constructor
YarnSkein::YarnSkein(std::string strandWeight, std::string color, double length, std::string fiber, double skeinWeight, double needleSize, double hookSize) {
    this->strandWeight = strToWeight.at(strandWeight);
    this->color = color;
    this->length = length;
    this->fiber = strToFiber.at(trim(fiber, ","));
    this->skeinWeight = skeinWeight;
    this->needleSize = needleSize;
    this->hookSize = hookSize;
}

// copy constructor
YarnSkein::YarnSkein(const YarnSkein &ys) {
    this->strandWeight = ys.strandWeight;
    this->color = ys.color;
    this->length = ys.length;
    this->fiber = ys.fiber;
    this->skeinWeight = ys.skeinWeight;
    this->needleSize = ys.needleSize;
    this->hookSize = ys.hookSize;
}

// destructor
YarnSkein::~YarnSkein() {
 
}

// assignment operator
YarnSkein& YarnSkein::operator=(const YarnSkein &ys) {
    this->strandWeight = ys.strandWeight;
    this->color = ys.color;
    this->length = ys.length;
    this->fiber = ys.fiber;
    this->skeinWeight = ys.skeinWeight;
    this->needleSize = ys.needleSize;
    this->hookSize = ys.hookSize;

    return *this;
}

// getter functions
double YarnSkein::getHookSize() const {
    return this->hookSize;
}

double YarnSkein::getLength() const {
    return this->length;
}

double YarnSkein::getNeedleSize() const {
    return this->needleSize;
}

double YarnSkein::getSkeinWeight() const {
    return this->skeinWeight;
}

int YarnSkein::getStrandWeight() const {
    return this->strandWeight;
}

std::string YarnSkein::getFiberList() const {
    return fiberToStr.at(this->fiber);
}

std::string YarnSkein::getStrandWeightName() const {
    return weightToStr.at(this->strandWeight);
}

std::string YarnSkein::getColor() const {
    return this->color;
}

// setter functions

void YarnSkein::setColor(std::string color) {
    this->color = color;
}

void YarnSkein::setLength(double length) {
    this->length = length;
}

void YarnSkein::setFiber(std::string fiber) {
    this->fiber = strToFiber.at(fiber);
}

void YarnSkein::copyYarn(const YarnSkein &ys) {
    this->strandWeight = ys.strandWeight;
    this->color = ys.color;
    this->length = ys.length;
    this->fiber = ys.fiber;
    this->skeinWeight = ys.skeinWeight;
    this->needleSize = ys.needleSize;
    this->hookSize = ys.hookSize;
}

// trim helper function from https://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string to help remove whitespace from comma separated string
std::string YarnSkein::trim(const std::string &str,
                 const std::string &whitespace)
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}