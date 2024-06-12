#include "yarn.h"

// static maps
const std::map<YarnSkein::fiberType, std::string> YarnSkein::fiberToStr{
    {ACRYLIC, "Acrylic"},
    {BAMBOO, "Bamboo"},
    {COTTON, "Cotton"},
    {SILK, "Silk"},
    {WOOL, "Wool"}};

const std::map<std::string, YarnSkein::fiberType> YarnSkein::strToFiber = {
    {"ACRYLIC", ACRYLIC},
    {"BAMBOO", BAMBOO},
    {"COTTON", COTTON},
    {"SILK", SILK},
    {"WOOL", WOOL}};

const std::map<std::string, YarnSkein::weightType> YarnSkein::strToWeight = {
    {"BULKY", BULKY},
    {"FINE", FINE},
    {"JUMBO", JUMBO},
    {"LACE", LACE},
    {"LIGHT", LIGHT},
    {"MEDIUM", MEDIUM},
    {"SUPER BULKY", SUPERBULKY},
    {"SUPER FINE", SUPERFINE}};

const std::map<YarnSkein::weightType, std::string> YarnSkein::weightToStr = {
    {BULKY, "Bulky"},
    {FINE, "Fine"},
    {JUMBO, "Jumbo"},
    {LACE, "Lace"},
    {LIGHT, "Light"},
    {MEDIUM, "Medium"},
    {SUPERBULKY, "Super Bulky"},
    {SUPERFINE, "Super Fine"}};

// constructor
YarnSkein::YarnSkein(std::string _strandWeight, std::string _color, double _length, std::string _fiber, double _skeinWeight, double _needleSize, double _hookSize)
{
    std::transform(_strandWeight.begin(), _strandWeight.end(), _strandWeight.begin(), ::toupper); //transform to upper before attempting to set
    setStrandWeight(strToWeight.at(_strandWeight));
    setColor(_color);
    setLength(_length);
    setFiber(_fiber);
    setSkeinWeight(_skeinWeight);
    setNeedleSize(_needleSize);
    setHookSize(_hookSize);
}

// copy constructor
YarnSkein::YarnSkein(const YarnSkein &ys)
{
    setStrandWeight(ys.strandWeight);
    setColor(ys.color);
    setLength(ys.length);
    this->fiber = ys.fiber;
    setSkeinWeight(ys.skeinWeight);
    setNeedleSize(ys.needleSize);
    setHookSize(ys.hookSize);
}

// destructor
YarnSkein::~YarnSkein()
{
}

// assignment operator
YarnSkein &YarnSkein::operator=(const YarnSkein &ys)
{
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
double YarnSkein::getHookSize() const
{
    return this->hookSize;
}

double YarnSkein::getLength() const
{
    return this->length;
}

double YarnSkein::getNeedleSize() const
{
    return this->needleSize;
}

double YarnSkein::getSkeinWeight() const
{
    return this->skeinWeight;
}

int YarnSkein::getStrandWeight() const
{
    return this->strandWeight;
}

std::string YarnSkein::getFiberList() const
{
    std::stringstream ss;
    for(int i = 0; i < numFiberType; i++){
        ss << fiberToStr.at(fiber[i]);
        if(i != numFiberType -1){
            ss << ", ";
        }
    }
    return ss.str();
}

std::string YarnSkein::getStrandWeightName() const
{
    return weightToStr.at(this->strandWeight);
}

std::string YarnSkein::getColor() const
{
    return this->color;
}

// setter functions

void YarnSkein::setColor(std::string color)
{
    this->color = color;
}

void YarnSkein::setLength(double length)
{
    if(length < 0)
        throw std::invalid_argument("Invalid length: " + std::to_string(length));
        
    this->length = length;
}

void YarnSkein::setStrandWeight(weightType weight){
    if(weight < 0)
        throw std::invalid_argument("Invalid weight: " + std::to_string(weight));

    this->strandWeight = weight; 
}

void YarnSkein::setSkeinWeight(double weight){
    if(weight < 0)
        throw std::invalid_argument("Invalid weight: " + std::to_string(weight));

    this->skeinWeight = weight;    
}

void YarnSkein::setNeedleSize(double size){
    if(size < 0)
        throw std::invalid_argument("Invalid size: " + std::to_string(size));

    this->needleSize = size;    
}

void YarnSkein::setHookSize(double size){
    if(size < 0)
        throw std::invalid_argument("Invalid size: " + std::to_string(size));

    this->hookSize = size;
}

void YarnSkein::setFiber(std::string fiberStr)
{
    std::stringstream ss(fiberStr);

    while (ss.good()) {
        std::string substr;
        getline(ss, substr, ','); //get substring
        substr = trim(substr); //trim whitespace
        std::transform(substr.begin(), substr.end(), substr.begin(), ::toupper); //transform to upper
        auto it = strToFiber.find(substr); //check if valid fiber
        if(it != strToFiber.end())
            this->fiber.push_back(it->second); //add to vector
        else
            throw std::invalid_argument("Invalid fiber type: " + it->first);
    }
    
    numFiberType = this->fiber.size();
}

void YarnSkein::copyYarn(const YarnSkein &ys)
{
    setStrandWeight(ys.strandWeight);
    setColor(ys.color);
    setLength(ys.length);
    this->fiber = ys.fiber;
    setSkeinWeight(ys.skeinWeight);
    setNeedleSize(ys.needleSize);
    setHookSize(ys.hookSize);
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